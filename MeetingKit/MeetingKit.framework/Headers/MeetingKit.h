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
#import <MeetingKit/MeetingKitRoom.h>
#import <MeetingKit/MeetingKitDefine.h>
#import <MeetingKit/MeetingKitObjects.h>
#import <MeetingKit/MeetingKitDelegate.h>
#import <MeetingKit/MeetingKitIMDelegate.h>
#import <MeetingKit/MeetingKitScreenDelegate.h>
#else
#import "MeetingKitRoom.h"
#import "MeetingKitDefine.h"
#import "MeetingKitObjects.h"
#import "MeetingKitDelegate.h"
#import "MeetingKitIMDelegate.h"
#import "MeetingKitScreenDelegate.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class MeetingKitRoom;
@protocol MeetingKitRoomDelegate;

#pragma mark - MeetingKit
/// 会议组件全局入口
/// 该单例只承载账号级与设备级能力：登录、即时通讯、本地采集与预览、音频路由、屏幕采集进程侧接入，以及会议的查询与预约。
/// 会中的一切操作与事件都属于房间维度，通过 -createRoomWithDelegate: 创建 MeetingKitRoom 实例进行；
/// 同一账号可以同时创建并加入多个房间，各房间的媒体与业务状态相互独立。
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
/// 设置事件回调，您可以通过 MeetingKitDelegate 获得全局事件通知（音频路由变更、应用性能数据）
/// 房间内的事件请实现 MeetingKitRoomDelegate 并在创建房间时传入
/// @param delegate 委托实例
- (void)addDelegate:(id <MeetingKitDelegate>)delegate;

#pragma mark 创建会议房间
/// 创建独立会议房间实例
/// 每次调用都会返回一个新的房间实例，实例之间互不影响；调用房间的 exitRoom: 后该实例即失效，需要重新创建
/// @param delegate 房间事件代理
- (nullable MeetingKitRoom *)createRoomWithDelegate:(nullable id<MeetingKitRoomDelegate>)delegate;

#pragma mark 获取活跃会议房间
/// 获取当前已经加入的会议房间列表
- (NSArray<MeetingKitRoom *> *)getRooms;

#pragma mark 登录接口
/// 登录接口，您需要先初始化用户信息后才能进入房间，并进行一系列的操作
/// - Parameters:
///   - token: 会议令牌
///   - appGroup: 组标识符
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)loginWithToken:(NSString *)token appGroup:(NSString *)appGroup onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 自定义日志配置登录接口
/// 登录接口，您需要先初始化用户信息后才能进入房间，并进行一系列的操作
/// - Parameters:
///   - token: 会议令牌
///   - appGroup: 组标识符
///   - logConfig: 日志配置
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)loginWithToken:(NSString *)token appGroup:(NSString *)appGroup logConfig:(SEALogConfig *)logConfig onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 退出登录接口
/// 退出登录接口，会离开并销毁全部房间实例、销毁资源
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

#pragma mark 获取会议详情
/// 获取会议详情
/// - Parameters:
///   - roomNo: 房间号码
///   - onSuccess: 成功回调
///   - onFailed: 失败回调
- (void)getMeetingDetailsWithRoomNo:(NSString *)roomNo onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

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

#pragma mark 创建房间
/// 创建房间
/// 该接口只在服务端创建会议，不会加入房间；加入房间请使用 MeetingKitRoom 的 enterRoom: 接口
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


#pragma mark - ------------ 本地采集相关接口 ------------
#pragma mark 更新本地摄像头的预览画面
/// 更新本地摄像头的预览画面
/// 摄像头在 iOS 上本就是单路硬件，采集与预览属全局能力，多个房间共用同一路采集
/// @param view 承载视频画面的控件
- (void)updateLocalView:(VIEW_CLASS *)view;

#pragma mark 切换摄像头
/// 切换摄像头
- (void)switchCamera;

#pragma mark 设置前置摄像头本地预览镜像偏好
/// 设置前置摄像头本地预览镜像偏好
/// 仅作用于本地预览画面，不影响推流数据；后置摄像头恒不镜像，切换摄像头后自动应用
/// - Parameter mirror: YES-前置摄像头镜像 NO-前置摄像头不镜像
- (void)setLocalPreviewMirror:(BOOL)mirror;

#pragma mark 获取当前摄像头方向
/// 获取当前摄像头方向
/// - Returns: 摄像头方向，SEACameraDirectionFront-前置 SEACameraDirectionBack-后置
- (SEACameraDirection)currentCameraDirection;


#pragma mark - ------------ 音频路由相关接口 ------------
#pragma mark 切换音频路由
/// 切换音频路由
/// 音频路由对应进程内唯一的 AVAudioSession，属设备级能力，切换会同时作用于全部房间
/// 同步请求成功不代表系统实际路由已经完成切换，最终结果以currentAudioRoute和onAudioRouteChange回调为准
/// - Parameter route: 音频路由
- (void)switchAudioRoute:(SEAAudioRoute)route;

#pragma mark 获取系统当前实际音频路由
/// 获取系统当前实际音频路由
- (SEAAudioRoute)currentAudioRoute;

#pragma mark 是否存在有线耳机设备
/// 是否存在有线耳机设备
- (BOOL)headphoneDeviceAvailable;

#pragma mark 是否存在蓝牙耳机设备
/// 是否存在蓝牙耳机设备
- (BOOL)bluetoothDeviceAvailable;


#pragma mark - ------------ 屏幕共享相关接口函数 ------------
#pragma mark 录屏启动方法
/// 录屏启动方法
/// ReplayKit 采集运行在独立的 Broadcast Upload Extension 进程，属进程级接入点
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

@end

NS_ASSUME_NONNULL_END
