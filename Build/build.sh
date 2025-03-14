#!/bin/bash

# 导出数据目录(当前目录)
DERIVED_DATA_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# 获取工程文件目录
PROJECT_PATH="$( cd "$( dirname "$PWD" )" && pwd )"

# 项目名字
LIBRARY_NAME="MeetingKit"

# 项目Podspec名字
PODSPEC_NAME="${LIBRARY_NAME}.podspec"

# podspec文件路径
PODSPEC_PATH=${PROJECT_PATH}/${PODSPEC_NAME}

# 获取组件仓库提交的标签版本号列表
CLOUDS_VERSION_ARRAY=$(git tag)

# 获取组件仓库的当前分支
BRANCH_NAME=$(git symbolic-ref --short -q HEAD)

# 组件发布日志文件
ISSUE_LOG_FILE="${DERIVED_DATA_PATH}/issue_log.txt"

# 上传日志
COMMIT_LOG=""

# 获取podspec文件中的版本号
OID_VERSION=""

# 逐行匹配获取文件中的版本号
while read line
do
    if [[ $line == s.version* ]]; then
    	# 匹配单引号或者双引号
		RE="\'([^\']*)\'"
		RE_DOUBLE="\"([^\"]*)\""
		if [[ $line =~ $RE || $line =~ $RE_DOUBLE ]]; then
			OID_VERSION=${BASH_REMATCH[1]}
		fi
    	break
    fi
done < $PODSPEC_PATH

# 检测要发布的版本号是否已经存在
if [[ "${CLOUDS_VERSION_ARRAY[@]}" =~ "${OID_VERSION}" ]]; then
	echo "要发布的版本号已经存在，请修改组件发布版本(${PODSPEC_NAME})"
	exit 1
fi

# 获取上传日志
echo "请输入上传日志内容："
# 读取用户输入上传日志
read log
while [[ -z "$log" ]]; do
	echo "出错了！上传日志内容不能为空。"
	echo "请输入上传日志内容："
	read log
done
COMMIT_LOG="发布SDK${OID_VERSION}-${log}"
echo "输入的提交日志是：${COMMIT_LOG}"

# 记录开始发布时间
START_DATE=$(date "+%s")

# 所有修改的文件全量提交
git add .
echo "#################### 正在提交 ####################"
git commit -a -m "${COMMIT_LOG}"
echo "#################### 正在Push ####################"
git tag -a ${OID_VERSION} -m "${OID_VERSION}"
git push --tags
git pull origin "$BRANCH_NAME"
git push origin "$BRANCH_NAME"
echo "#################### Push完成 ####################"

# 发布组件版本
echo "#################### 正在发布 ####################"
pod trunk push ${PODSPEC_PATH} --skip-import-validation --allow-warnings --use-libraries --verbose | tee ${ISSUE_LOG_FILE}

COUNT=0
TOTAL_COUNT=2

while read LOG_LINE
do
	if [[ ${LOG_LINE} =~ "Push for \`${LIBRARY_NAME} ${OID_VERSION}' has been pushed" ]]; then
		COUNT=`expr ${COUNT} + 1`
	fi
done < $ISSUE_LOG_FILE

# 记录结束发布时间
END_DATE=$(date "+%s")
# 发布持续时间(秒级)
DURATION_SECOND_TIME=$((END_DATE-START_DATE))
# 小时
HOUR_TIME=$(( $DURATION_SECOND_TIME/3600 ))
# 分钟
MINUTE_TIME=$(( ($DURATION_SECOND_TIME-${HOUR_TIME}*3600)/60 ))
# 秒数
SECOND_TIME=$(( $DURATION_SECOND_TIME-${HOUR_TIME}*3600-${MINUTE_TIME}*60 ))
# 发布持续时间(时:分:秒)
DURATION_TIME="${HOUR_TIME}小时 ${MINUTE_TIME}分钟 ${SECOND_TIME}秒"

# 判断发布是否成功
if [[ ${COUNT} == ${TOTAL_COUNT} ]]; then
	echo "#################### 发布成功 ####################"
    # 移除日志文件
    rm $ISSUE_LOG_FILE
else
	echo "#################### 发布失败 ####################"
fi

echo "#################### 发布用时：${DURATION_TIME} ####################"

