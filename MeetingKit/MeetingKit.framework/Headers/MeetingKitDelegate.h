//
//  MeetingKitDelegate.h
//  MeetingKit
//
//  Created by SailorGa on 2024/2/20.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<MeetingKit/MeetingKit.h>)
#import <MeetingKit/MeetingKitDefine.h>
#else
#import "MeetingKitDefine.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class MeetingKit;

#pragma mark - MeetingKit 事件回调
/// 全局组件事件回调
/// 该协议只承载账号级与设备级的全局事件，房间内的事件请实现 MeetingKitRoomDelegate。
@protocol MeetingKitDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ------------ 音频事件回调 ------------
#pragma mark 音频路由变更回调
/// 音频路由变更回调
/// 音频路由对应进程内唯一的 AVAudioSession，属设备级事件，与加入了几个房间无关。
/// @param route 音频路由
/// @param previousRoute 变更前的音频路由
- (void)onAudioRouteChange:(SEAAudioRoute)route previousRoute:(SEAAudioRoute)previousRoute;


#pragma mark - ------------ 其它事件回调 ------------
#pragma mark 应用性能使用情况回调
/// 应用性能使用情况回调
/// 统计的是宿主进程整体占用，属进程级事件。
/// @param memory 内存占用
/// @param cpuUsage CUP使用率
- (void)onApplicationPerformance:(CGFloat)memory cpuUsage:(CGFloat)cpuUsage;

@end

NS_ASSUME_NONNULL_END
