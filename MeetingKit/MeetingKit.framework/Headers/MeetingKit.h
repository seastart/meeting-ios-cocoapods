//
//  MeetingKit.h
//  MeetingKit
//
//  Created by SailorGa on 2023/12/26.
//  Copyright © 2023 SailorGa. All rights reserved.
//

#import <RTCEngineKit/RTCEngineKit.h>
#import <Foundation/Foundation.h>

#if __has_include(<MeetingKit/MeetingKit.h>)
#import <MeetingKit/MeetingKitDefine.h>
#import <MeetingKit/MeetingKitObjects.h>
#import <MeetingKit/MeetingKitDelegate.h>
#import <MeetingKit/MeetingKitIMDelegate.h>
#import <MeetingKit/MeetingKitScreenDelegate.h>
#else
#import "MeetingKitDefine.h"
#import "MeetingKitObjects.h"
#import "MeetingKitDelegate.h"
#import "MeetingKitIMDelegate.h"
#import "MeetingKitScreenDelegate.h"
#endif

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MeetingKit
@interface MeetingKit : NSObject

+ (instancetype)new __attribute__((unavailable("use sharedInstance instead.")));
- (instancetype)init __attribute__((unavailable("use sharedInstance instead.")));


#pragma mark - ------------ 核心基础接口 ------------
#pragma mark 创建 MeetingKit 实例
/// 创建 MeetingKit 实例
+ (MeetingKit *)sharedInstance;

#pragma mark 会议引擎版本
///  会议引擎版本
- (NSString *)version;

#pragma mark 设置事件回调
/// 设置事件回调，您可以通过 MeetingKitDelegate 获得各类事件通知（例如：错误码，远端用户进房间，音视频状态参数等）
/// @param delegate 委托实例
- (void)addDelegate:(id <MeetingKitDelegate>)delegate;

#pragma mark 登录接口
/// 登录接口，您需要先初始化用户信息后才能进入房间，并进行一系列的操作
/// - Parameters:
///   - token: 会议令牌
///   - appGroup: 组标识符
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)loginWithToken:(NSString *)token appGroup:(NSString *)appGroup onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 退出登录接口
/// 退出登录接口，会有主动离开房间操作、销毁资源
- (void)logout;


#pragma mark - ------------ 即时通讯接口 ------------
#pragma mark 启用即时通讯
/// 启用即时通讯
/// - Parameter delegate: 委托代理
/// - Parameter onSuccess: 成功回调
/// - Parameter onFailed: 失败回调
- (void)enableImWithDelegate:(nullable id<MeetingKitIMDelegate>)delegate onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 停用即时通讯
/// 停用即时通讯
- (void)disableIm;


#pragma mark - ------------ 会议操作接口 ------------
#pragma mark 获取会议列表
/// 获取会议列表
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getMeetingList:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取更多会议列表
/// 获取更多会议列表
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getMoreMeetingList:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取历史会议列表
/// 获取历史会议列表
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getHistoryMeetingList:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取更多历史会议列表
/// 获取更多历史会议列表
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getMoreHistoryMeetingList:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取会议详情
/// 获取会议详情
/// - Parameters:
///   - meetingId: 会议标识
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getMeetingDetailsWithMeetingId:(NSString *)meetingId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取参会人员列表
/// 获取参会人员列表
/// - Parameters:
///   - meetingId: 会议标识
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getParticipantListsWithMeetingId:(NSString *)meetingId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取更多参会人员列表
/// 获取更多参会人员列表
/// - Parameters:
///   - meetingId: 会议标识
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getMoreParticipantListsWithMeetingId:(NSString *)meetingId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 请求取消会议
/// 请求取消会议
/// - Parameters:
///   - meetingId: 会议标识
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)requestCancelMeetingWithMeetingId:(NSString *)meetingId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;


#pragma mark - ------------ 用户操作接口 ------------
#pragma mark 获取设备列表
/// 获取设备列表
/// - Parameters:
///   - typesList: 设备类型列表
///   - keyword: 关键词
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
///   注：上述设备类型列表为需要获取的目标设备类型构成的数组参数，设备类型可参看 SEAAgentType 声明定义。
- (void)getAgentList:(NSArray <NSNumber *> *)typesList keyword:(nullable NSString *)keyword onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取更多设备列表
/// 获取更多设备列表
/// - Parameters:
///   - typesList: 设备类型列表
///   - keyword: 关键词
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
///   注：上述设备类型列表为需要获取的目标设备类型构成的数组参数，设备类型可参看 SEAAgentType 声明定义。
- (void)getMoreAgentList:(NSArray <NSNumber *> *)typesList keyword:(nullable NSString *)keyword onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 创建房间
/// 创建房间
/// @param params 创建参数
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)createRoom:(SEAMeetingParam *)params onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 修改房间
/// 修改房间
/// @param params 房间参数
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)updateRoom:(SEAMeetingParam *)params onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 加入房间
/// 加入房间
/// @param params 加入会议参数
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)enterRoom:(SEAMeetingEnterParam *)params onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 离开房间
/// 离开房间
/// @param onSuccess 成功回调
- (void)exitRoom:(nullable SEASuccessBlock)onSuccess;

#pragma mark 用户更新昵称
/// 用户更新昵称
/// @param username 新昵称
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)updateName:(NSString *)username onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户请求打开摄像头
/// 用户请求打开摄像头
/// @param frontCamera 摄像头方向，YES-前置摄像头 NO-后置摄像头
/// @param view 承载视频画面的控件
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)requestOpenCamera:(BOOL)frontCamera view:(VIEW_CLASS *)view onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户请求打开麦克风
/// 用户请求打开麦克风
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)requestOpenMic:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户关闭摄像头
/// 用户关闭摄像头
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)closeCamera:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户关闭麦克风
/// 用户关闭麦克风
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)closeMic:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户请求开启共享
/// 用户请求开启共享
/// @param shareType 共享类型
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)requestShare:(SEAShareType)shareType onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户关闭共享
/// 用户关闭共享
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)stopShare:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户发送聊天消息
/// 用户发送聊天消息
/// @param message 聊天消息
/// @param messageType 消息类型
/// @param targetId 目标标识，为空时表示全房间接收
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)sendRoomChatMessage:(NSString *)message messageType:(SEAMessageType)messageType targetId:(nullable NSString *)targetId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户发送自定义消息
/// 用户发送自定义消息
/// @param message 消息内容
/// @param targetId 目标标识，为空时表示全房间接收
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)sendRoomCustomMessage:(NSString *)message targetId:(nullable NSString *)targetId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取聊天列表
/// 获取聊天列表
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getChatList:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取更多聊天列表
/// 获取更多聊天列表
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getMoreChatList:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户请求举手
/// 用户请求举手
/// @param handupType 申请类型
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)requestHandup:(SEAHandupType)handupType onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 用户取消举手
/// 用户取消举手
/// @param handupType 申请类型
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)cancelHandup:(SEAHandupType)handupType onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 回复同意打开摄像头请求
/// 回复同意打开摄像头请求
/// @param targetId 目标标识，请求或同意您开启摄像头请求的管理者标识
/// @param frontCamera 摄像头方向，YES-前置摄像头 NO-后置摄像头
/// @param view 承载视频画面的控件
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)confirmAdminOpenCamera:(NSString *)targetId frontCamera:(BOOL)frontCamera view:(VIEW_CLASS *)view onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 回复同意打开麦克风请求
/// 回复同意打开麦克风请求
/// @param targetId 目标标识，请求或同意您开启摄像头请求的管理者标识
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)confirmAdminOpenMic:(NSString *)targetId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 更新本地摄像头的预览画面
/// 更新本地摄像头的预览画面
/// @param view 承载视频画面的控件
- (void)updateLocalView:(VIEW_CLASS *)view;

#pragma mark 切换摄像头
/// 切换摄像头
- (void)switchCamera;

#pragma mark 设置扬声器状态
/// 设置扬声器状态
/// - Parameter enabled: YES-开启 NO-关闭
- (void)switchSpeaker:(BOOL)enabled;

#pragma mark 切换音频路由
/// 切换音频路由
/// - Parameter route: 音频路由
- (void)switchAudioRoute:(SEAAudioRoute)route;

#pragma mark 获取当前音频路由
/// 获取当前音频路由
- (SEAAudioRoute)currentAudioRoute;

#pragma mark 是否存在有线耳机设备
/// 是否存在有线耳机设备
- (BOOL)headphoneDeviceAvailable;

#pragma mark 是否存在蓝牙耳机设备
/// 是否存在蓝牙耳机设备
- (BOOL)bluetoothDeviceAvailable;

#pragma mark 订阅远端用户的视频流，并绑定视频渲染控件
/// 订阅远端用户的视频流，并绑定视频渲染控件
/// @param userId 指定远端用户标识
/// @param streamType 视频流类型
/// @param view 承载视频画面的渲染控件
- (void)startRemoteView:(NSString *)userId streamType:(SEAVideoStreamType)streamType view:(VIEW_CLASS *)view;

#pragma mark 停止订阅远端用户的视频流，并释放渲染控件
/// 停止订阅远端用户的视频流，并释放渲染控件
/// @param userId 指定远端用户标识
/// @param streamType 视频流类型
- (void)stopRemoteView:(NSString *)userId streamType:(SEAVideoStreamType)streamType;

#pragma mark 停止订阅指定远端用户的所有视频流，并释放全部渲染资源
/// 停止订阅指定远端用户的所有视频流，并释放全部渲染资源
/// @param userId 指定远端用户标识
- (void)stopAllRemoteViewWithUserId:(NSString *)userId;

#pragma mark 订阅远端合成画面视频流，并绑定视频渲染控件
/// 订阅远端合成画面视频流，并绑定视频渲染控件
/// @param view 承载视频画面的渲染控件
- (void)startRemoteMixture:(VIEW_CLASS *)view;

#pragma mark 停止订阅远端合成画面视频流，并释放渲染控件
/// 停止订阅远端合成画面视频流，并释放渲染控件
- (void)stopRemoteMixture;


#pragma mark - ------------ 屏幕共享相关接口函数 ------------
#pragma mark 关闭屏幕录制
/// 关闭屏幕录制
- (void)stopScreenRecord;

#pragma mark 录屏启动方法
/// 录屏启动方法
/// 需要在 RPBroadcastSampleHandler 的实现类中的 broadcastStartedWithSetupInfo 方法中调用
/// - Parameters:
///   - appGroup: Application Group Identifier
///   - delegate: 回调对象
- (void)broadcastStartedWithAppGroup:(NSString *)appGroup delegate:(id<MeetingKitScreenDelegate>)delegate;

#pragma mark 媒体数据(音视频)发送方法
/// 媒体数据(音视频)发送方法
/// - Parameters:
///   - sampleBuffer: 系统回调的视频或音频帧
///   - sampleBufferType: 媒体输入类型
/// 注释：sampleBufferType 当前支持 RPSampleBufferTypeVideo 和 RPSampleBufferTypeAudioApp 类型的数据帧处理；
/// RPSampleBufferTypeAudioMic 不支持，可以在宿主 App 处理麦克风采集数据。
- (void)sendSampleBuffer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType;


#pragma mark - ------------ 主持人操作接口 ------------
#pragma mark 主持人解散房间
/// 主持人解散房间
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminDestroyRoom:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新房间全体禁视频
/// 主持人更新房间全体禁视频
/// @param cameraDisabled 房间视频禁用状态，YES-禁用 NO-不禁用
/// @param selfUnmuteCameraDisabled 是否禁止自我解除视频状态，YES-禁止 NO-不禁止
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateRoomCameraState:(BOOL)cameraDisabled selfUnmuteCameraDisabled:(BOOL)selfUnmuteCameraDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新房间全体禁音频
/// 主持人更新房间全体禁音频
/// @param micDisabled 房间音频禁用状态，YES-禁用 NO-不禁用
/// @param selfUnmuteMicDisabled 是否禁止自我解除音频状态，YES-禁止 NO-不禁止
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateRoomMicState:(BOOL)micDisabled selfUnmuteMicDisabled:(BOOL)selfUnmuteMicDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新房间是否禁止自我解除视频状态
/// 主持人更新房间是否禁止自我解除视频状态
/// @param selfUnmuteCameraDisabled 是否禁止自我解除视频状态，YES-禁止 NO-不禁止
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateRoomSelfUnmuteCameraDisabled:(BOOL)selfUnmuteCameraDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新房间是否禁止自我解除音频状态
/// 主持人更新房间是否禁止自我解除音频状态
/// @param selfUnmuteMicDisabled 是否禁止自我解除音频状态，YES-禁止 NO-不禁止
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateRoomSelfUnmuteMicDisabled:(BOOL)selfUnmuteMicDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新房间聊天禁用状态
/// 主持人更新房间聊天禁用状态
/// @param chatDisabled 禁用状态，YES-禁用 NO-不禁用
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateRoomChatDisabled:(BOOL)chatDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新房间截屏开关状态
/// 主持人更新房间截屏开关状态
/// @param screenshotDisabled 禁用状态，YES-禁用 NO-不禁用
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateRoomScreenshotDisabled:(BOOL)screenshotDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新房间水印开关状态
/// 主持人更新房间水印开关状态
/// @param watermarkDisabled 水印状态，YES-开启 NO-关闭
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateRoomWatermarkDisabled:(BOOL)watermarkDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新房间锁定状态
/// 主持人更新房间锁定状态
/// @param locked 锁定状态，YES-开启 NO-关闭
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateRoomLocked:(BOOL)locked onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新用户昵称
/// 主持人更新用户昵称
/// @param userId 用户标识
/// @param nickname 用户昵称
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateNickname:(NSString *)userId nickname:(NSString *)nickname onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新用户角色
/// 主持人更新用户角色
/// @param userId 用户标识
/// @param userRole 用户角色
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateUserRole:(NSString *)userId userRole:(SEAUserRole)userRole onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人转移
/// 主持人转移
/// @param userId 用户标识
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminMoveHost:(NSString *)userId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新用户聊天状态
/// 主持人更新用户聊天状态
/// @param userId 用户标识
/// @param chatDisabled 禁用状态，YES-禁用 NO-不禁用
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateUserChatDisabled:(NSString *)userId chatDisabled:(BOOL)chatDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人请求打开成员摄像头
/// 主持人请求打开成员摄像头
/// @param userId 用户标识
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminRequestUserOpenCamera:(NSString *)userId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人关闭远端用户摄像头
/// 主持人关闭远端用户摄像头
/// @param userId 用户标识
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminCloseUserCamera:(NSString *)userId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人请求打开成员麦克风
/// 主持人请求打开成员麦克风
/// @param userId 用户标识
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminRequestUserOpenMic:(NSString *)userId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人关闭远端用户麦克风
/// 主持人关闭远端用户麦克风
/// @param userId 用户标识
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminCloseUserMic:(NSString *)userId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人踢出成员
/// 主持人踢出成员
/// @param userId 用户标识
/// @param joinDisabled 是否禁止再次加入房间，YES-禁止 NO-不禁止
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminKickUserOut:(NSString *)userId joinDisabled:(BOOL)joinDisabled onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人关闭共享
/// 主持人关闭共享
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminStopRoomShare:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人处理举手
/// 主持人处理举手
/// @param userId 用户标识
/// @param handupType 举手申请类型
/// @param approve 处理举手申请，YES-同意 NO-拒绝
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminConfirmHandup:(NSString *)userId handupType:(SEAHandupType)handupType approve:(BOOL)approve onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人更新受邀成员
/// 主持人更新受邀成员
/// @param conferee 成员标识列表
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminUpdateConferee:(NSArray <NSString *> *)conferee onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 主持人邀请设备入会
/// 主持人邀请设备入会
/// @param invitesList 邀请列表
/// @param onSuccess 成功回调
/// @param onFailed 失败回调
- (void)adminInviteAgent:(NSArray <SEAInviteModel *> *)invitesList onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;


#pragma mark - ------------ 云录制相关接口 ------------
#pragma mark 获取云录制详情
/// 获取云录制详情
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getCloudRecordDetail:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 获取云录制配置
/// 获取云录制配置
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getCloudRecordConfig:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 开启云录制
/// 开启云录制
/// - Parameters:
///   - params: 云录制参数
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)startCloudRecord:(SEACloudRecordParam *)params onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 停止云录制
/// 停止云录制
/// - Parameters:
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)stopCloudRecord:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;


#pragma mark - ------------ 数据管理相关接口 ------------
#pragma mark 获取当前账户信息
/// 获取当前账户信息
- (SEAUserModel *)getMySelf;

#pragma mark 获取成员信息
/// 获取成员信息
/// @param userId 用户编号
- (SEAUserModel *)findMemberWithUserId:(NSString *)userId;

#pragma mark 获取成员列表
/// 获取成员列表
- (NSArray<SEAUserModel *> *)getRemoteUsers;

#pragma mark 获取房间详情数据
/// 获取房间详情数据
- (SEARoomModel *)getRoomDetails;

#pragma mark 获取画板地址
/// 获取画板地址
- (NSString *)getDrawingHost;


#pragma mark - ------------ 调试相关接口 ------------
#pragma mark 设置调试参数
/// 设置调试参数
/// - Parameter param: 调试参数
- (void)setDebugParam:(SEADebugParam *)param;

@end

NS_ASSUME_NONNULL_END
