//
//  MeetingKitObjects.h
//  MeetingKit
//
//  Created by SailorGa on 2024/2/20.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RTCEngineKit/RTCEngineKit.h>

#if __has_include(<MeetingKit/MeetingKit.h>)
#import <MeetingKit/MeetingKitDefine.h>
#else
#import "MeetingKitDefine.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class SEALayoutViewListCellModel;
@class SEALayoutWatermarkModel;
@class SEALayoutViewListModel;
@class SEALayoutLabelModel;
@class SEALayoutDataModel;
@class SEAUserExtend;
@class SEARoomExtend;
@class SEASignInActivityModel;
@class MeetingKitRoom;

/// 日志配置
@interface SEALogConfig : NSObject

/// 是否启用全进程本地日志采集，默认 YES
@property (nonatomic, assign) BOOL enableLocalLog;

@end


/// 用户数据
@interface SEAUserModel : RTCEngineUserModel

/// 成员所属会议房间，用于解析房间内的共享状态
@property (nonatomic, strong, nullable) MeetingKitRoom *meetingRoom;
/// 麦克风状态
@property (nonatomic, assign) SEADeviceState micState;
/// 摄像头状态
@property (nonatomic, assign) SEADeviceState cameraState;
/// 共享类型
@property (nonatomic, assign) SEAShareType shareType;
/// 扩展属性
@property (nonatomic, strong) SEAUserExtend *extend;

@end


/// 房间数据
@interface SEARoomModel : RTCEngineChannelModel

/// 扩展属性
@property (nonatomic, strong) SEARoomExtend *extend;

@end


/// 用户数据扩展属性
@interface SEAUserExtend : NSObject

/// 参会角色
@property (nonatomic, assign) SEAUserRole role;
/// 参会头像
@property (nonatomic, copy) NSString *avatar;
/// 是否被踢出
@property (nonatomic, assign) BOOL isKickout;
/// 聊天能力禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL chatDisabled;
/// 涂鸦能力禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL drawDisabled;

/// 扩展信息
@property (nonatomic, copy, nullable) NSString *extendInfo;

@end


/// 房间数据扩展属性
@interface SEARoomExtend : NSObject

/// 会议标识(频道名称)
@property (nonatomic, copy) NSString *meetingId;
/// 房间号码
@property (nonatomic, copy) NSString *roomNo;
/// 会议标题
@property (nonatomic, copy) NSString *title;
/// 会议说明
@property (nonatomic, copy) NSString *content;
/// 会议类型
@property (nonatomic, assign) SEAMeetingType meetingType;
/// 会议模式
@property (nonatomic, assign) SEAMeetingMode meetingMode;
/// 预约时间(计划开始时间)，单位：秒
@property (nonatomic, assign) NSInteger planTime;
/// 预约时长(计划会议时长)，单位：分钟
@property (nonatomic, assign) NSInteger planDuration;
/// 入会静音状态
@property (nonatomic, assign) SEAMeetingMuteState entryMutePolicy;
/// 房间水印禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL watermarkDisabled;
/// 房间截屏禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL screenshotDisabled;
/// 聊天能力禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL chatDisabled;
/// 麦克风禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL micDisabled;
/// 摄像头禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL cameraDisabled;
/// 是否禁止自我解除音频状态，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL selfUnmuteMicDisabled;
/// 是否禁止自我解除视频状态，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL selfUnmuteCameraDisabled;
/// 房间共享禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL shareDisabled;
/// 等候室禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL waitingRoomDisabled;
/// 上级会议标识
@property (nonatomic, copy, nullable) NSString *parentMid;
/// 是否禁止在主持人之前入会，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL enterBeforeHostDisabled;
/// 锁定状态，YES-开启 NO-关闭
@property (nonatomic, assign) BOOL locked;

/// 共享类型
@property (nonatomic, assign) SEAShareType shareType;
/// 共享者标识
@property (nonatomic, copy, nullable) NSString *shareUid;
/// 创建者标识
@property (nonatomic, copy) NSString *creator;
/// 主持人标识
@property (nonatomic, copy) NSString *hostUid;
/// 联席主持标识列表
@property (nonatomic, copy, nullable) NSArray <NSString *> *unionHosts;
/// 云录制状态
@property (nonatomic, assign) SEARecordStatus recordStatus;

/// 房间是否存在进行中的签到活动
@property (nonatomic, assign) BOOL hasSignInActivity;
/// 房间签到活动列表
@property (nonatomic, copy, nullable) NSArray <SEASignInActivityModel *> *signInActivityLists;

/// 扩展信息
@property (nonatomic, copy, nullable) NSString *extendInfo;

@end


/// 用户信息
@interface SEAUserInfo : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 设备标识
@property (nonatomic, copy) NSString *deviceId;
/// 设备类型
@property (nonatomic, assign) SEADeviceType deviceType;
/// 过期时间
@property (nonatomic, assign) NSInteger expAt;

@end


/// 媒体配置参数
@interface SEAMediaConfig : NSObject

/// 回声消除AEC，默认 12
@property (nonatomic, assign) int aec;
/// 自动增益控制AGC，默认 16000
@property (nonatomic, assign) int agc;
/// 音频采样率，默认 48000
@property (nonatomic, assign) int audioSampe;
/// 音频编码格式，默认 OPUS
@property (nonatomic, assign) SEACodecType audioEncode;
/// 无外设时的默认内置音频路由，支持扬声器或听筒，默认 SEAAudioRouteReceiver
@property (nonatomic, assign) SEAAudioRoute audioRoute;

/// 视频分辨率宽必须是16的倍数 高必须是2的倍数 否则容易出现绿边等问题(已做了兼容)
/// 1080P---1920x1080
/// 720P---1280x720
/// 480P---640x480
/// 180P---320x180
/// 视频分辨率宽，默认 640
@property (nonatomic, assign) int videoWidth;
/// 视频分辨率高，默认 480
@property (nonatomic, assign) int videoHeight;
/// 视频镜像，默认 YES
@property (nonatomic, assign) BOOL videoMirror;

/// 视频帧率，默认 25
@property (nonatomic, assign) int fps;
/// 视频码率，默认 0.9*1024，单位kbps
@property (nonatomic, assign) int bitrate;

/// 是否启用媒体流加密 YES开启 NO关闭，默认 NO
@property (nonatomic, assign) BOOL enableEncrypt;
/// 是否强制横屏，默认 NO
@property (nonatomic, assign) BOOL forceLandscape;

@end


/// 网络质量控制参数
@interface SEANetworkQosParam : NSObject

/// 接收自适应延迟二档位，默认 500
@property (nonatomic, assign) int secondGear;
/// 接收自适应延迟三档位，默认 1200
@property (nonatomic, assign) int thirdGear;

/// 获取云端音频数据信息周期，默认 500毫秒
@property (nonatomic, assign) float onAudioCycle;

/// 开启硬件解码 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isHardwarede;
/// 开启网络自适应延迟 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isNetworkAdaptive;
/// 开启码率自适应 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isBitrateAdaptive;

/// 网络延时抗抖动等级，默认 SEANetworkQosShakeLevelMedium
@property (nonatomic, assign) SEANetworkQosShakeLevel shakeLevel;

@end


/// 调试模式参数
@interface SEADebugParam : NSObject

/// 远程调试地址
@property (nonatomic, copy, nullable) NSString *debugHost;
/// 保存视频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveVideo;
/// 保存采集音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioCapture;
/// 保存远程音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioReceive;

@end


/// 会议参数
@interface SEAMeetingParam : NSObject

/// 会议标识，修改会议信息时必填
@property (nonatomic, copy, nullable) NSString *meetingId;
/// 会议号码
@property (nonatomic, copy, nullable) NSString *roomNo;
/// 会议标题
@property (nonatomic, copy) NSString *title;
/// 会议说明
@property (nonatomic, copy, nullable) NSString *content;
/// 会议密码
@property (nonatomic, copy, nullable) NSString *password;
/// 参会成员标识列表
@property (nonatomic, copy, nullable) NSArray <NSString *> *conferee;
/// 参会类型，默认 SEAMeetingAttendTypeNormal
@property (nonatomic, assign) SEAMeetingAttendType attendType;
/// 会议类型，默认 SEAMeetingTypeInitiate
@property (nonatomic, assign) SEAMeetingType meetingType;
/// 会议模式，默认 SEAMeetingModeNormal
@property (nonatomic, assign) SEAMeetingMode meetingMode;
/// 会议布局
@property (nonatomic, strong) SEALayoutDataModel *layoutData;
/// 计划开始时间，SEAMeetingTypeSchedule 会议必填
@property (nonatomic, assign) NSInteger planTime;
/// 计划会议时长(单位分钟)，SEAMeetingTypeSchedule 会议必填
@property (nonatomic, assign) NSInteger planDuration;
/// 入会静音状态，默认 SEAMeetingMuteState3
@property (nonatomic, assign) SEAMeetingMuteState entryMutePolicy;
/// 水印是否关闭，默认 YES
@property (nonatomic, assign) BOOL watermarkDisabled;
/// 截屏是否禁止，默认 NO
@property (nonatomic, assign) BOOL screenshotDisabled;
/// 聊天是否禁止，默认 NO
@property (nonatomic, assign) BOOL chatDisabled;
/// 等候室是否禁用，默认 YES
@property (nonatomic, assign) BOOL waitingRoomDisabled;
/// 禁止在主持人之前入会，默认 NO
@property (nonatomic, assign) BOOL enterBeforeHostDisabled;
/// 是否开启录制，默认 YES
@property (nonatomic, assign) BOOL autoRecord;
/// 扩展信息
@property (nonatomic, copy, nullable) NSString *extendInfo;

@end


/// 加入会议参数
/// 入会时，可以选择会议号码或会议标识进行加会操作
@interface SEAMeetingEnterParam : NSObject

/// 会议号码
@property (nonatomic, copy, nullable) NSString *roomNo;
/// 会议标识
@property (nonatomic, copy, nullable) NSString *meetingId;
/// 会议密码
@property (nonatomic, copy, nullable) NSString *password;
/// 参会昵称
@property (nonatomic, copy, nullable) NSString *nickname;
/// 参会头像
@property (nonatomic, copy, nullable) NSString *avatar;
/// 扩展信息
@property (nonatomic, copy, nullable) NSString *extendInfo;
/// 流媒体提供商
@property (nonatomic, copy, nullable) NSString *streamVendor;
/// 是否以观众身份入会，默认 NO
@property (nonatomic, assign) BOOL isAudience;

@end


/// 创建房间响应对象
@interface SEAMeetingCreateModel : NSObject

/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 房间号码
@property (nonatomic, copy) NSString *roomNo;

@end


/// 数据分页对象
@interface SEASectionModel : NSObject

/// 当前页码
@property (nonatomic, assign) NSInteger currentPage;
/// 总页数
@property (nonatomic, assign) NSInteger pageCount;
/// 每页数据条数
@property (nonatomic, assign) NSInteger perPage;
/// 总数据条数
@property (nonatomic, assign) NSInteger totalCount;

@end


/// 聊天消息对象
@interface SEAChatModel : NSObject

/// 消息标识
@property (nonatomic, copy) NSString *messageId;
/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 消息内容
@property (nonatomic, copy) NSString *message;
/// 消息类型
@property (nonatomic, assign) SEAMessageType messageType;

/// 发送者标识
@property (nonatomic, copy) NSString *senderId;
/// 发送者昵称
@property (nonatomic, copy) NSString *senderName;

/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;

@end


/// 聊天消息列表对象
@interface SEAChatListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 聊天消息对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAChatModel *> *listData;

@end


/// 预签名上传结果对象
/// 拿到后由调用方自己 HTTP PUT 文件二进制到 url（请求头 Content-Type: application/octet-stream，不是 multipart），
/// 上传成功后业务里保存 / 发送的是 key 而不是 url（url 带签名、有效期约 2 小时）
@interface SEAPresignedPutObjectModel : NSObject

/// 预签名上传地址（PUT）
@property (nonatomic, copy) NSString *url;
/// 资源标识，下载时传给 presignedGetObject 的 resKey 换取下载地址
@property (nonatomic, copy) NSString *key;
/// 文件扩展名（不带点，后端回显）
@property (nonatomic, copy) NSString *ext;

@end


/// 会议信息对象
@interface SEAMeetingModel : NSObject

/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 会议号码
@property (nonatomic, copy) NSString *roomNo;
/// 会议标题
@property (nonatomic, copy) NSString *title;
/// 会议说明
@property (nonatomic, copy, nullable) NSString *content;
/// 会议密码
@property (nonatomic, copy, nullable) NSString *password;
/// 受邀成员标识列表
@property (nonatomic, copy, nullable) NSArray <NSString *> *conferee;
/// 创建者标识
@property (nonatomic, copy) NSString *creator;
/// 参会类型
@property (nonatomic, assign) SEAMeetingAttendType attendType;
/// 会议类型
@property (nonatomic, assign) SEAMeetingType meetingType;
/// 会议模式
@property (nonatomic, assign) SEAMeetingMode meetingMode;
/// 会议布局
@property (nonatomic, strong) SEALayoutDataModel *layoutData;
/// 会议状态
@property (nonatomic, assign) SEAMeetingStatus meetingStatus;
/// 计划开始时间
@property (nonatomic, assign) NSInteger planTime;
/// 计划会议时长，单位：分钟
@property (nonatomic, assign) NSInteger planDuration;

/// 实际开始时间
@property (nonatomic, assign) NSInteger beginTime;
/// 实际开始时间
@property (nonatomic, assign) NSInteger endTime;
/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;

/// 入会静音状态
@property (nonatomic, assign) SEAMeetingMuteState entryMutePolicy;
/// 房间水印禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL watermarkDisabled;
/// 房间截屏禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL screenshotDisabled;
/// 聊天能力禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL chatDisabled;
/// 麦克风禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL micDisabled;
/// 摄像头禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL cameraDisabled;
/// 是否禁止自我解除音频状态，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL selfUnmuteMicDisabled;
/// 是否禁止自我解除视频状态，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL selfUnmuteCameraDisabled;
/// 房间共享禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL shareDisabled;
/// 等候室禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL waitingRoomDisabled;
/// 禁止在主持人之前入会，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL enterBeforeHostDisabled;
/// 锁定状态，YES-开启 NO-关闭
@property (nonatomic, assign) BOOL locked;
/// 是否开启录制，YES-开启 NO-关闭
@property (nonatomic, assign) BOOL autoRecord;
/// 在线人数
@property (nonatomic, assign) NSInteger onlineNum;
/// 共享类型
@property (nonatomic, assign) SEAShareType shareType;

@end


/// 会议列表对象
@interface SEAMeetingListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 会议信息对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAMeetingModel *> *listData;

@end


/// 参会成员对象
@interface SEAMemberModel : NSObject

/// 记录标识
@property (nonatomic, copy) NSString *recordId;
/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 用户昵称
@property (nonatomic, copy) NSString *nickname;
/// 加入时间
@property (nonatomic, assign) NSInteger enterAt;
/// 离开时间
@property (nonatomic, assign) NSInteger exitAt;

@end


/// 参会成员列表对象
@interface SEAMemberListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 参会成员对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAMemberModel *> *listData;

@end


/// 流媒体音频信息
@interface SEAStreamAudioModel : RTCStreamAudioModel

@end


/// 流媒体发送状态数据
@interface SEAStreamSendModel : RTCStreamSendModel

@end


/// 流媒体接收状态数据
@interface SEAStreamReceiveModel : RTCStreamReceiveModel

@end


/// 流媒体质量监测数据
@interface SEAStreamQualityModel : RTCStreamQualitySampleModel

@end


/// 邀请设备对象
@interface SEAAgentModel : NSObject

/// 设备ID
@property (nonatomic, copy) NSString *deviceId;
/// 设备名称
@property (nonatomic, copy) NSString *name;
/// 设备类型
@property (nonatomic, assign) SEAAgentType type;
/// 设备状态
@property (nonatomic, assign) SEAAgentStatus status;
/// 设备标识
@property (nonatomic, copy) NSString *contact;
/// 设备备注
@property (nonatomic, copy) NSString *remark;
/// 连接参数
@property (nonatomic, copy) NSDictionary *connectParams;

@end


/// 邀请设备列表对象
@interface SEAAgentListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 代理设备对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAAgentModel *> *listData;

@end


/// 邀请对象
@interface SEAInviteModel : NSObject

/// 设备标识
@property (nonatomic, copy) NSString *contact;
/// 设备类型
@property (nonatomic, assign) SEAAgentType type;

/// 创建邀请数据对象
/// - Parameters:
///   - contact: 设备标识
///   - type: 设备类型
- (instancetype)initWithContact:(NSString *)contact type:(SEAAgentType)type;

@end


/// 小组会议参会成员对象
@interface SEAConfereeModel : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 用户昵称
@property (nonatomic, copy) NSString *nickname;

/// 创建参会成员数据对象
/// - Parameters:
///   - userId: 用户标识
///   - nickname: 用户昵称
- (instancetype)initWithUserId:(NSString *)userId nickname:(NSString *)nickname;

@end


/// 布局数据对象
@interface SEALayoutDataModel : NSObject

/// 布局类型，默认 auto
@property (nonatomic, copy) NSString *layout;
/// 是否轮询，默认 NO
@property (nonatomic, assign) BOOL isPolling;

/// 布局水印
@property (nonatomic, strong, nullable) SEALayoutWatermarkModel *watermark;
/// 布局标签
@property (nonatomic, strong, nullable) SEALayoutLabelModel *label;
/// 布局视图列表，即：逻辑块, 包含宫格与用户
@property (nonatomic, copy, nullable) NSArray <SEALayoutViewListModel *> *viewLists;

@end


/// 布局水印对象
@interface SEALayoutWatermarkModel : NSObject

/// 水印类型，默认 1；1-无，2-单排，3-多排
@property (nonatomic, assign) NSInteger type;
/// 字体大小，为0时，表示默认值
@property (nonatomic, assign) CGFloat size;
/// 字体颜色，为空时，表示默认值
@property (nonatomic, copy, nullable) NSString *color;
/// 轮廓颜色, 为空时，表示默认值
@property (nonatomic, copy, nullable) NSString *olColor;
/// 轮廓线宽, 为0时，表示默认值
@property (nonatomic, assign) CGFloat olWidth;

@end


/// 布局标签对象
@interface SEALayoutLabelModel : NSObject

/// 标签类型，默认 LT；字母或组合：L-左，R-右，T-上，B-下
@property (nonatomic, copy) NSString *type;
/// 字体大小，为0时，表示默认值
@property (nonatomic, assign) CGFloat size;
/// 字体颜色，为空时，表示默认值
@property (nonatomic, copy, nullable) NSString *color;
/// 背景颜色, 为空时，表示默认值
@property (nonatomic, copy, nullable) NSString *bgColor;

@end


/// 布局视图列表对象，即：逻辑块, 包含宫格与用户
@interface SEALayoutViewListModel : NSObject

/// 视图列表单元格
@property (nonatomic, copy, nullable) NSArray <SEALayoutViewListCellModel *> *itemLists;
/// 成员标识列表
@property (nonatomic, copy, nullable) NSArray <NSString *> *userIds;

@end


/// 布局视图列表单元格对象
@interface SEALayoutViewListCellModel : NSObject

/// 格子序号，排序规则按HTML中标签的顺序，默认 0
@property (nonatomic, assign) NSInteger index;
/// 是否优先绑定会议内的共享流，默认 NO
@property (nonatomic, assign) BOOL bindShare;
/// 单元格标签
@property (nonatomic, strong, nullable) SEALayoutLabelModel *label;

@end


/// 云录制参数
@interface SEACloudRecordParam : NSObject

/// 录制类型，默认 SEARecordTypeVideo
@property (nonatomic, assign) SEARecordType recordType;
/// 录制文件标题
@property (nonatomic, copy) NSString *title;
/// 录制布局
@property (nonatomic, strong) SEALayoutDataModel *layoutData;

@end


/// 云录制详情对象
@interface SEACloudRecordDetailsModel : NSObject

/// 任务标识
@property (nonatomic, copy) NSString *taskId;
/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 会议号码
@property (nonatomic, copy) NSString *roomNo;
/// 录制文件标题
@property (nonatomic, copy) NSString *title;
/// 操作人标识
@property (nonatomic, copy) NSString *opUid;
/// 操作人名称
@property (nonatomic, copy) NSString *opName;
/// 云录制状态
@property (nonatomic, assign) SEARecordStatus recordStatus;
/// 视频地址
@property (nonatomic, copy) NSString *videoKey;
/// 视频大小
@property (nonatomic, assign) NSInteger videoSize;
/// 录制标签
@property (nonatomic, copy) NSString *tags;
/// 错误描述
@property (nonatomic, copy) NSString *errorDesc;
/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;
/// 更新时间
@property (nonatomic, assign) NSInteger updatedAt;

@end


/// 云录制配置对象
@interface SEACloudRecordConfigModel : NSObject

/// 布局类型
@property (nonatomic, copy) NSString *layout;
/// 水印类型
@property (nonatomic, assign) NSInteger watermarkType;
/// 标签类型
@property (nonatomic, copy) NSString *labelType;
/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;
/// 更新时间
@property (nonatomic, assign) NSInteger updatedAt;

@end


/// 会议提醒对象
@interface SEAMeetingRemindModel : NSObject

/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 房间号码
@property (nonatomic, copy) NSString *roomNo;
/// 会议标题
@property (nonatomic, copy) NSString *title;
/// 创建者标识
@property (nonatomic, copy) NSString *creatorId;
/// 创建者昵称
@property (nonatomic, copy) NSString *creatorName;
/// 预约时间
@property (nonatomic, assign) NSInteger planTime;
/// 预约时长，单位：分钟
@property (nonatomic, assign) NSInteger planDuration;

@end


/// 等候室成员对象
@interface SEAWaitingRoomMemberModel : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 用户昵称
@property (nonatomic, copy) NSString *nickname;
/// 加入时间
@property (nonatomic, assign) NSInteger enterAt;

@end


/// 等候室成员列表对象
@interface SEAWaitingRoomMemberListModel : NSObject

/// 等候室成员对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAWaitingRoomMemberModel *> *listData;

@end


/// 小组会议对象
@interface SEARoomSubMeetingModel : NSObject

/// 小组标识
@property (nonatomic, copy) NSString *groupId;
/// 小组会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 主会议标识
@property (nonatomic, copy) NSString *parentMid;
/// 小组会议名称
@property (nonatomic, copy) NSString *title;
/// 小组会议状态
@property (nonatomic, assign) SEAMeetingStatus meetingStatus;

/// 小组会议参会成员
@property (nonatomic, copy, nullable) NSArray <SEAConfereeModel *> *conferee;

@end


/// 小组会议列表对象
@interface SEARoomSubMeetingListModel : NSObject

/// 小组会议对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEARoomSubMeetingModel *> *listData;

@end


/// 在线成员对象
@interface SEAOnlineMemberModel : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 用户昵称
@property (nonatomic, copy) NSString *nickname;
/// 设备类型
@property (nonatomic, assign) SEADeviceType deviceType;
/// 加入时间
@property (nonatomic, assign) NSInteger joinAt;

@end


/// 在线成员列表对象
@interface SEAOnlineMemberListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 在线成员数据列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAOnlineMemberModel *> *listData;

@end


/// 签到活动项对象
@interface SEASignInActivityModel : NSObject

/// 活动所属会议房间，用于解析房间内成员扩展数据
@property (nonatomic, weak, nullable) MeetingKitRoom *meetingRoom;
/// 用户标识(创建者)
@property (nonatomic, copy) NSString *userId;
/// 发起人昵称
@property (nonatomic, copy, nullable) NSString *hostName;
/// 签到轮次
@property (nonatomic, assign) NSInteger epoch;
/// 开始时间
@property (nonatomic, assign) NSInteger beginAt;
/// 签到时长，单位：分钟，0为不限时
@property (nonatomic, assign) NSInteger dur;
/// 结束时间
@property (nonatomic, assign) NSInteger endAt;
/// 活动状态
@property (nonatomic, assign) SEASignInActivityState status;
/// 签到描述
@property (nonatomic, copy, nullable) NSString *desc;
/// 签到人数
@property (nonatomic, assign) NSInteger nums;

@end


/// 签到活动列表对象
@interface SEASignInListModel : NSObject

/// 签到活动列表
@property (nonatomic, strong, nullable) NSMutableArray <SEASignInActivityModel *> *listData;
/// 当前服务器时间
@property (nonatomic, assign) NSInteger now;

@end


/// 签到统计人数对象
@interface SEASignInCountModel : NSObject

/// 签到人数
@property (nonatomic, assign) NSInteger nums;

@end


/// 签到详情项对象
@interface SEASignInDetailModel : NSObject

/// 记录标识
@property (nonatomic, copy) NSString *detailId;
/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 用户昵称
@property (nonatomic, copy) NSString *nickname;
/// 用户角色
@property (nonatomic, assign) SEAUserRole role;
/// 签到轮次
@property (nonatomic, assign) NSInteger epoch;
/// 签到时间
@property (nonatomic, assign) NSInteger createdAt;

@end


/// 签到活动详情列表对象
@interface SEASignInDetailListModel : NSObject

/// 签到详情列表
@property (nonatomic, strong, nullable) NSMutableArray <SEASignInDetailModel *> *listData;

@end


#pragma mark - ------------ 会前网络检测 ------------
/// 会前网络检测的参数与结果对象（MeetingKit networkCheck:onItem:completion: 使用）
/// 检测逻辑由 RTC 层实现，会议层同名透传并在 server 项里多一个 meeting_api 子检查；
/// 检测项、状态、原因码的字符串取值与各端 SDK 完全一致，便于 App 与日志跨端对照

/// 检测项标识，固定 5 项
typedef NSString *SEANetworkCheckItemId NS_TYPED_ENUM;
/// 网络权限（iOS：蜂窝数据权限，Wi-Fi 下不影响）
FOUNDATION_EXPORT SEANetworkCheckItemId const SEANetworkCheckItemIdPermission;
/// 网络连接情况（系统网络状态）
FOUNDATION_EXPORT SEANetworkCheckItemId const SEANetworkCheckItemIdConnectivity;
/// 最大传输单元检测（向媒体服务器发不分片的 UDP 探测包）
FOUNDATION_EXPORT SEANetworkCheckItemId const SEANetworkCheckItemIdMtu;
/// 域名解析检测（接口、信令、媒体服务器的域名）
FOUNDATION_EXPORT SEANetworkCheckItemId const SEANetworkCheckItemIdDns;
/// 服务器连接情况（子检查：会议接口 meeting_api、RTC 接口 api、信令 signal、媒体 media）
FOUNDATION_EXPORT SEANetworkCheckItemId const SEANetworkCheckItemIdServer;

/// 检测状态（单项与汇总共用一套字符串，汇总只会出现 ok / warning / fail）
typedef NSString *SEANetworkCheckStatus NS_TYPED_ENUM;
/// 汇总：全部正常
FOUNDATION_EXPORT SEANetworkCheckStatus const SEANetworkCheckStatusOk;
/// 单项：通过
FOUNDATION_EXPORT SEANetworkCheckStatus const SEANetworkCheckStatusPass;
/// 单项 / 汇总：有隐患但可用
FOUNDATION_EXPORT SEANetworkCheckStatus const SEANetworkCheckStatusWarning;
/// 单项 / 汇总：异常
FOUNDATION_EXPORT SEANetworkCheckStatus const SEANetworkCheckStatusFail;
/// 单项：无需检测（App 显示「无需检测」）
FOUNDATION_EXPORT SEANetworkCheckStatus const SEANetworkCheckStatusSkipped;
/// 单项：本平台不支持（App 显示「不支持」；iOS 五项都支持，保留取值与其它端对齐）
FOUNDATION_EXPORT SEANetworkCheckStatus const SEANetworkCheckStatusUnsupported;

/// 机器可读的原因码，通过时为空串
typedef NSString *SEANetworkCheckReason NS_TYPED_ENUM;
/// 未授予网络权限（iOS 不会出现，保留与其它端对齐）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonNoPermission;
/// 蜂窝数据被系统设置限制，且当前不在 Wi-Fi / 有线网络下
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonCellularRestricted;
/// 当前没有网络连接
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonOffline;
/// 1200 字节的探测包都回不来，但 STUN 通（网络对大包有限制）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonMtuTooSmall;
/// UDP 不通（媒体服务器 STUN 无应答 / 探测包全部无回显）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonUdpBlocked;
/// 有域名解析失败
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonDnsFailed;
/// 会议接口不可达（server.meeting_api 没有收到任何 HTTP 响应）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonMeetingApiUnreachable;
/// RTC 检测信息接口 netcheck/info 调用失败（服务器不可达或老服务端没有该接口）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonApiUnreachable;
/// 信令服务器连不上（TCP/TLS 与 WebSocket 都不通）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonSignalUnreachable;
/// 流媒体供应商不是 seastart，不做媒体 UDP / MTU 检测（skipped 时使用）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonVendorNotSupported;
/// seastart 但服务端没有可用的媒体节点（server 记 fail，mtu 记 skipped）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonMediaUnavailable;
/// 拿不到服务端检测信息，依赖它的 mtu、server.signal、server.media 记 skipped
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonServerInfoUnavailable;
/// 系统设不了不分片，mtu 记 unsupported（iOS 不会出现，保留与其它端对齐）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonDfNotSupported;
/// 系统接口查不到，该项记 unsupported（iOS 不会出现，保留与其它端对齐）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonQueryFailed;
/// 检测被取消（本端取消时完成回调直接返回 SEAErrorUserCancelled、不出单项结果，保留与其它端对齐）
FOUNDATION_EXPORT SEANetworkCheckReason const SEANetworkCheckReasonCancelled;


/// 网络检测参数
/// 已登录时可以不传（传 nil 即可），会议 SDK 从登录信息里取应用标识与服务器地址；
/// 未登录时须显式传 appId + serverUrl，或传 token（任意一个本应用的 RTC 令牌），二选一；两者都传时以 appId + serverUrl 为准
@interface SEANetworkCheckParams : NSObject

/// 应用标识(app_id)
@property (nonatomic, copy, nullable) NSString *appId;
/// RTC 的 SDK 接口前缀（即 RTC 令牌中的 client_api，如 @"https://host/client/"）
@property (nonatomic, copy, nullable) NSString *serverUrl;
/// RTC 加密令牌（频道令牌 / 即时通讯令牌均可，不要求未过期），appId / serverUrl 未传时从中解出
@property (nonatomic, copy, nullable) NSString *token;
/// 单项超时(毫秒)，默认 3000，小于等于 0 时按默认值
@property (nonatomic, assign) NSInteger timeoutMs;

@end


/// 网络检测单项结果
@interface SEANetworkCheckItem : NSObject

/// 检测项标识
@property (nonatomic, copy) SEANetworkCheckItemId itemId;
/// 检测状态：pass / warning / fail / skipped / unsupported
@property (nonatomic, copy) SEANetworkCheckStatus status;
/// 原因码，pass 时为空串
@property (nonatomic, copy) SEANetworkCheckReason reason;
/// 给人看的中文说明，App 可直接显示
@property (nonatomic, copy) NSString *message;
/// 本项耗时(毫秒)
@property (nonatomic, assign) NSInteger costMs;
/// 本项测量值，键名与各端一致：
/// connectivity：{netType: "wifi"|"cellular"|"ethernet"|"unknown"}
/// mtu：{maxSize: 1472}（全部不通时为 0）
/// dns：{hosts: [{host, ips, costMs}]}
/// server：{meeting_api:{ok,status,reason,rttMs}, api:{ok,status,reason,rttMs[,httpStatus,code]},
///          signal:{ok,status,reason,rttMs,via:"tcp"|"ws"}, media:{ok,status,reason,rttMs}}
///         meeting_api 为会议层子检查（收到任何 HTTP 响应即算可达；未登录时 status 为 skipped、reason 为 server_info_unavailable），
///         其余三个子检查原样来自 RTC 层
/// permission：{}
@property (nonatomic, copy) NSDictionary<NSString *, id> *data;

/// 转为字典（键名与其它端一致：id / status / reason / message / costMs / data），便于日志与跨端对照
- (NSDictionary<NSString *, id> *)toDictionary;

@end


/// 网络检测汇总结果
@interface SEANetworkCheckResult : NSObject

/// 汇总状态：有 fail 即 fail；无 fail 但有 warning 即 warning；否则 ok（skipped / unsupported 不影响汇总）
@property (nonatomic, copy) SEANetworkCheckStatus status;
/// 各项结果，固定 5 项、固定顺序：permission、connectivity、mtu、dns、server
@property (nonatomic, copy) NSArray<SEANetworkCheckItem *> *items;
/// 总耗时(毫秒)
@property (nonatomic, assign) NSInteger costMs;

/// 按单项结果计算汇总状态
/// @param items 单项结果
+ (SEANetworkCheckStatus)statusForItems:(NSArray<SEANetworkCheckItem *> *)items;

/// 转为字典（键名与其它端一致：status / items / costMs）
- (NSDictionary<NSString *, id> *)toDictionary;

@end


/// 网络检测单项完成回调（主线程），按固定顺序 permission → connectivity → mtu → dns → server 回调，每项一次
typedef void (^SEANetworkCheckItemBlock)(SEANetworkCheckItem *item);
/// 网络检测完成回调（主线程）
/// 正常结束：result 非空、errorCode 为 SEAErrorOK；被取消：result 为 nil、errorCode 为 SEAErrorUserCancelled(103026，透传 RTC 层码)
typedef void (^SEANetworkCheckCompletionBlock)(SEANetworkCheckResult * _Nullable result, SEAError errorCode);


NS_ASSUME_NONNULL_END
