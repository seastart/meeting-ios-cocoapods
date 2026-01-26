//
//  MeetingKitDelegate.h
//  MeetingKit
//
//  Created by SailorGa on 2024/2/20.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MeetingKit;

#pragma mark - MeetingKit 事件回调
@protocol MeetingKitDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ------------ 错误事件回调 ------------
#pragma mark 错误事件回调
/// 错误事件回调
/// 发生不可恢复的错误，这个事件触发一般需要获取新的令牌重新入会。
/// - Parameters:
///   - errCode: 错误码
///   - errMsg: 错误信息
- (void)onError:(SEAError)errCode errMsg:(nullable NSString *)errMsg;


#pragma mark - ------------ 连接事件回调 ------------
#pragma mark 开始重连事件回调
/// 开始重连事件回调
/// 收到该事件说明连接出现异常，正在尝试重连，如：网络异常等。
- (void)onReconnecting;

#pragma mark 重连成功事件回调
/// 重连成功事件回调
/// 当连接恢复时，会收到该事件通知。
- (void)onReconnected;


#pragma mark - ------------ 我的相关回调 ------------
#pragma mark 进入房间事件回调
/// 进入房间事件回调
/// 调用 enterRoom: 接口执行加入房间操作后，会收到该事件通知，如果遇到错误会通过方法的 onFailed 参数抛出。
/// - Parameters:
///   - meetingId: 会议标识
///   - userId: 用户标识
- (void)onEnterRoom:(NSString *)meetingId userId:(NSString *)userId;

#pragma mark 离开房间事件回调
/// 离开房间事件回调
/// 当前用户非主动离开时，会收到该事件通知，如：被主持人踢出房间、会议解散等。
/// - Parameter reason: 离开原因
- (void)onExitRoom:(SEALeaveReason)reason;

#pragma mark 请求开启摄像头回调
/// 请求开启摄像头回调
/// 主持人调用 adminRequestUserOpenCamera: 接口执行请求打开成员摄像头后，对应成员会收到该事件通知。
/// - Parameter userId: 请求者标识
- (void)onRequestOpenCamera:(NSString *)userId;

#pragma mark 请求开启麦克风回调
/// 请求开启麦克风回调
/// 主持人调用 adminRequestUserOpenMic: 接口执行请求打开成员麦克风后，对应成员会收到该事件通知。
/// - Parameter userId: 请求者标识
- (void)onRequestOpenMic:(NSString *)userId;

#pragma mark 请求开启共享回调
/// 请求开启共享回调
/// 主持人调用 adminRequestUserOpenShare: 接口执行请求打开成员共享后，对应成员会收到该事件通知。
/// - Parameter userId: 请求者标识
- (void)onRequestOpenShare:(NSString *)userId;

#pragma mark 被管理员移进等候室回调
/// 被管理员移进等候室回调
/// 主持人调用 adminMoveInWaitingRoom: 接口执行将您从会议室移动到等候室后，此时您会收到该事件通知。
/// - Parameter userId: 操作者标识
- (void)onRoomMoveInWaitingRoom:(NSString *)userId;

#pragma mark 被管理员移进小组会议或主会场回调
/// 被管理员移进小组会议或主会场回调
/// 主持人调用 adminMoveSubMeetingUser: 接口执行小组会议之间移动用户后，此时您会收到该事件通知。
/// - Parameters:
///   - fromMeetingId: 原小组会议标识
///   - fromMeetingTitle: 原小组会议标题
///   - toMeetingId: 目标小组会议标识
///   - toMeetingTitle: 目标小组会议标题
- (void)onRoomMoveSubMeeting:(NSString *)fromMeetingId fromMeetingTitle:(NSString *)fromMeetingTitle toMeetingId:(NSString *)toMeetingId toMeetingTitle:(NSString *)toMeetingTitle;


#pragma mark - ------------ 房间事件回调 ------------
#pragma mark 房间摄像头禁用状态变更回调
/// 房间摄像头禁用状态变更回调
/// 主持人调用 adminUpdateRoomCameraState: 接口执行更新房间全体禁视频后，当前房间所有成员都会收到该事件通知。
/// - Parameter cameraDisabled: 房间视频禁用状态，YES-禁用 NO-不禁用
/// - Parameter selfUnmuteCameraDisabled: 是否禁止自我解除视频状态，YES-禁止 NO-不禁止
/// - Parameter userId: 操作者标识
- (void)onRoomCameraStateChanged:(BOOL)cameraDisabled selfUnmuteCameraDisabled:(BOOL)selfUnmuteCameraDisabled userId:(NSString *)userId;

#pragma mark 房间麦克风禁用状态变更回调
/// 房间麦克风禁用状态变更回调
/// 主持人调用 adminUpdateRoomMicState: 接口执行更新房间全体禁音频后，当前房间所有成员都会收到该事件通知。
/// - Parameter micDisabled: 房间音频禁用状态，YES-禁用 NO-不禁用
/// - Parameter selfUnmuteMicDisabled: 是否禁止自我解除音频状态，YES-禁止 NO-不禁止
/// - Parameter userId: 操作者标识
- (void)onRoomMicStateChanged:(BOOL)micDisabled selfUnmuteMicDisabled:(BOOL)selfUnmuteMicDisabled userId:(NSString *)userId;

#pragma mark 房间聊天禁用状态变更回调
/// 房间聊天禁用状态变更回调
/// 主持人调用 adminUpdateRoomChatDisabled: 接口执行更新房间聊天禁用状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter chatDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)onRoomChatDisabledChanged:(BOOL)chatDisabled userId:(NSString *)userId;

#pragma mark 房间共享禁用状态变更回调
/// 房间共享禁用状态变更回调
/// 主持人调用 adminUpdateRoomShareDisabled: 接口执行更新房间共享禁用状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter shareDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)onRoomShareDisabledChanged:(BOOL)shareDisabled userId:(NSString *)userId;

#pragma mark 房间截图禁用状态变更回调
/// 房间截图禁用状态变更回调
/// 主持人调用 adminUpdateRoomScreenshotDisabled: 接口执行更新房间截屏开关状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter screenshotDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)onRoomScreenshotDisabledChanged:(BOOL)screenshotDisabled userId:(NSString *)userId;

#pragma mark 房间水印禁用状态变更回调
/// 房间水印禁用状态变更回调
/// 主持人调用 adminUpdateRoomWatermarkDisabled: 接口执行更新房间水印开关状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter watermarkDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)onRoomWatermarkDisabledChanged:(BOOL)watermarkDisabled userId:(NSString *)userId;

#pragma mark 房间等候室禁用状态变更回调
/// 房间等候室禁用状态变更回调
/// 主持人调用 adminUpdateWaitingRoomDisabled: 接口执行更新房间等候室禁用状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter waitingRoomDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)onRoomWaitingRoomDisabledChanged:(BOOL)waitingRoomDisabled userId:(NSString *)userId;

#pragma mark 房间锁定状态变化回调
/// 房间锁定状态变化回调
/// 主持人调用 adminUpdateRoomLocked: 接口执行更新房间锁定状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter locked: 锁定状态，YES-开启 NO-关闭
/// - Parameter userId: 操作者标识
- (void)onRoomLockedChanged:(BOOL)locked userId:(NSString *)userId;

#pragma mark 房间转移主持人回调
/// 房间转移主持人回调
/// 主持人调用 adminMoveHost: 接口执行主持人转移操作后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - userId: 新主持人用户标识
///   - sourceUserId: 原主持人用户标识
- (void)onRoomMoveHost:(NSString *)userId sourceUserId:(NSString *)sourceUserId;

#pragma mark 共享开始回调
/// 共享开始回调
/// 成员调用 requestShare: 接口执行请求开启共享后，如果服务允许此用户开启共享操作，当前房间所有成员都会收到该事件通知，注：如果当前房间正在共享，后续加入的成员也会收到该事件通知。
/// - Parameter userId: 共享成员标识
/// - Parameter shareType: 共享类型
- (void)onRoomShareStart:(NSString *)userId shareType:(SEAShareType)shareType;

#pragma mark 共享结束回调
/// 共享结束回调
/// 成员调用 stopShare: 接口执行关闭共享后，当前房间所有成员都会收到该事件通知，注：如果共享成员未结束共享直接执行退出操作，此时其他成员也会收到该事件通知。
/// - Parameter userId: 共享成员标识
/// - Parameter shareType: 共享类型
- (void)onRoomShareStop:(NSString *)userId shareType:(SEAShareType)shareType;

#pragma mark 主持人结束房间共享回调
/// 主持人结束房间共享回调
/// 主持人调用 adminStopRoomShare: 接口执行关闭共享后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
/// - Parameter userId: 共享成员标识
/// - Parameter shareType: 共享类型
- (void)onAdminRoomShareStop:(NSString *)userId shareType:(SEAShareType)shareType;

#pragma mark 房间成员举手状态变化回调
/// 房间成员举手状态变化回调
/// 成员调用 requestHandup: 接口执行请求举手后，拥有管理权限的成员会收到该事件通知。
/// - Parameter userId: 成员标识
/// - Parameter enable: 举手状态，YES-申请举手 NO-取消举手
/// - Parameter handupType: 举手申请类型
- (void)onRoomHandUpChanged:(NSString *)userId enable:(BOOL)enable handupType:(SEAHandupType)handupType;

#pragma mark 房间讨论组开始回调
/// 房间讨论组开始回调
/// 主持人调用 adminStartSubMeeting: 接口执行开始小组会议后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - meetingId: 会议标识
///   - title: 小组名称
///   - conferee: 参会成员
- (void)onRoomSubMeetingStart:(NSString *)meetingId title:(NSString *)title conferee:(nullable NSArray <NSString *> *)conferee;

#pragma mark 房间讨论组结束回调
/// 房间讨论组结束回调
/// 主持人调用 adminStopSubMeeting: 接口执行结束小组会议后，当前房间所有成员都会收到该事件通知。
/// - Parameter parentMid: 上级会议标识
- (void)onRoomSubMeetingStop:(NSString *)parentMid;

#pragma mark 房间会议标题变化回调
/// 房间会议标题变化回调
/// - Parameter title: 会议标题
- (void)onRoomMeetingTitleChanged:(NSString *)title;


#pragma mark - ------------ 用户事件回调 ------------
#pragma mark 远端用户加入房间回调
/// 远端用户加入房间回调
/// 成员调用 enterRoom: 接口执行加入房间后，当前房间所有成员都会收到该事件通知。
/// - Parameter userId: 成员标识
- (void)onUserEnter:(NSString *)userId;

#pragma mark 远端用户离开房间回调
/// 远端用户离开房间回调
/// 成员调用 exitRoom: 接口执行离开房间后，当前房间所有成员都会收到该事件通知。
/// - Parameter userId: 成员标识
- (void)onUserExit:(NSString *)userId;

#pragma mark 用户昵称变化回调
/// 用户昵称变化回调
/// 成员调用 updateName: 接口执行更新昵称或者主持人调用 adminUpdateNickname: 接口执行更新用户昵称后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - targetUserId: 目标成员标识
///   - nickname: 用户昵称
- (void)onUserNameChanged:(NSString *)targetUserId nickname:(NSString *)nickname;

#pragma mark 用户角色变化回调
/// 用户角色变化回调
/// 主持人调用 adminUpdateUserRole: 接口执行更新用户角色后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - targetUserId: 目标成员标识
///   - userRole: 用户角色
- (void)onUserRoleChanged:(NSString *)targetUserId userRole:(SEAUserRole)userRole;

#pragma mark 用户摄像头状态变化回调
/// 用户摄像头状态变化回调
/// 成员调用 requestOpenCamera: 或 closeCamera: 接口执行打开/关闭摄像头以及主持人调用 adminCloseUserCamera: 接口执行关闭远端用户摄像头后，当前房间所有成员都会收到该事件通知，注：当房间内已经有成员开启了摄像头，这时进入房间时也会收到该事件通知。
/// - Parameters:
///   - targetUserId: 目标成员标识
///   - cameraState: 视频状态
///   - reason: 发生变化原因
- (void)onUserCameraStateChanged:(NSString *)targetUserId cameraState:(SEADeviceState)cameraState reason:(SEAChangeReason)reason;

#pragma mark 用户麦克风状态变化回调
/// 用户麦克风状态变化回调
/// 成员调用 requestOpenMic: 或 closeMic: 接口执行打开/关闭麦克风以及主持人调用 adminCloseUserMic: 接口执行关闭远端用户麦克风后，当前房间所有成员都会收到该事件通知，注：当房间内已经有成员开启了麦克风，这时进入房间时也会收到该事件通知。
/// - Parameters:
///   - targetUserId: 目标成员标识
///   - micState: 音频状态
///   - reason: 发生变化原因
- (void)onUserMicStateChanged:(NSString *)targetUserId micState:(SEADeviceState)micState reason:(SEAChangeReason)reason;

#pragma mark 用户涂鸦能力禁用状态变化回调
/// 用户涂鸦能力禁用状态变化回调
/// 主持人调用 adminUpdateUserDrawDisabled: 接口对成员执行涂鸦禁用操作后，对应成员会收到该事件通知。
/// - Parameter drawDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)onUserDrawDisabledChanged:(BOOL)drawDisabled userId:(NSString *)userId;

#pragma mark 用户聊天能力禁用状态变化回调
/// 用户聊天能力禁用状态变化回调
/// 主持人调用 adminUpdateUserChatDisabled: 接口对成员执行聊天禁用操作后，对应成员会收到该事件通知。
/// - Parameter chatDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)onUserChatDisabledChanged:(BOOL)chatDisabled userId:(NSString *)userId;

#pragma mark 举手处理结果回调
/// 举手处理结果回调
/// 成员通过 requestHandup: 接口执行请求举手，主持人会收到来自组件的 onRoomHandUpChanged:enable:handupType:() 事件通知；主持人通过 adminConfirmHandup:() 接口执行处理举手后，对应成员会收到该事件通知。
/// - Parameter handupType: 申请类型
/// - Parameter approve: 处理结果
/// - Parameter userId: 处理人标识
- (void)onHandupConfirm:(SEAHandupType)handupType approve:(BOOL)approve userId:(NSString *)userId;

#pragma mark 远端用户加入等候室回调
/// 远端用户加入等候室回调
/// 成员调用 enterRoom: 接口执行加入房间并且该房间开启了等候室功能，当前房间管理员用户将会收到该事件通知。
/// - Parameters:
///   - userId: 成员标识
///   - nickname: 成员昵称
- (void)onRoomUserEnterWaitingRoom:(NSString *)userId nickname:(NSString *)nickname;

#pragma mark 远端用户离开等候室回调
/// 远端用户离开等候室回调
/// 成员调用 exitWaitingRoom: 接口执行离开等候室后，当前房间管理员用户将会收到该事件通知。
/// - Parameters:
///   - userId: 成员标识
///   - nickname: 成员昵称
- (void)onRoomUserExitWaitingRoom:(NSString *)userId nickname:(NSString *)nickname;


#pragma mark - ------------ 消息事件回调 ------------
#pragma mark 收到聊天消息回调
/// 收到聊天消息回调
/// 成员通过 sendRoomChatMessage:() 或者 sendRoomCustomMessage:() 接口执行发送消息后，对应成员会收到该事件通知。
/// - Parameter senderId: 发送者标识
/// - Parameter message: 消息内容
/// - Parameter messageType: 消息类型
- (void)onReceiveChatMessage:(NSString *)senderId message:(NSString *)message messageType:(SEAMessageType)messageType;

#pragma mark 收到系统消息回调
/// 收到系统消息回调
/// - Parameters:
///   - message: 消息内容
///   - messageType: 消息类型
- (void)onReceiveSystemMessage:(NSString *)message messageType:(SEAMessageType)messageType;


#pragma mark - ------------ 云录制事件回调 ------------
#pragma mark 云录制状态变更回调
/// 云录制状态变更回调
/// - Parameters:
///   - recordType: 录制类型
///   - status: 录制状态
///   - errMsg: 错误描述
- (void)onCloudRecordStatusChange:(SEARecordType)recordType status:(SEARecordStatus)status errMsg:(nullable NSString *)errMsg;

#pragma mark 云录制告警回调
/// 云录制告警回调
/// - Parameters:
///   - status: 录制状态
///   - taskId: 任务标识
///   - gateway: 所在网关
///   - alarmAt: 告警时间
///   - alarmBrief: 告警摘要
- (void)onCloudRecordAlarm:(SEARecordStatus)status taskId:(NSString *)taskId gateway:(NSString *)gateway alarmAt:(NSInteger)alarmAt alarmBrief:(nullable NSString *)alarmBrief;


#pragma mark - ------------ 屏幕采集事件回调 ------------
#pragma mark 屏幕共享状态回调
/// 屏幕共享状态回调
/// @param status 状态码
- (void)onScreenRecordStatus:(SEAScreenRecordStatus)status;


#pragma mark - ------------ 音频事件回调 ------------
#pragma mark 音频路由变更回调
/// 音频路由变更回调
/// @param route 音频路由
/// @param previousRoute 变更前的音频路由
- (void)onAudioRouteChange:(SEAAudioRoute)route previousRoute:(SEAAudioRoute)previousRoute;

#pragma mark 远程成员音频状态回调
/// 远程成员音频状态回调
/// @param audioArray 成员音频列表
- (void)onRemoteMemberAudioStatus:(NSArray<SEAStreamAudioModel *> *)audioArray;


#pragma mark - ------------ 流媒体事件回调 ------------
#pragma mark 下行码率自适应状态回调
/// 下行码率自适应状态回调
/// @param userId 用户标识
/// @param state 下行码率自适应状态
- (void)onDownBitrateAdaptiveUserId:(NSString *)userId state:(SEADownBitrateAdaptiveState)state;

#pragma mark 上行码率自适应状态回调
/// 上行码率自适应状态回调
/// @param state 上行码率自适应状态
- (void)onUploadBitrateAdaptiveState:(SEAUploadBitrateAdaptiveState)state;

#pragma mark 下行平均丢包档位变化回调
/// 下行平均丢包档位变化回调
/// @param state 下行平均丢包档位
- (void)onDownLossLevelChangeState:(SEADownLossLevelState)state;

#pragma mark 下行平均丢包率回调
/// 下行平均丢包率回调
/// @param average 下行平均丢包率
- (void)onDownLossRateAverage:(CGFloat)average;

#pragma mark 流媒体发送状态数据回调
/// 流媒体发送状态数据回调
/// @param sendModel 流媒体发送状态数据
- (void)onSendStreamModel:(SEAStreamSendModel *)sendModel;

#pragma mark 流媒体接收状态数据回调
/// 流媒体接收状态数据回调
/// @param receiveArray 流媒体接收状态数据列表
- (void)onReceiveStreamModel:(NSArray <SEAStreamReceiveModel *> *)receiveArray;

#pragma mark 流媒体接收视频流状态变更回调
/// 流媒体接收视频流状态变更回调
/// @param targetUserId 目标成员标识
/// @param streamType 视频流类型
/// @param status 接收状态，YES-超时 NO-恢复
- (void)onReceiveStreamStatusChange:(NSString *)targetUserId streamType:(SEAVideoStreamType)streamType status:(BOOL)status;

#pragma mark 流媒体接收合成流画面状态变更回调
/// 流媒体接收合成流画面状态变更回调
/// @param status 接收状态，YES-超时 NO-恢复
- (void)onReceiveMixtureStreamStatusChange:(BOOL)status;


#pragma mark - ------------ 其它事件回调 ------------
#pragma mark 应用性能使用情况回调
/// 应用性能使用情况回调
/// @param memory 内存占用
/// @param cpuUsage CUP使用率
- (void)onApplicationPerformance:(CGFloat)memory cpuUsage:(CGFloat)cpuUsage;

@end

NS_ASSUME_NONNULL_END
