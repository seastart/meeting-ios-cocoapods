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

#pragma mark SDK 语言
/// SDK 语言（BCP 47 语言标签，如 @"zh-CN"、@"en"），nil 或空串 = 跟随系统语言（[NSLocale preferredLanguages].firstObject）
/// 只影响请求后端时的 Accept-Language 请求头：后端据此返回对应语言的业务错误文案（1000–99999 后端码的 message）；
/// SDK 自身产生的报错 message 一律英文，不随语言变化。进程级生效，不随登录 / 登出重置，建议在登录前设置。
/// 设置时会同时设置底层 RTCEngineKit.language，会议层与 RTC 层用同一语言（需搭配支持 language 的 RTCEngineKit，3.2.0 及以前不支持、RTC 层请求不带语言）。
@property (nonatomic, copy, nullable) NSString *language;

/// 当前实际生效的语言：language 已设置则为它，否则为系统语言（取不到时为 @"zh"）
@property (nonatomic, copy, readonly) NSString *currentLanguage;

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


#pragma mark - ------------ 资源相关接口 ------------
#pragma mark 预签名上传
/// 预签名上传：向会议层申请一个直传存储的上传地址
/// 成功回调的 data 为 SEAPresignedPutObjectModel（url / key / ext）；调用方随后自己用 HTTP PUT 把文件二进制传到 url，
/// 请求头 Content-Type 为 application/octet-stream（不是 multipart）。业务里保存 / 发送的应当是 key，
/// 需要下载时再用 presignedGetObjectWithResKey:resId: 现换下载地址（url 带签名，约 2 小时过期，不要缓存）。
/// 部署关闭了文件功能时失败回调 SEAErrorMeetingApiFileDisabled(2125)。
/// 聊天文件消息约定：上传后以 SEAMessageTypeFile 发送 JSON 字符串 {"key":"<key>","name":"原始文件名","size":"1.20MB"}
/// - Parameters:
///   - type: 资源类型，聊天文件传 SEAResourceTypeChat
///   - meetingId: 会议标识
///   - ext: 文件扩展名，必填、不带点（如 @"pdf"），没有扩展名时传 @"bin"
///   - onSuccess: 成功回调，data 为 SEAPresignedPutObjectModel
///   - onFailed: 失败回调
- (void)presignedPutObject:(SEAResourceType)type meetingId:(NSString *)meetingId ext:(NSString *)ext onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;

#pragma mark 预签名下载
/// 预签名下载：用资源标识换取一个临时下载地址
/// 每次下载前现换，不要缓存返回的地址（带签名，约 2 小时过期）
/// - Parameters:
///   - resKey: 资源标识（预签名上传返回的 key，聊天文件消息里的 key），必填；为空时直接失败回调 SEAErrorMeetingInvalidArgument(203012)
///   - resId: 资源记录 ID，预留参数：resId 目前后端不支持，请传 resKey（传了也会和 resKey 一起带给后端，但后端只认 res_key）
///   - onSuccess: 成功回调，data 为下载地址 NSString
///   - onFailed: 失败回调
- (void)presignedGetObjectWithResKey:(nullable NSString *)resKey resId:(nullable NSString *)resId onSuccess:(nullable SEASuccessBlock)onSuccess onFailed:(nullable SEAFailedBlock)onFailed;


#pragma mark - ------------ 会前网络检测相关接口 ------------
#pragma mark 开始会前网络检测
/// 开始会前网络检测
/// 入会前调用，不需要进入房间、不需要连接 RTC；逐项检测网络权限、网络连接情况、最大传输单元、域名解析、服务器连接情况，
/// 全部正常时约 5 秒内完成，最长约 10 秒。检测逻辑与 RTC 层一致，会议层在 server 项里多一个会议接口子检查 meeting_api，
/// 会议接口不通时 server 记 fail、reason 为 meeting_api_unreachable（server 已因 RTC 子检查失败时保留 RTC 的原因）；
/// 未登录时拿不到会议接口地址，meeting_api 记 skipped、reason 为 server_info_unavailable
/// @param params 检测参数；已登录时可传 nil（从登录信息里取应用标识与服务器地址），未登录时须传 appId + serverUrl 或 token
/// @param onItem 单项完成回调（主线程），每完成一项回调一次
/// @param completion 检测完成回调（主线程）：正常结束 result 非空、errorCode 为 SEAErrorOK；
///        被 cancelNetworkCheck（或退出登录）取消时 result 为 nil、errorCode 为 SEAErrorUserCancelled(103026)
/// @return SEAErrorOK 表示已开始；未登录且未传参返回 SEAErrorMeetingNotLoggedIn(203001)；
///         其余错误透传 RTC 层码：已有检测在进行中 SEAErrorConflict(103005)，参数非法或令牌解不开 SEAErrorInvalidArgs(103031)
- (SEAError)networkCheck:(nullable SEANetworkCheckParams *)params onItem:(nullable SEANetworkCheckItemBlock)onItem completion:(nullable SEANetworkCheckCompletionBlock)completion;

#pragma mark 取消会前网络检测
/// 取消会前网络检测：不再回调 onItem，完成回调以 SEAErrorUserCancelled(103026) 结束；可立即发起新的检测
- (void)cancelNetworkCheck;


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


#pragma mark - ------------ 虚拟背景相关接口 ------------
/// 虚拟背景作用于进程内唯一的共享摄像头采集链路，属设备级能力，设置会同时作用于全部房间。
/// 会中切换摄像头、断线重连后会议层会自动把当前配置重新应用，调用方不必自己补。

#pragma mark 装载虚拟背景组件
/// 装载虚拟背景组件
/// 建议在进入房间、打开摄像头之前调用；装载后需要再调 enabledVirtualBackground: 才会生效
/// - Parameter modelPath: 人像分割模型(selfie_segmenter_fixed.onnx)文件路径，
///   传 nil 使用 SDK 内置的那一份
- (SEAError)installVirtualBackground:(nullable NSString *)modelPath;

#pragma mark 卸载虚拟背景组件
/// 卸载虚拟背景组件
- (void)uninstallVirtualBackground;

#pragma mark 虚拟背景功能开关
/// 虚拟背景功能开关
/// - Parameter enabled: YES-开启 NO-关闭(关闭即零开销直通，不跑推理)
- (SEAError)enabledVirtualBackground:(BOOL)enabled;

#pragma mark 设置背景虚化
/// 设置背景虚化
/// 与 setVirtualBackgroundImage: 互斥，后调用的生效
/// - Parameter level: 虚化等级，取值范围 1-10，默认 5
- (void)setVirtualBackgroundBlur:(NSInteger)level;

#pragma mark 设置背景替换
/// 设置背景替换
/// 与 setVirtualBackgroundBlur: 互斥，后调用的生效
/// - Parameter image: 背景图片，按 cover 裁剪不拉伸
- (void)setVirtualBackgroundImage:(nullable UIImage *)image;

#pragma mark 设置分割推理间隔
/// 设置分割推理间隔
/// 给调用方按机型下发的性能档，不建议暴露给终端用户
/// - Parameter interval: 分割每 N 帧跑一次(合成仍每帧跑)，默认 1，低端机可调大保帧率
- (void)setVirtualBackgroundInferenceInterval:(NSInteger)interval;

#pragma mark 设置蒙版对齐
/// 设置蒙版对齐
/// 消挥手时的错位拖影，代价是画面更新率降到蒙版率；
/// interval == 1 时开与不开没有任何区别，它只在调大推理间隔后才起作用
/// - Parameter enabled: YES-开启 NO-关闭，默认 NO
- (void)setVirtualBackgroundMaskSync:(BOOL)enabled;

#pragma mark 获取虚拟背景开启状态
/// 获取虚拟背景开启状态
- (BOOL)isVirtualBackgroundEnabled;


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
