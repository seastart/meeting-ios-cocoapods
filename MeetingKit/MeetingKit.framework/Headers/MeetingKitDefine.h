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
    SEAVideoStreamTypeBig = 0,
    /// 低清小画面，小画面和大画面的内容相同，但是分辨率和码率都比大画面低，因此清晰度也更低
    SEAVideoStreamTypeSmall = 1,
    /// 屏幕共享流
    SEAVideoStreamTypeScreen = 2
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


#pragma mark - 用户类型
/// 用户类型
typedef enum : NSInteger {
    
    /// 普通用户
    SEAUserTypeNormal = 1,
    /// SIP
    SEAUserTypeSIP = 2,
    /// H323
    SEAUserTypeH323 = 3
} SEAUserType;


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
    SEAHandupTypeChat = 3
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


#pragma mark - 操作相关回调
/// 成功回调
typedef void (^SEASuccessBlock)(id _Nullable data);
/// 失败回调
typedef void (^SEAFailedBlock)(SEAError code, NSString * _Nonnull message);

NS_ASSUME_NONNULL_END
