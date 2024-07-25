//
//  MeetingKitScreenDelegate.h
//  MeetingKit
//
//  Created by SailorGa on 2024/7/17.
//  Copyright © 2024 SailorGa. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class MeetingKit;

#pragma mark - 屏幕共享回调
@protocol MeetingKitScreenDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 录屏完成回调
/// 录屏完成回调
/// @param engine 回调实例
/// @param reason 结束原因
- (void)broadcastFinished:(MeetingKit *)engine reason:(NSString *)reason;

@end

NS_ASSUME_NONNULL_END
