#!/bin/bash

# 导出数据目录(当前目录)
DERIVED_DATA_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# 获取工程文件目录(基于脚本自身位置推算，不依赖调用时的 PWD)
PROJECT_PATH="$( cd "$( dirname "$DERIVED_DATA_PATH" )" && pwd )"

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
    if [[ $line =~ s\.version[[:space:]]*= ]]; then
    	# 匹配单引号或者双引号
		RE="\'([^\']*)\'"
		RE_DOUBLE="\"([^\"]*)\""
		if [[ $line =~ $RE || $line =~ $RE_DOUBLE ]]; then
			OID_VERSION=${BASH_REMATCH[1]}
		fi
    	break
    fi
done < $PODSPEC_PATH

# 校验版本号解析成功(为空则中止，避免空版本号污染 commit 与 tag)
if [[ -z "${OID_VERSION}" ]]; then
	echo "未能从 ${PODSPEC_NAME} 解析出版本号，发布中止"
	exit 1
fi

# 检测要发布的版本号是否已经存在
if [[ "${CLOUDS_VERSION_ARRAY[@]}" =~ "${OID_VERSION}" ]]; then
	echo "要发布的版本号已经存在，请修改组件发布版本(${PODSPEC_NAME})"
	exit 1
fi

# 获取上传日志
# 优先使用环境变量 RELEASE_LOG（供一键发布脚本传入），否则交互式输入
if [[ -n "${RELEASE_LOG:-}" ]]; then
	log="${RELEASE_LOG}"
	echo "使用传入的上传日志内容：${log}"
else
	echo "请输入上传日志内容："
	# 读取用户输入上传日志
	read log
	while [[ -z "$log" ]]; do
		echo "出错了！上传日志内容不能为空。"
		echo "请输入上传日志内容："
		read log
	done
fi
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
# 先同步远端，避免分支非快进被拒
if ! git pull --no-edit origin "$BRANCH_NAME"; then
	echo "#################### 同步远端分支 ${BRANCH_NAME} 失败，发布中止 ####################"
	exit 1
fi
# 先推分支再推 tag，且逐个校验退出码：
# 避免出现"tag 已推送但分支版本号未更新"的不一致(历史上曾因静默失败导致 master 停留在旧版本)
if ! git push origin "$BRANCH_NAME"; then
	echo "#################### 分支 ${BRANCH_NAME} 推送失败，发布中止 ####################"
	exit 1
fi
if ! git push origin "$OID_VERSION"; then
	echo "#################### tag ${OID_VERSION} 推送失败，发布中止 ####################"
	exit 1
fi
echo "#################### Push完成 ####################"

# 发布组件版本
echo "#################### 正在发布 ####################"
# 仅更新 trunk(CDN)源索引，确保能解析到最近发布的依赖组件(如 RTCEngineKit 新版本)
# 注：只更新 trunk，避免克隆庞大的 cocoapods master 索引仓库
echo "#################### 更新 Spec 索引 ####################"
pod repo update trunk
pod trunk push ${PODSPEC_PATH} --skip-import-validation --allow-warnings --use-libraries --synchronous --verbose | tee ${ISSUE_LOG_FILE}
# 以 pod trunk push 的退出码判定成功(注意取管道首段退出码)
PUSH_RESULT=${PIPESTATUS[0]}

# trunk 服务端偶发返回 500(或网络抖动)但实际已发布成功的已知问题：
# push 失败时二次校验 trunk 是否已存在该版本，存在即视为发布成功，避免误报失败
if [[ ${PUSH_RESULT} -ne 0 ]]; then
	echo "#################### push 返回失败，二次校验 trunk 是否已发布 ${LIBRARY_NAME} ${OID_VERSION} ####################"
	# 版本号中的点转义后按行首"- 版本号 ("精确匹配 pod trunk info 输出
	VERSION_RE="${OID_VERSION//./\\.}"
	if pod trunk info "${LIBRARY_NAME}" 2>/dev/null | grep -qE "^[[:space:]]*-[[:space:]]*${VERSION_RE}[[:space:]]*\("; then
		echo "#################### trunk 已存在 ${LIBRARY_NAME} ${OID_VERSION}，判定为发布成功 ####################"
		PUSH_RESULT=0
	fi
fi

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

# 判断发布是否成功(依据 pod trunk push 退出码)
if [[ ${PUSH_RESULT} -eq 0 ]]; then
	echo "#################### 发布成功 ####################"
    # 移除日志文件
    rm -f $ISSUE_LOG_FILE
else
	echo "#################### 发布失败 ####################"
	echo "#################### 发布用时：${DURATION_TIME} ####################"
	# 以非零退出，让上层发布脚本感知失败并中止(不再误报成功)
	exit 1
fi

echo "#################### 发布用时：${DURATION_TIME} ####################"

