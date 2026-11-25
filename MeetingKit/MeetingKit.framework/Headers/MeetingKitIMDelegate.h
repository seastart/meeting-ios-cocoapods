//
//  MeetingKitIMDelegate.h
//  MeetingKit
//
//  Created by SailorGa on 2024/9/24.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MeetingKit;

#pragma mark - MeetingKit 事件回调
@protocol MeetingKitIMDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ------------ 连接事件回调 ------------
#pragma mark 连接成功回调
/// 连接成功回调
/// 调用 enableImWithDelegate:() 接口执行启用即时通讯操作后，会收到该事件通知，如果遇到错误会通过 onImDisconnected:() 事件抛出。
/// - Parameters:
///   - userId: 用户标识
///   - sessionId: 会话标识
- (void)onImConnectSucceed:(NSString *)userId sessionId:(NSString *)sessionId;

#pragma mark 开始重连回调
/// 开始重连回调
/// 收到该事件说明连接出现异常，正在尝试重连，如：网络异常等。
- (void)onImReconnecting;

#pragma mark 重连成功回调
/// 重连成功回调
/// 当连接恢复时，会收到该事件通知。
- (void)onImReconnected;

#pragma mark 连接断开回调
/// 连接断开回调
/// 发生不可恢复的错误或者被动断开连接，如果是错误事件需要重新获取令牌
/// @param reason 离开原因
/// @param errCode 错误码
/// @param errMsg 错误信息
- (void)onImDisconnected:(SEAImDisconnectReason)reason errCode:(SEAError)errCode errMsg:(nullable NSString *)errMsg;


#pragma mark - ------------ 消息相关回调 ------------
#pragma mark 接收消息回调
/// 接收消息回调
/// 调用后台接口执行发送消息后，指定成员会收到该事件通知。
/// @param content 消息内容
/// @param action 消息标识
/// @param userId 用户标识
/// @param sessionId 会话标识
/// @param nickname 用户昵称
- (void)onImMessage:(NSString *)content action:(NSString *)action userId:(nullable NSString *)userId sessionId:(nullable NSString *)sessionId nickname:(nullable NSString *)nickname;

#pragma mark 会议即将开始回调
/// 会议即将开始回调
/// @param remindModel 会议提醒
- (void)onMeetingRemind:(SEAMeetingRemindModel *)remindModel;


#pragma mark - ------------ 通话相关回调 ------------
#pragma mark 通话请求的回调
/// 通话请求的回调
/// 收到一个新的通话请求回调，被叫会收到，您可以通过监听这个事件，来决定是否显示通话接听界面。
/// @param callerId 主叫标识
/// @param nickname 主叫昵称
/// @param roomNo 房间号码
/// @param title 会议标题
/// @note 实现了带 meetingId / forceJoin 的 onCallReceived:nickname:roomNo:title:meetingId:forceJoin: 后，不再回调本方法。
- (void)onCallReceived:(NSString *)callerId nickname:(nullable NSString *)nickname roomNo:(NSString *)roomNo title:(NSString *)title;

#pragma mark 通话请求的回调（含会议标识与强制入会标记）
/// 通话请求的回调（含会议标识与强制入会标记）
/// 收到一个新的通话请求回调，被叫会收到。实现本方法后不再回调 onCallReceived:nickname:roomNo:title:。
/// forceJoin 为 YES 表示管理员通过服务端接口 meet-admin/call-users 传了 force_join=true，要求被叫直接入会：
/// 建议不弹接听界面，直接进入目标会议；若正在其它会议中，先离开当前会议再进入。
/// @param callerId 主叫标识
/// @param nickname 主叫昵称
/// @param roomNo 房间号码
/// @param title 会议标题
/// @param meetingId 会议标识
/// @param forceJoin 是否强制入会，缺省为 NO
- (void)onCallReceived:(NSString *)callerId nickname:(nullable NSString *)nickname roomNo:(NSString *)roomNo title:(NSString *)title meetingId:(nullable NSString *)meetingId forceJoin:(BOOL)forceJoin;


#pragma mark - ------------ 等候室相关回调 ------------
#pragma mark 被管理员从等候室移入会议室回调
/// 被管理员从等候室移入会议室回调
/// 主持人调用 adminMoveOutWaitingRoom: 接口执行将您从等候室移动到会议室后，此时您会收到该事件通知。
/// - Parameters:
///   - meetingId: 会议标识
///   - title: 会议标题
- (void)onWaitingRoomMoveInRoom:(NSString *)meetingId title:(nullable NSString *)title;


#pragma mark - ------------ 分组讨论相关回调 ------------
#pragma mark 小组会议请求帮助回调
/// 小组会议请求帮助回调
/// 小组会议成员调用 subMeetingHelp:onFailed: 接口执行请求管理员帮助后，此时管理员会收到该事件通知。
/// - Parameters:
///   - parentMid: 上级会议标识
///   - meetingId: 小组会议标识
///   - title: 小组会议标题
- (void)onSubMeetingAskingHelp:(NSString *)parentMid meetingId:(NSString *)meetingId title:(nullable NSString *)title;

@end

NS_ASSUME_NONNULL_END
