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

@end

NS_ASSUME_NONNULL_END
