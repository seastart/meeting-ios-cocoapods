//
//  MeetingKitRoomDelegate.h
//  MeetingKit
//
//  Created by SailorGa on 2026/8/11.
//  Copyright © 2026 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<MeetingKit/MeetingKit.h>)
#import <MeetingKit/MeetingKitObjects.h>
#else
#import "MeetingKitObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class MeetingKitRoom;

#pragma mark - MeetingKitRoom 事件回调
/// 单个会议房间的事件回调
/// 所有回调的首个参数都是事件来源房间实例，同时加入多个房间时据此区分事件归属。
@protocol MeetingKitRoomDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ------------ 错误事件回调 ------------
#pragma mark 错误事件回调
/// 错误事件回调
/// 发生不可恢复的错误，这个事件触发一般需要获取新的令牌重新入会。
/// - Parameters:
///   - room: 事件来源房间实例
///   - errCode: 错误码
///   - errMsg: 错误信息
- (void)meetingRoom:(MeetingKitRoom *)room onError:(SEAError)errCode errMsg:(nullable NSString *)errMsg;


#pragma mark - ------------ 连接事件回调 ------------
#pragma mark 开始重连事件回调
/// 开始重连事件回调
/// 收到该事件说明连接出现异常，正在尝试重连，如：网络异常等。
/// - Parameter room: 事件来源房间实例
- (void)meetingRoomOnReconnecting:(MeetingKitRoom *)room;

#pragma mark 重连成功事件回调
/// 重连成功事件回调
/// 当连接恢复时，会收到该事件通知。
/// - Parameter room: 事件来源房间实例
- (void)meetingRoomOnReconnected:(MeetingKitRoom *)room;


#pragma mark - ------------ 我的相关回调 ------------
#pragma mark 进入房间事件回调
/// 进入房间事件回调
/// 调用 enterRoom: 接口执行加入房间操作后，会收到该事件通知，如果遇到错误会通过方法的 onFailed 参数抛出。
/// - Parameters:
///   - room: 事件来源房间实例
///   - meetingId: 会议标识
///   - userId: 用户标识
- (void)meetingRoom:(MeetingKitRoom *)room onEnterRoom:(NSString *)meetingId userId:(NSString *)userId;

#pragma mark 离开房间事件回调
/// 离开房间事件回调
/// 当前用户非主动离开时，会收到该事件通知，如：被主持人踢出房间、会议解散等。
/// - Parameters:
///   - room: 事件来源房间实例
///   - reason: 离开原因
- (void)meetingRoom:(MeetingKitRoom *)room onExitRoom:(SEALeaveReason)reason;

#pragma mark 自己数据更新回调
/// 自己数据更新回调
/// 底层频道内自身数据发生变更时回调，业务通常无需关心，会中状态变更请使用对应的语义化事件。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 用户标识
- (void)meetingRoom:(MeetingKitRoom *)room onUserUpdate:(NSString *)userId;

#pragma mark 请求开启摄像头回调
/// 请求开启摄像头回调
/// 主持人调用 adminRequestUserOpenCamera: 接口执行请求打开成员摄像头后，对应成员会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 请求者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRequestOpenCamera:(NSString *)userId;

#pragma mark 请求开启麦克风回调
/// 请求开启麦克风回调
/// 主持人调用 adminRequestUserOpenMic: 接口执行请求打开成员麦克风后，对应成员会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 请求者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRequestOpenMic:(NSString *)userId;

#pragma mark 请求开启共享回调
/// 请求开启共享回调
/// 主持人调用 adminRequestUserOpenShare: 接口执行请求打开成员共享后，对应成员会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 请求者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRequestOpenShare:(NSString *)userId;

#pragma mark 被管理员移进等候室回调
/// 被管理员移进等候室回调
/// 主持人调用 adminMoveInWaitingRoom: 接口执行将您从会议室移动到等候室后，此时您会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomMoveInWaitingRoom:(NSString *)userId;

#pragma mark 被管理员移进小组会议或主会场回调
/// 被管理员移进小组会议或主会场回调
/// 主持人调用 adminMoveSubMeetingUser: 接口执行小组会议之间移动用户后，此时您会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - fromMeetingId: 原小组会议标识
///   - fromMeetingTitle: 原小组会议标题
///   - toMeetingId: 目标小组会议标识
///   - toMeetingTitle: 目标小组会议标题
- (void)meetingRoom:(MeetingKitRoom *)room onRoomMoveSubMeeting:(NSString *)fromMeetingId fromMeetingTitle:(NSString *)fromMeetingTitle toMeetingId:(NSString *)toMeetingId toMeetingTitle:(NSString *)toMeetingTitle;


#pragma mark - ------------ 房间事件回调 ------------
#pragma mark 房间摄像头禁用状态变更回调
/// 房间摄像头禁用状态变更回调
/// 主持人调用 adminUpdateRoomCameraState: 接口执行更新房间全体禁视频后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter cameraDisabled: 房间视频禁用状态，YES-禁用 NO-不禁用
/// - Parameter selfUnmuteCameraDisabled: 是否禁止自我解除视频状态，YES-禁止 NO-不禁止
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomCameraStateChanged:(BOOL)cameraDisabled selfUnmuteCameraDisabled:(BOOL)selfUnmuteCameraDisabled userId:(NSString *)userId;

#pragma mark 房间麦克风禁用状态变更回调
/// 房间麦克风禁用状态变更回调
/// 主持人调用 adminUpdateRoomMicState: 接口执行更新房间全体禁音频后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter micDisabled: 房间音频禁用状态，YES-禁用 NO-不禁用
/// - Parameter selfUnmuteMicDisabled: 是否禁止自我解除音频状态，YES-禁止 NO-不禁止
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomMicStateChanged:(BOOL)micDisabled selfUnmuteMicDisabled:(BOOL)selfUnmuteMicDisabled userId:(NSString *)userId;

#pragma mark 房间聊天禁用状态变更回调
/// 房间聊天禁用状态变更回调
/// 主持人调用 adminUpdateRoomChatDisabled: 接口执行更新房间聊天禁用状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter chatDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomChatDisabledChanged:(BOOL)chatDisabled userId:(NSString *)userId;

#pragma mark 房间共享禁用状态变更回调
/// 房间共享禁用状态变更回调
/// 主持人调用 adminUpdateRoomShareDisabled: 接口执行更新房间共享禁用状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter shareDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomShareDisabledChanged:(BOOL)shareDisabled userId:(NSString *)userId;

#pragma mark 房间截图禁用状态变更回调
/// 房间截图禁用状态变更回调
/// 主持人调用 adminUpdateRoomScreenshotDisabled: 接口执行更新房间截屏开关状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter screenshotDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomScreenshotDisabledChanged:(BOOL)screenshotDisabled userId:(NSString *)userId;

#pragma mark 房间水印禁用状态变更回调
/// 房间水印禁用状态变更回调
/// 主持人调用 adminUpdateRoomWatermarkDisabled: 接口执行更新房间水印开关状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter watermarkDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomWatermarkDisabledChanged:(BOOL)watermarkDisabled userId:(NSString *)userId;

#pragma mark 房间等候室禁用状态变更回调
/// 房间等候室禁用状态变更回调
/// 主持人调用 adminUpdateWaitingRoomDisabled: 接口执行更新房间等候室禁用状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter waitingRoomDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomWaitingRoomDisabledChanged:(BOOL)waitingRoomDisabled userId:(NSString *)userId;

#pragma mark 房间锁定状态变化回调
/// 房间锁定状态变化回调
/// 主持人调用 adminUpdateRoomLocked: 接口执行更新房间锁定状态后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter locked: 锁定状态，YES-开启 NO-关闭
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomLockedChanged:(BOOL)locked userId:(NSString *)userId;

#pragma mark 房间转移主持人回调
/// 房间转移主持人回调
/// 主持人调用 adminMoveHost: 接口执行主持人转移操作后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 新主持人用户标识
///   - sourceUserId: 原主持人用户标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomMoveHost:(NSString *)userId sourceUserId:(NSString *)sourceUserId;

#pragma mark 共享开始回调
/// 共享开始回调
/// 成员调用 requestShare: 接口执行请求开启共享后，如果服务允许此用户开启共享操作，当前房间所有成员都会收到该事件通知，注：如果当前房间正在共享，后续加入的成员也会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter userId: 共享成员标识
/// - Parameter shareType: 共享类型
- (void)meetingRoom:(MeetingKitRoom *)room onRoomShareStart:(NSString *)userId shareType:(SEAShareType)shareType;

#pragma mark 共享结束回调
/// 共享结束回调
/// 成员调用 stopShare: 接口执行关闭共享后，当前房间所有成员都会收到该事件通知，注：如果共享成员未结束共享直接执行退出操作，此时其他成员也会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter userId: 共享成员标识
/// - Parameter shareType: 共享类型
- (void)meetingRoom:(MeetingKitRoom *)room onRoomShareStop:(NSString *)userId shareType:(SEAShareType)shareType;

#pragma mark 主持人结束房间共享回调
/// 主持人结束房间共享回调
/// 主持人调用 adminStopRoomShare: 接口执行关闭共享后，当前房间所有成员都会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter userId: 共享成员标识
/// - Parameter shareType: 共享类型
- (void)meetingRoom:(MeetingKitRoom *)room onAdminRoomShareStop:(NSString *)userId shareType:(SEAShareType)shareType;

#pragma mark 房间成员举手状态变化回调
/// 房间成员举手状态变化回调
/// 成员调用 requestHandup: 接口执行请求举手后，拥有管理权限的成员会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter userId: 成员标识
/// - Parameter enable: 举手状态，YES-申请举手 NO-取消举手
/// - Parameter handupType: 举手申请类型
- (void)meetingRoom:(MeetingKitRoom *)room onRoomHandUpChanged:(NSString *)userId enable:(BOOL)enable handupType:(SEAHandupType)handupType;

#pragma mark 房间讨论组开始回调
/// 房间讨论组开始回调
/// 主持人调用 adminStartSubMeeting: 接口执行开始小组会议后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - meetingId: 会议标识
///   - title: 小组名称
///   - conferee: 参会成员
- (void)meetingRoom:(MeetingKitRoom *)room onRoomSubMeetingStart:(NSString *)meetingId title:(NSString *)title conferee:(nullable NSArray <NSString *> *)conferee;

#pragma mark 房间讨论组结束回调
/// 房间讨论组结束回调
/// 主持人调用 adminStopSubMeeting: 接口执行结束小组会议后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - parentMid: 上级会议标识
- (void)meetingRoom:(MeetingKitRoom *)room onRoomSubMeetingStop:(NSString *)parentMid;

#pragma mark 房间会议标题变化回调
/// 房间会议标题变化回调
/// - Parameters:
///   - room: 事件来源房间实例
///   - title: 会议标题
- (void)meetingRoom:(MeetingKitRoom *)room onRoomMeetingTitleChanged:(NSString *)title;


#pragma mark - ------------ 用户事件回调 ------------
#pragma mark 远端用户加入房间回调
/// 远端用户加入房间回调
/// 成员调用 enterRoom: 接口执行加入房间后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 成员标识
- (void)meetingRoom:(MeetingKitRoom *)room onUserEnter:(NSString *)userId;

#pragma mark 远端用户离开房间回调
/// 远端用户离开房间回调
/// 成员调用 exitRoom: 接口执行离开房间后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 成员标识
- (void)meetingRoom:(MeetingKitRoom *)room onUserExit:(NSString *)userId;

#pragma mark 用户昵称变化回调
/// 用户昵称变化回调
/// 成员调用 updateName: 接口执行更新昵称或者主持人调用 adminUpdateNickname: 接口执行更新用户昵称后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - targetUserId: 目标成员标识
///   - nickname: 用户昵称
- (void)meetingRoom:(MeetingKitRoom *)room onUserNameChanged:(NSString *)targetUserId nickname:(NSString *)nickname;

#pragma mark 用户角色变化回调
/// 用户角色变化回调
/// 主持人调用 adminUpdateUserRole: 接口执行更新用户角色后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - targetUserId: 目标成员标识
///   - userRole: 用户角色
- (void)meetingRoom:(MeetingKitRoom *)room onUserRoleChanged:(NSString *)targetUserId userRole:(SEAUserRole)userRole;

#pragma mark 用户摄像头状态变化回调
/// 用户摄像头状态变化回调
/// 成员调用 requestOpenCamera: 或 closeCamera: 接口执行打开/关闭摄像头以及主持人调用 adminCloseUserCamera: 接口执行关闭远端用户摄像头后，当前房间所有成员都会收到该事件通知，注：当房间内已经有成员开启了摄像头，这时进入房间时也会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - targetUserId: 目标成员标识
///   - cameraState: 视频状态
///   - reason: 发生变化原因
- (void)meetingRoom:(MeetingKitRoom *)room onUserCameraStateChanged:(NSString *)targetUserId cameraState:(SEADeviceState)cameraState reason:(SEAChangeReason)reason;

#pragma mark 用户麦克风状态变化回调
/// 用户麦克风状态变化回调
/// 成员调用 requestOpenMic: 或 closeMic: 接口执行打开/关闭麦克风以及主持人调用 adminCloseUserMic: 接口执行关闭远端用户麦克风后，当前房间所有成员都会收到该事件通知，注：当房间内已经有成员开启了麦克风，这时进入房间时也会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - targetUserId: 目标成员标识
///   - micState: 音频状态
///   - reason: 发生变化原因
- (void)meetingRoom:(MeetingKitRoom *)room onUserMicStateChanged:(NSString *)targetUserId micState:(SEADeviceState)micState reason:(SEAChangeReason)reason;

#pragma mark 用户涂鸦能力禁用状态变化回调
/// 用户涂鸦能力禁用状态变化回调
/// 主持人调用 adminUpdateUserDrawDisabled: 接口对成员执行涂鸦禁用操作后，对应成员会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter drawDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onUserDrawDisabledChanged:(BOOL)drawDisabled userId:(NSString *)userId;

#pragma mark 用户聊天能力禁用状态变化回调
/// 用户聊天能力禁用状态变化回调
/// 主持人调用 adminUpdateUserChatDisabled: 接口对成员执行聊天禁用操作后，对应成员会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter chatDisabled: 禁用状态，YES-禁用 NO-不禁用
/// - Parameter userId: 操作者标识
- (void)meetingRoom:(MeetingKitRoom *)room onUserChatDisabledChanged:(BOOL)chatDisabled userId:(NSString *)userId;

#pragma mark 举手处理结果回调
/// 举手处理结果回调
/// 成员通过 requestHandup: 接口执行请求举手，主持人会收到来自组件的 meetingRoom:onRoomHandUpChanged:enable:handupType:() 事件通知；主持人通过 adminConfirmHandup:() 接口执行处理举手后，对应成员会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter handupType: 申请类型
/// - Parameter approve: 处理结果
/// - Parameter userId: 处理人标识
- (void)meetingRoom:(MeetingKitRoom *)room onHandupConfirm:(SEAHandupType)handupType approve:(BOOL)approve userId:(NSString *)userId;

#pragma mark 远端用户加入等候室回调
/// 远端用户加入等候室回调
/// 成员调用 enterRoom: 接口执行加入房间并且该房间开启了等候室功能，当前房间管理员用户将会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 成员标识
///   - nickname: 成员昵称
- (void)meetingRoom:(MeetingKitRoom *)room onRoomUserEnterWaitingRoom:(NSString *)userId nickname:(NSString *)nickname;

#pragma mark 远端用户离开等候室回调
/// 远端用户离开等候室回调
/// 成员调用 exitWaitingRoom: 接口执行离开等候室后，当前房间管理员用户将会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 成员标识
///   - nickname: 成员昵称
- (void)meetingRoom:(MeetingKitRoom *)room onRoomUserExitWaitingRoom:(NSString *)userId nickname:(NSString *)nickname;


#pragma mark - ------------ 消息事件回调 ------------
#pragma mark 收到聊天消息回调
/// 收到聊天消息回调
/// 成员通过 sendRoomChatMessage:() 或者 sendRoomCustomMessage:() 接口执行发送消息后，对应成员会收到该事件通知。
/// - Parameter room: 事件来源房间实例
/// - Parameter senderId: 发送者标识
/// - Parameter message: 消息内容
/// - Parameter messageType: 消息类型
- (void)meetingRoom:(MeetingKitRoom *)room onReceiveChatMessage:(NSString *)senderId message:(NSString *)message messageType:(SEAMessageType)messageType;

#pragma mark 收到系统消息回调
/// 收到系统消息回调
/// - Parameters:
///   - room: 事件来源房间实例
///   - message: 消息内容
///   - messageType: 消息类型
- (void)meetingRoom:(MeetingKitRoom *)room onReceiveSystemMessage:(NSString *)message messageType:(SEAMessageType)messageType;

#pragma mark 收到房间自定义消息回调
/// 收到房间自定义消息回调
/// 组件已解析的会中事件会通过对应的语义化回调抛出，该回调透传全部原始频道消息，供业务层处理自定义扩展的 action。
/// - Parameters:
///   - room: 事件来源房间实例
///   - content: 消息内容
///   - action: 消息标识
///   - userId: 发送者标识
///   - sessionId: 会话标识
///   - nickname: 发送者昵称
- (void)meetingRoom:(MeetingKitRoom *)room onReceiveCustomMessage:(NSString *)content action:(NSString *)action userId:(nullable NSString *)userId sessionId:(nullable NSString *)sessionId nickname:(nullable NSString *)nickname;


#pragma mark - ------------ 云录制事件回调 ------------
#pragma mark 云录制状态变更回调
/// 云录制状态变更回调
/// - Parameters:
///   - room: 事件来源房间实例
///   - recordType: 录制类型
///   - status: 录制状态
///   - errMsg: 错误描述
- (void)meetingRoom:(MeetingKitRoom *)room onCloudRecordStatusChange:(SEARecordType)recordType status:(SEARecordStatus)status errMsg:(nullable NSString *)errMsg;

#pragma mark 云录制告警回调
/// 云录制告警回调
/// - Parameters:
///   - room: 事件来源房间实例
///   - status: 录制状态
///   - taskId: 任务标识
///   - gateway: 所在网关
///   - alarmAt: 告警时间
///   - alarmBrief: 告警摘要
- (void)meetingRoom:(MeetingKitRoom *)room onCloudRecordAlarm:(SEARecordStatus)status taskId:(NSString *)taskId gateway:(NSString *)gateway alarmAt:(NSInteger)alarmAt alarmBrief:(nullable NSString *)alarmBrief;


#pragma mark - ------------ 屏幕采集事件回调 ------------
#pragma mark 屏幕共享状态回调
/// 屏幕共享状态回调
/// @param room 事件来源房间实例
/// @param status 状态码
- (void)meetingRoom:(MeetingKitRoom *)room onScreenRecordStatus:(SEAScreenRecordStatus)status;


#pragma mark - ------------ 音频事件回调 ------------
#pragma mark 远程成员音频状态回调
/// 远程成员音频状态回调
/// @param room 事件来源房间实例
/// @param audioArray 成员音频列表
- (void)meetingRoom:(MeetingKitRoom *)room onRemoteMemberAudioStatus:(NSArray<SEAStreamAudioModel *> *)audioArray;


#pragma mark - ------------ 流媒体事件回调 ------------
#pragma mark 下行码率自适应状态回调
/// 下行码率自适应状态回调
/// @param room 事件来源房间实例
/// @param userId 用户标识
/// @param state 下行码率自适应状态
- (void)meetingRoom:(MeetingKitRoom *)room onDownBitrateAdaptiveUserId:(NSString *)userId state:(SEADownBitrateAdaptiveState)state;

#pragma mark 上行码率自适应状态回调
/// 上行码率自适应状态回调
/// @param room 事件来源房间实例
/// @param state 上行码率自适应状态
- (void)meetingRoom:(MeetingKitRoom *)room onUploadBitrateAdaptiveState:(SEAUploadBitrateAdaptiveState)state;

#pragma mark 下行平均丢包档位变化回调
/// 下行平均丢包档位变化回调
/// @param room 事件来源房间实例
/// @param state 下行平均丢包档位
- (void)meetingRoom:(MeetingKitRoom *)room onDownLossLevelChangeState:(SEADownLossLevelState)state;

#pragma mark 下行平均丢包率回调
/// 下行平均丢包率回调
/// @param room 事件来源房间实例
/// @param average 下行平均丢包率
- (void)meetingRoom:(MeetingKitRoom *)room onDownLossRateAverage:(CGFloat)average;

#pragma mark 流媒体发送状态数据回调
/// 流媒体发送状态数据回调
/// @param room 事件来源房间实例
/// @param sendModel 流媒体发送状态数据
- (void)meetingRoom:(MeetingKitRoom *)room onSendStreamModel:(SEAStreamSendModel *)sendModel;

#pragma mark 流媒体接收状态数据回调
/// 流媒体接收状态数据回调
/// @param room 事件来源房间实例
/// @param receiveArray 流媒体接收状态数据列表
- (void)meetingRoom:(MeetingKitRoom *)room onReceiveStreamModel:(NSArray <SEAStreamReceiveModel *> *)receiveArray;

#pragma mark 流媒体上行质量数据回调
/// 流媒体上行质量数据回调
/// @param room 事件来源房间实例
/// @param qualityModel 流媒体质量数据
- (void)meetingRoom:(MeetingKitRoom *)room onSendQualityModel:(SEAStreamQualityModel *)qualityModel;

#pragma mark 流媒体下行质量数据回调
/// 流媒体下行质量数据回调
/// @param room 事件来源房间实例
/// @param qualityModel 流媒体质量数据
- (void)meetingRoom:(MeetingKitRoom *)room onReceiveQualityModel:(SEAStreamQualityModel *)qualityModel;

#pragma mark 流媒体接收视频流状态变更回调
/// 流媒体接收视频流状态变更回调
/// @param room 事件来源房间实例
/// @param targetUserId 目标成员标识
/// @param streamType 视频流类型
/// @param status 接收状态，YES-超时 NO-恢复
- (void)meetingRoom:(MeetingKitRoom *)room onReceiveStreamStatusChange:(NSString *)targetUserId streamType:(SEAVideoStreamType)streamType status:(BOOL)status;

#pragma mark 流媒体接收合成流画面状态变更回调
/// 流媒体接收合成流画面状态变更回调
/// @param room 事件来源房间实例
/// @param status 接收状态，YES-超时 NO-恢复
- (void)meetingRoom:(MeetingKitRoom *)room onReceiveMixtureStreamStatusChange:(BOOL)status;

#pragma mark 流媒体接收转推流状态变更回调
/// 流媒体接收转推流状态变更回调
/// @param room 事件来源房间实例
/// @param streamName 转推流名
/// @param status 接收状态，YES-超时 NO-恢复
- (void)meetingRoom:(MeetingKitRoom *)room onReceiveRetweetStreamStatusChange:(NSString *)streamName status:(BOOL)status;


#pragma mark - ------------ 其它事件回调 ------------
#pragma mark 扩展事件回调
/// 扩展事件回调
/// @param room 事件来源房间实例
/// @param event 事件类型
/// @param content 数据内容
- (void)meetingRoom:(MeetingKitRoom *)room onExtendedEvents:(NSString *)event content:(NSString *)content;


#pragma mark - ------------ 签到事件回调 ------------
#pragma mark 签到活动回调
/// 签到活动回调
/// 主持人创建签到活动后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 发起人标识
///   - epoch: 签到轮次
///   - beginAt: 开始时间
///   - dur: 签到时长，单位：分钟，0为不限时
///   - endAt: 结束时间
///   - desc: 签到描述
- (void)meetingRoom:(MeetingKitRoom *)room onSignInActivity:(NSString *)userId epoch:(NSInteger)epoch beginAt:(NSInteger)beginAt dur:(NSInteger)dur endAt:(NSInteger)endAt desc:(nullable NSString *)desc;

#pragma mark 签到结束回调
/// 签到结束回调
/// 主持人结束签到活动后，当前房间所有成员都会收到该事件通知。
/// - Parameters:
///   - room: 事件来源房间实例
///   - userId: 发起人标识
///   - epoch: 签到轮次
- (void)meetingRoom:(MeetingKitRoom *)room onSignInFinish:(NSString *)userId epoch:(NSInteger)epoch;

@end

NS_ASSUME_NONNULL_END
