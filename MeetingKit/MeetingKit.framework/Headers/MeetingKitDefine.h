//
//  MeetingKitDefine.h
//  MeetingKit
//
//  Created by SailorGa on 2024/2/20.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 错误码
/// 错误码
typedef enum : NSInteger {
    
    /// 无错误
    SEAErrorOK = 0,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       API错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 请求头中缺少APPID
    SEAErrorRtcApiHeaderNotAppId = 1001,
    /// 请求头中的APPID无效
    SEAErrorRtcApiHeaderInvalidAppId = 1002,
    /// 请求头中的签名无效
    SEAErrorRtcApiHeaderInvalidSignature = 1003,
    /// 请求头中的时间戳无效
    SEAErrorRtcApiHeaderInvalidTimestamp = 1004,
    /// 请求头中的会话标识无效
    SEAErrorApiHeaderInvalidSession = 1005,
    /// 请求头中缺少随机标识
    SEAErrorRtcApiHeaderNotNonce = 1006,
    
    /// 应用无效
    SEAErrorRtcApiInvalidApplication = 1011,
    /// 服务组无效
    SEAErrorRtcApiInvalidServiceGroup = 1012,
    /// 服务无效
    SEAErrorRtcApiInvalidService = 1013,
    /// 应用场景无效
    SEAErrorRtcApiInvalidScene = 1014,
    /// 回调配置无效
    SEAErrorRtcApiInvalidConfigure = 1015,
    
    /// 生成 Channel Token 失败
    SEAErrorRtcApiChannelTokenFailed = 1020,
    /// Channel Token 已被使用
    SEAErrorRtcApiChannelTokenOccupied = 1021,
    /// 该会话不在频道中
    SEAErrorRtcApiSessionNotFound = 1022,
    /// 成员不在频道中
    SEAErrorRtcApiMemberNotFound = 1023,
    /// 频道未开启
    SEAErrorRtcApiChannelNotOpen = 1024,
    /// 频道已开启
    SEAErrorRtcApiChannelOpen = 1025,
    /// 生成 Im Token 失败
    SEAErrorRtcApiImTokenFailed = 1030,
    /// Im Token 已被使用
    SEAErrorRtcApiImTokenOccupied = 1031,
    /// 该会话不在线
    SEAErrorRtcApiSessionOffline = 1032,
    /// 并发已达上限
    SEAErrorRtcApiInsufficientConcurrency = 1033,
    
    /// 未找到MCU任务
    SEAErrorRtcApiNotFoundMcuTask = 1040,
    /// 录像任务还未结束
    SEAErrorRtcApiRecordTaskUnfinished = 1041,
    /// 录像任务还未生成录像文件
    SEAErrorRtcApiRecordTaskNotFile = 1042,
    /// MCU的布局数据出错
    SEAErrorRtcApiMcuLayoutFailed = 1043,
    /// MCU任务已经停止
    SEAErrorRtcApiMcuTaskStoped = 1044,
    
    /// 当前用户已在其它地登录
    SEAErrorMeetingApiRemoteLogin = 2040,
    /// 请求头中缺少APPID
    SEAErrorMeetingApiHeaderNotAppId = 2041,
    /// 请求头中的APPID无效
    SEAErrorMeetingApiHeaderInvalidAppId = 2042,
    /// 请求头中的签名无效
    SEAErrorMeetingApiHeaderInvalidSignature = 2043,
    /// 请求头中的时间戳无效
    SEAErrorMeetingApiHeaderInvalidTimestamp = 2044,
    /// 请求头中的会议会话标识无效
    SEAErrorMeetingApiHeaderInvalidSession = 2045,
    /// 请求头中缺少随机标识
    SEAErrorMeetingApiHeaderNotNonce = 2046,
    /// 请求头中缺少用户标识
    SEAErrorMeetingApiHeaderNotUserId = 2047,
    
    /// 生成 Token 失败
    SEAErrorMeetingApiTokenFailed = 2050,
    /// 未获取授权
    SEAErrorMeetingApiNotAuthorized = 2051,
    /// 授权过期
    SEAErrorMeetingApiTokenExpired = 2052,
    
    /// 会议内部错误
    SEAErrorMeetingApiFailed = 2100,
    /// 会议不存在
    SEAErrorMeetingApiNotFound = 2101,
    /// 会议未开始
    SEAErrorMeetingApiNotStarted = 2102,
    /// 会议已结束
    SEAErrorMeetingApiFinished = 2103,
    /// 会中已经有人在共享
    SEAErrorMeetingApiSomeoneSharing = 2104,
    /// 会中不在共享状态
    SEAErrorMeetingApiNotSharing = 2105,
    /// 会议已被锁定
    SEAErrorMeetingApiLocked = 2106,
    /// 已被踢出，无法入会
    SEAErrorMeetingApiKickedout = 2107,
    /// 已经在其它会议中
    SEAErrorMeetingApiAtOtherMeeting = 2108,
    /// 已经在该会议中
    SEAErrorMeetingApiAlreadyExisted = 2109,
    /// 不在该会议中
    SEAErrorMeetingApiNotMeeting = 2110,
    /// 目标不在该会议中
    SEAErrorMeetingApiMemberNotFound = 2111,
    /// 不允许开麦克风
    SEAErrorMeetingApiMicDisabled = 2112,
    /// 不允许开摄像头
    SEAErrorMeetingApiCameraDisabled = 2113,
    /// 不允许聊天
    SEAErrorMeetingApiChatDisabled = 2114,
    /// 密码错误
    SEAErrorMeetingApiPasswordFailed = 2115,
    /// 会议仅限受邀人加入,请联系主持人
    SEAErrorMeetingApiByInviteOnly = 2116,
    /// 会议开启等候室，需要管理员确认后入会
    SEAErrorMeetingApiWaitingRoomEnable = 2118,
    /// 会议禁止在主持人之前加入
    SEAErrorMeetingApiEnterBeforeHostDisabled = 2120,
    
    /// 未归类的通用错误
    SEAErrorApiFailed = 10000,
    /// 数据库错误或异常
    SEAErrorApiDatabaseFailed = 10001,
    /// 数据记录未找到
    SEAErrorApiRecordNotFound = 10002,
    /// 数据记录已存在
    SEAErrorApiRepeatFound = 10003,
    /// ⽆权限
    SEAErrorApiNotAuthorized = 10040,
    /// 未登录
    SEAErrorApiNotInitialized = 10041,
    /// 令牌⽆效
    SEAErrorApiTokenDisabled = 10042,
    /// 令牌已过期
    SEAErrorApiTokenExpired = 10043,
    /// ⽹络错误或异常
    SEAErrorApiNetworkFailed = 10051,
    /// 请求超时
    SEAErrorApiNetworkTimeout = 10055,
    /// 请求参数不合法
    SEAErrorApiInvalidParameter = 10070,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       RTC错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 系统内部错误
    SEAErrorSystemError = 100001,
    /// 未初始化
    SEAErrorNotInitialized = 100002,
    /// 媒体模块尚未初始化
    SEAErrorMediaNotInitialized = 100003,
    /// 协议解析错误
    SEAErrorProtocolParsingError = 100004,
    
    /// 超时
    SEAErrorTimeout = 100005,
    /// 参数错误
    SEAErrorInvalidArgs = 100006,
    /// 重复操作冲突
    SEAErrorConflict = 100007,
    /// 令牌失效
    SEAErrorSdkTokenInvalid = 100008,
    
    /// 网络错误
    SEAErrorNetError = 100009,
    /// 媒体网络错误
    SEAErrorMediaNetError = 100010,
    /// 目标不存在
    SEAErrorNotFound = 100011,
    
    /// 设备访问无权限
    SEAErrorDeviceNoAuthorized = 103001,
    /// 未加入频道
    SEAErrorNotJoinedChannel = 103002,
    /// 操作不被允许
    SEAErrorForbidden = 103003,
    /// 码流不存在
    SEAErrorStreamNotFound = 103004,
    /// 没有权限执行操作
    SEAErrorNotAuthorized = 103005
} SEAError;


#pragma mark - 设备类型
/// 设备类型
typedef enum : NSUInteger {
    
    /// 未知设备
    SEADeviceTypeUnknown = 0,
    
    /// Windows
    SEADeviceTypeWindows = 1,
    /// Android
    SEADeviceTypeAndroid = 2,
    /// iOS
    SEADeviceTypeIOS = 3,
    /// Linux
    SEADeviceTypeLinux = 4,
    /// MacOS
    SEADeviceTypeMacOS = 5,
    
    /// WebRTC
    SEADeviceTypeWebRTC = 6,
    /// 微信小程序
    SEADeviceTypeWeChat = 7
} SEADeviceType;


#pragma mark - 编码类型
/// 编码类型
typedef enum : NSUInteger {
    
    /// 未知类型
    SEACodecTypeUnknown = 0,
    /// H264
    SEACodecTypeH264 = 0x1b,
    /// H265
    SEACodecTypeH265 = 0x24,
    /// AAC
    SEACodecTypeAAC = 0x0f,
    /// OPUS
    SEACodecTypeOPUS = 0x5355504f
} SEACodecType;


#pragma mark - 网络延时抗抖动等级
/// 网络延时抗抖动等级
typedef enum : NSInteger {
    
    /// 超短(0) 单向延迟120ms左右 这种模式下没有丢包补偿机制 并且编码关闭了B帧 一般不建议实际使用
    SEANetworkQosShakeLevelUltraShort = 0,
    /// 短(1) 单向延迟200ms左右 单次丢包补偿 B帧为1 双向对讲环境下可以使用
    SEANetworkQosShakeLevelShort = 1,
    /// 中(2) 单向延迟350ms左右 两次丢包补偿 B帧为1 双向对讲环境下推荐使用
    SEANetworkQosShakeLevelMedium = 2,
    /// 长(3) 单向延迟600ms左右 三次丢包补偿 B帧为3 这种模式仅用于单向收看 双向对讲环境下不建议使用 该参数无法动态设置
    SEANetworkQosShakeLevelLong = 3
} SEANetworkQosShakeLevel;


#pragma mark - 音频路由类型
/// 音频路由类型
typedef enum : NSInteger {
    
    /// 未知
    SEAAudioRouteUnknown = 0,
    /// 扬声器
    SEAAudioRouteSpeaker = 1,
    /// 听筒
    SEAAudioRouteReceiver = 2,
    /// 蓝牙耳机
    SEAAudioRouteBluetooth = 3,
    /// 有线耳机
    SEAAudioRouteHeadset = 4
} SEAAudioRoute;


#pragma mark - 视频流类型
/// 视频流类型
typedef enum : NSInteger {
    
    /// 高清大画面，一般用来传输摄像头的视频数据
    SEAVideoStreamTypeBig = 1,
    /// 低清小画面，小画面和大画面的内容相同，但是分辨率和码率都比大画面低，因此清晰度也更低
    SEAVideoStreamTypeSmall = 2,
    /// 屏幕共享流
    SEAVideoStreamTypeScreen = 3
} SEAVideoStreamType;


#pragma mark - 屏幕共享状态
/// 屏幕共享状态
typedef enum : NSInteger {
    
    /// 屏幕共享常规状态
    SEAScreenRecordStatusNormal = 1000,
    /// 屏幕共享连接错误
    SEAScreenRecordStatusError = -1,
    /// 屏幕共享已经停止
    SEAScreenRecordStatusStop = 0,
    /// 屏幕共享已经开始
    SEAScreenRecordStatusStart = 1
} SEAScreenRecordStatus;


#pragma mark - 用户角色
/// 用户角色
typedef enum : NSInteger {
    
    /// 普通成员
    SEAUserRoleNormal = 0,
    /// 主持人
    SEAUserRoleHost = 1,
    /// 联席主持人
    SEAUserRoleUnionHost = 2
} SEAUserRole;


#pragma mark - 会议类型
/// 会议类型
typedef enum : NSInteger {
    
    /// 即时会议
    SEAMeetingTypeInitiate = 1,
    /// 预约会议
    SEAMeetingTypeSchedule = 2
} SEAMeetingType;


#pragma mark - 会议模式
/// 会议模式
typedef enum : NSInteger {
    
    /// 常规会议模式
    SEAMeetingModeNormal = 1,
    /// 合成会议模式
    SEAMeetingModeMixture = 2,
    /// 语音会议模式
    SEAMeetingModeVoice = 3,
    /// 培训会议模式
    SEAMeetingModeTraining = 4,
    /// 小组会议模式
    SEAMeetingModeGroups = 5
} SEAMeetingMode;


#pragma mark - 会议状态
/// 会议状态
typedef enum : NSInteger {
    
    /// 未开始
    SEAMeetingStatusNotStart = 1,
    /// 进行中
    SEAMeetingStatusIng = 2,
    /// 已结束
    SEAMeetingStatusEnded = 3
} SEAMeetingStatus;


#pragma mark - 参会类型
/// 参会类型
typedef enum : NSInteger {
    
    /// 无限制
    SEAMeetingAttendTypeNormal = 1,
    /// 密码参会
    SEAMeetingAttendTypePassword = 2,
    /// 仅邀请人员参会
    SEAMeetingAttendTypeInitiate = 3
} SEAMeetingAttendType;


#pragma mark - 入会静音状态
/// 入会静音状态
typedef enum : NSInteger {
    
    /// 开启入会静音(所有人入会默认静音)
    SEAMeetingMuteState1 = 1,
    /// 关闭入会静音(跟随客户端初始音频状态)
    SEAMeetingMuteState2 = 2,
    /// 超6人静音(超过6人后入会静音)
    SEAMeetingMuteState3 = 3
} SEAMeetingMuteState;


#pragma mark - 设备状态
/// 设备状态
typedef enum : NSInteger {
    
    /// 开启状态
    SEADeviceStateOpen = 1,
    /// 关闭状态
    SEADeviceStateClosed = 2
} SEADeviceState;


#pragma mark - 共享类型
/// 共享类型
typedef enum : NSInteger {
    
    /// 默认类型
    SEAShareTypeNormal = 0,
    /// 共享屏幕
    SEAShareTypeScreen = 1,
    /// 共享画板
    SEAShareTypeDrawing = 2
} SEAShareType;


#pragma mark - 消息类型
/// 消息类型
typedef enum : NSInteger {
    
    /// 文本消息
    SEAMessageTypeText = 1,
    /// 文件消息
    SEAMessageTypeFile = 2,
    /// 图片消息
    SEAMessageTypePicture = 3,
    /// 语音消息
    SEAMessageTypeVoice = 4,
    /// 自定义消息
    SEAMessageTypeCustom = 5
} SEAMessageType;


#pragma mark - 举手申请类型
/// 举手申请类型
typedef enum : NSInteger {
    
    /// 麦克风
    SEAHandupTypeMic = 1,
    /// 摄像头
    SEAHandupTypeCamera = 2,
    /// 聊天
    SEAHandupTypeChat = 3,
    /// 共享
    SEAHandupTypeShare = 4,
    /// 涂鸦
    SEAHandupTypeDraw = 4,
} SEAHandupType;


#pragma mark - 离开原因
/// 离开原因
typedef enum : NSInteger {
    
    /// 主动离开
    SEALeaveReasonNormal = 1,
    /// 被踢离开
    SEALeaveReasonKickout = 2,
    /// 被顶号
    SEALeaveReasonReplaced = 3,
    /// 心跳超时离开
    SEALeaveReasonTimeout = 4,
    /// 频道销毁离开
    SEALeaveReasonDestroy = 5
} SEALeaveReason;


#pragma mark - 音视频状态更改原因
/// 音视频状态更改原因
typedef enum : NSInteger {
    
    /// 自己操作
    SEAChangeReasonBySelf = 0,
    /// 主持人或联席主持人操作
    SEAChangeReasonByAdmin = 1
} SEAChangeReason;


#pragma mark - 下行码率自适应状态
/// 下行码率自适应状态
typedef enum : NSInteger {
    
    /// 正常
    SEADownBitrateAdaptiveStateNormal = 0,
    /// 较差
    SEADownBitrateAdaptiveStatePoor = -1,
    /// 很差
    SEADownBitrateAdaptiveStateBad = -2,
    /// 极差
    SEADownBitrateAdaptiveStateVeryBad = -3,
    /// 下行链路状态不存在
    SEADownBitrateAdaptiveStateLose = -4
} SEADownBitrateAdaptiveState;


#pragma mark - 上行码率自适应状态
/// 上行码率自适应状态
typedef enum : NSInteger {
    
    /// 码率自适应开始工作
    SEAUploadBitrateAdaptiveStateStart = 1000,
    /// 码率恢复到最初设置
    SEAUploadBitrateAdaptiveStateNormal = 0,
    /// 码率变为原来的一半
    SEAUploadBitrateAdaptiveStateHalf = -1,
    /// 码率变为原来的四分之一
    SEAUploadBitrateAdaptiveStateQuarter = -2,
    /// 当前网络环境及其差劲情况
    SEAUploadBitrateAdaptiveStateVeryBad = -3,
} SEAUploadBitrateAdaptiveState;


#pragma mark - 下行平均丢包档位
/// 下行平均丢包档位
typedef enum : NSInteger {
    
    /// 无效
    SEADownLossLevelStateInvalid = -1,
    /// 正常
    SEADownLossLevelStateNormal = 0,
    /// 较差
    SEADownLossLevelStatePoor = 1,
    /// 很差
    SEADownLossLevelStateBad = 2,
    /// 极差
    SEADownLossLevelStateVeryBad = 3
} SEADownLossLevelState;


#pragma mark - im断开原因
/// im断开原因
typedef enum : NSInteger {
    
    /// 发生错误
    SEAImDisconnectReasonError = -1,
    /// 主动离开
    SEAImDisconnectReasonNormal = 1,
    /// 被踢离开
    SEAImDisconnectReasonKickout = 2,
    /// 心跳超时离开
    SEAImDisconnectReasonTimeout = 4
} SEAImDisconnectReason;


#pragma mark - 邀请设备类型
/// 邀请设备类型
typedef enum : NSUInteger {
    
    /// SIP
    SEAAgentTypeSIP = 2,
    /// H323
    SEAAgentTypeH323 = 3,
    /// GB28181
    SEAAgentTypeGB28181 = 4,
    /// RTSP拉流
    SEAAgentTypeRTSP = 5,
    /// RTMP拉流
    SEAAgentTypeRTMP = 6,
    /// 文件播放
    SEAAgentTypeFile = 7,
    /// 腾讯会议
    SEAAgentTypeTencent = 8,
    /// AI
    SEAAgentTypeAI = 9
} SEAAgentType;


#pragma mark - 邀请设备状态
/// 邀请设备状态
typedef enum : NSUInteger {
    
    /// 未知
    SEAAgentStatusUnknown = 0,
    /// 在线
    SEAAgentStatusOnline = 1,
    /// 离线
    SEAAgentStatusOffline = 2
} SEAAgentStatus;


#pragma mark - 录制类型
/// 录制类型
typedef enum : NSInteger {
    
    /// 录像模式
    SEARecordTypeVideo = 1,
    /// 合流模式
    SEARecordTypeMixture = 2,
    /// 混合模式
    SEARecordTypeAll = 3
} SEARecordType;


#pragma mark - 录制状态
/// 录制状态
/// 注：除 SEARecordStatusIng 状态以外，都可视为录制未开始状态
typedef enum : NSInteger {
    
    /// 未开始
    SEARecordStatusWaitStart = 0,
    /// 进行中
    SEARecordStatusIng = 1,
    /// 待结束
    SEARecordStatusWaitEnded = 2,
    /// 异常结束
    SEARecordStatusError = 3,
    /// 正常结束
    SEARecordStatusEnded = 4
} SEARecordStatus;


#pragma mark - 通话角色
/// 通话角色
typedef enum : NSInteger {
    
    /// 未知类型
    SEACallRoleNone = 0,
    /// 主叫(邀请方)
    SEACallRoleCall = 1,
    /// 被叫(被邀请方)
    SEACallRoleCalled = 2,
} SEACallRole;


#pragma mark - 通话状态
/// 通话状态
typedef enum : NSInteger {
    
    /// 未知
    SEACallStatusNone = 0,
    /// 接听
    SEACallStatusAccept = 1,
    /// 拒绝
    SEACallStatusReject = 2,
    /// 忙线
    SEACallStatusBusy = 3,
} SEACallStatus;


#pragma mark - 操作相关回调
/// 成功回调
typedef void (^SEASuccessBlock)(id _Nullable data);
/// 失败回调
typedef void (^SEAFailedBlock)(SEAError code, NSString * _Nonnull message);

NS_ASSUME_NONNULL_END
