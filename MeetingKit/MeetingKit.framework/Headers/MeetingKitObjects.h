//
//  MeetingKitObjects.h
//  MeetingKit
//
//  Created by SailorGa on 2024/2/20.
//  Copyright © 2024 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RTCEngineKit/RTCEngineKit.h>

#if __has_include(<MeetingKit/MeetingKit.h>)
#import <MeetingKit/MeetingKitDefine.h>
#else
#import "MeetingKitDefine.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class SEAUserExtend;
@class SEARoomExtend;

/// 用户数据
@interface SEAUserModel : RTCEngineUserModel

/// 扩展属性
@property (nonatomic, strong) SEAUserExtend *extend;

@end


/// 房间数据
@interface SEARoomModel : RTCEngineChannelModel

/// 扩展属性
@property (nonatomic, strong) SEARoomExtend *extend;

@end


/// 用户数据扩展属性
@interface SEAUserExtend : NSObject

/// 参会角色
@property (nonatomic, assign) SEAUserRole role;
/// 参会头像
@property (nonatomic, copy) NSString *avatar;
/// 麦克风状态
@property (nonatomic, assign) SEADeviceState micState;
/// 摄像头状态
@property (nonatomic, assign) SEADeviceState cameraState;
/// 共享状态
@property (nonatomic, assign) SEAShareType shareType;
/// 是否被踢出
@property (nonatomic, assign) BOOL isKickout;
/// 聊天能力禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL chatDisabled;

/// 扩展信息
@property (nonatomic, assign) id extend;

@end


/// 房间数据扩展属性
@interface SEARoomExtend : NSObject

/// 会议标识(频道名称)
@property (nonatomic, copy) NSString *meetingId;
/// 房间号码
@property (nonatomic, copy) NSString *roomNo;
/// 会议标题
@property (nonatomic, copy) NSString *title;
/// 会议说明
@property (nonatomic, copy) NSString *content;
/// 会议类型
@property (nonatomic, assign) SEAMeetingType meetingType;
/// 开始时间
@property (nonatomic, assign) NSInteger beginTime;
/// 结束时间
@property (nonatomic, assign) NSInteger endTime;
/// 入会静音状态
@property (nonatomic, assign) SEAMeetingMuteState entryMutePolicy;
/// 房间水印禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL watermarkDisabled;
/// 房间截屏禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL screenshotDisabled;
/// 聊天能力禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL chatDisabled;
/// 麦克风禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL micDisabled;
/// 摄像头禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL cameraDisabled;
/// 是否禁止自我解除音频状态，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL selfUnmuteMicDisabled;
/// 是否禁止自我解除视频状态，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL selfUnmuteCameraDisabled;
/// 锁定状态，YES-开启 NO-关闭
@property (nonatomic, assign) BOOL locked;

/// 共享类型
@property (nonatomic, assign) SEAShareType shareType;
/// 共享者标识
@property (nonatomic, copy) NSString *shareUid;
/// 创建者标识
@property (nonatomic, copy) NSString *creator;
/// 主持人标识
@property (nonatomic, copy) NSString *hostUid;
/// 联席主持标识列表
@property (nonatomic, copy, nullable) NSMutableArray <NSString *> *unionHosts;

/// 扩展信息
@property (nonatomic, assign) id extend;

@end


/// 用户信息
@interface SEAUserInfo : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 设备标识
@property (nonatomic, copy) NSString *deviceId;
/// 设备类型
@property (nonatomic, assign) SEADeviceType deviceType;
/// 过期时间
@property (nonatomic, assign) NSInteger expAt;

@end


/// 会议参数
@interface SEAMeetingParam : NSObject

/// 会议标识，修改会议信息时必填
@property (nonatomic, copy, nullable) NSString *meetingId;
/// 会议号码
@property (nonatomic, copy, nullable) NSString *roomNo;
/// 会议标题
@property (nonatomic, copy) NSString *title;
/// 会议说明
@property (nonatomic, copy, nullable) NSString *content;
/// 会议密码
@property (nonatomic, copy, nullable) NSString *password;
/// 参会成员标识列表
@property (nonatomic, copy, nullable) NSArray <NSString *> *conferee;
/// 参会类型，默认 SEAMeetingAttendTypeNormal
@property (nonatomic, assign) SEAMeetingAttendType attendType;
/// 会议类型，默认 SEAMeetingTypeInitiate
@property (nonatomic, assign) SEAMeetingType meetingType;
/// 计划开始时间，SEAMeetingTypeSchedule 会议必填
@property (nonatomic, assign) NSInteger planTime;
/// 计划会议时长(单位分钟)，SEAMeetingTypeSchedule 会议必填
@property (nonatomic, assign) NSInteger planDuration;
/// 入会静音状态，默认 SEAMeetingMuteState3
@property (nonatomic, assign) SEAMeetingMuteState entryMutePolicy;
/// 水印是否关闭，默认 YES
@property (nonatomic, assign) BOOL watermarkDisabled;
/// 截屏是否禁止，默认 NO
@property (nonatomic, assign) BOOL screenshotDisabled;
/// 聊天是否禁止，默认 NO
@property (nonatomic, assign) BOOL chatDisabled;
/// 扩展信息
@property (nonatomic, copy, nullable) NSString *extendInfo;

@end


/// 加入会议参数
@interface SEAMeetingEnterParam : NSObject

/// 会议号码
@property (nonatomic, copy) NSString *roomNo;
/// 会议密码
@property (nonatomic, copy, nullable) NSString *password;
/// 参会昵称
@property (nonatomic, copy, nullable) NSString *nickname;
/// 参会头像
@property (nonatomic, copy, nullable) NSString *avatar;
/// 扩展信息
@property (nonatomic, copy, nullable) NSString *extendInfo;

/// 默认音频路由，默认 RTCAudioRouteReceiver
@property (nonatomic, assign) SEAAudioRoute route;

@end


/// 数据分页对象
@interface SEASectionModel : NSObject

/// 当前页码
@property (nonatomic, assign) NSInteger currentPage;
/// 总页数
@property (nonatomic, assign) NSInteger pageCount;
/// 每页数据条数
@property (nonatomic, assign) NSInteger perPage;
/// 总数据条数
@property (nonatomic, assign) NSInteger totalCount;

@end


/// 聊天消息对象
@interface SEAChatModel : NSObject

/// 消息标识
@property (nonatomic, copy) NSString *messageId;
/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 消息内容
@property (nonatomic, copy) NSString *message;
/// 消息类型
@property (nonatomic, assign) SEAMessageType messageType;

/// 发送者标识
@property (nonatomic, copy) NSString *senderId;
/// 发送者昵称
@property (nonatomic, copy) NSString *senderName;

/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;

@end


/// 聊天消息列表对象
@interface SEAChatListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 聊天消息对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAChatModel *> *listData;

@end


/// 会议信息对象
@interface SEAMeetingModel : NSObject

/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 会议号码
@property (nonatomic, copy) NSString *roomNo;
/// 会议标题
@property (nonatomic, copy) NSString *title;
/// 会议说明
@property (nonatomic, copy, nullable) NSString *content;
/// 参会成员标识列表
@property (nonatomic, copy, nullable) NSArray <NSString *> *conferee;
/// 创建者标识
@property (nonatomic, copy) NSString *creator;
/// 参会类型
@property (nonatomic, assign) SEAMeetingAttendType attendType;
/// 会议类型
@property (nonatomic, assign) SEAMeetingType meetingType;
/// 会议状态
@property (nonatomic, assign) SEAMeetingStatus meetingStatus;
/// 计划开始时间
@property (nonatomic, assign) NSInteger planTime;
/// 计划会议时长，单位：分钟
@property (nonatomic, assign) NSInteger planDuration;

/// 实际开始时间
@property (nonatomic, assign) NSInteger beginTime;
/// 实际开始时间
@property (nonatomic, assign) NSInteger endTime;
/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;

/// 入会静音状态
@property (nonatomic, assign) SEAMeetingMuteState entryMutePolicy;
/// 房间水印禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL watermarkDisabled;
/// 房间截屏禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL screenshotDisabled;
/// 聊天能力禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL chatDisabled;
/// 麦克风禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL micDisabled;
/// 摄像头禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL cameraDisabled;
/// 是否禁止自我解除音频状态，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL selfUnmuteMicDisabled;
/// 是否禁止自我解除视频状态，YES-禁止 NO-不禁止
@property (nonatomic, assign) BOOL selfUnmuteCameraDisabled;
/// 锁定状态，YES-开启 NO-关闭
@property (nonatomic, assign) BOOL locked;
/// 在线人数
@property (nonatomic, assign) NSInteger onlineNum;
/// 共享类型
@property (nonatomic, assign) SEAShareType shareType;

@end


/// 会议列表对象
@interface SEAMeetingListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 会议信息对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAMeetingModel *> *listData;

@end


/// 流媒体音频信息
@interface SEAStreamAudioModel : RTCStreamAudioModel

@end


/// 流媒体发送状态数据
@interface SEAStreamSendModel : RTCStreamSendModel

@end


/// 流媒体接收状态数据
@interface SEAStreamReceiveModel : RTCStreamReceiveModel

@end


NS_ASSUME_NONNULL_END
