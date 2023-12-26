//
//  MeetingKit.h
//  MeetingKit
//
//  Created by SailorGa on 2023/12/26.
//  Copyright © 2023 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - MeetingKit
@interface MeetingKit : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedEngine instead or +sharedEngineWithConfig")));
- (instancetype)init __attribute__((unavailable("Use +sharedEngine instead or +sharedEngineWithConfig")));

#pragma mark - ------------ Core Service ------------
#pragma mark 获取会议引擎实例
/// 获取会议引擎实例
+ (MeetingKit *)sharedEngine;

@end

NS_ASSUME_NONNULL_END
