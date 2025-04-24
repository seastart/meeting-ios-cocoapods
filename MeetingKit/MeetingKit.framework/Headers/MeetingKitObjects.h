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

@class SEALayoutViewListCellModel;
@class SEALayoutWatermarkModel;
@class SEALayoutViewListModel;
@class SEALayoutLabelModel;
@class SEALayoutDataModel;
@class SEAUserExtend;
@class SEARoomExtend;

/// 用户数据
@interface SEAUserModel : RTCEngineUserModel

/// 麦克风状态
@property (nonatomic, assign) SEADeviceState micState;
/// 摄像头状态
@property (nonatomic, assign) SEADeviceState cameraState;
/// 共享类型
@property (nonatomic, assign) SEAShareType shareType;
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
/// 是否被踢出
@property (nonatomic, assign) BOOL isKickout;
/// 聊天能力禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL chatDisabled;

/// 扩展信息
@property (nonatomic, copy, nullable) NSString *extendInfo;

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
/// 会议模式
@property (nonatomic, assign) SEAMeetingMode meetingMode;
/// 预约时间(计划开始时间)，单位：秒
@property (nonatomic, assign) NSInteger planTime;
/// 预约时长(计划会议时长)，单位：分钟
@property (nonatomic, assign) NSInteger planDuration;
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
/// 房间共享禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL shareDisabled;
/// 锁定状态，YES-开启 NO-关闭
@property (nonatomic, assign) BOOL locked;

/// 共享类型
@property (nonatomic, assign) SEAShareType shareType;
/// 共享者标识
@property (nonatomic, copy, nullable) NSString *shareUid;
/// 创建者标识
@property (nonatomic, copy) NSString *creator;
/// 主持人标识
@property (nonatomic, copy) NSString *hostUid;
/// 联席主持标识列表
@property (nonatomic, copy, nullable) NSMutableArray <NSString *> *unionHosts;
/// 云录制状态
@property (nonatomic, assign) SEARecordStatus recordStatus;

/// 扩展信息
@property (nonatomic, copy, nullable) NSString *extendInfo;

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


/// 媒体配置参数
@interface SEAMediaConfig : NSObject

/// 回声消除AEC，默认 12
@property (nonatomic, assign) int aec;
/// 自动增益控制AGC，默认 16000
@property (nonatomic, assign) int agc;
/// 音频采样率，默认 48000
@property (nonatomic, assign) int audioSampe;
/// 音频编码格式，默认 OPUS
@property (nonatomic, assign) SEACodecType audioEncode;
/// 音频路由，默认 SEAAudioRouteReceiver
@property (nonatomic, assign) SEAAudioRoute audioRoute;

/// 视频分辨率宽必须是16的倍数 高必须是2的倍数 否则容易出现绿边等问题(已做了兼容)
/// 1080P---1920x1080
/// 720P---1280x720
/// 480P---640x480
/// 180P---320x180
/// 视频分辨率宽，默认 640
@property (nonatomic, assign) int videoWidth;
/// 视频分辨率高，默认 480
@property (nonatomic, assign) int videoHeight;
/// 视频镜像，默认 YES
@property (nonatomic, assign) BOOL videoMirror;

/// 视频帧率，默认 25
@property (nonatomic, assign) int fps;
/// 视频码率，默认 0.9*1024，单位kbps
@property (nonatomic, assign) int bitrate;

/// 是否启用媒体流加密 YES开启 NO关闭，默认 NO
@property (nonatomic, assign) BOOL enableEncrypt;

@end


/// 网络质量控制参数
@interface SEANetworkQosParam : NSObject

/// 接收自适应延迟二档位，默认 500
@property (nonatomic, assign) int secondGear;
/// 接收自适应延迟三档位，默认 1200
@property (nonatomic, assign) int thirdGear;

/// 获取云端音频数据信息周期，默认 500毫秒
@property (nonatomic, assign) float onAudioCycle;

/// 开启硬件解码 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isHardwarede;
/// 开启网络自适应延迟 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isNetworkAdaptive;
/// 开启码率自适应 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isBitrateAdaptive;

/// 网络延时抗抖动等级，默认 SEANetworkQosShakeLevelMedium
@property (nonatomic, assign) SEANetworkQosShakeLevel shakeLevel;

@end


/// 调试模式参数
@interface SEADebugParam : NSObject

/// 远程调试地址
@property (nonatomic, copy, nullable) NSString *debugHost;
/// 保存视频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveVideo;
/// 保存采集音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioCapture;
/// 保存远程音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioReceive;

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
/// 会议模式，默认 SEAMeetingModeNormal
@property (nonatomic, assign) SEAMeetingMode meetingMode;
/// 会议布局
@property (nonatomic, strong) SEALayoutDataModel *layoutData;
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
/// 是否开启录制，默认 YES
@property (nonatomic, assign) BOOL autoRecord;
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
/// 受邀成员标识列表
@property (nonatomic, copy, nullable) NSArray <NSString *> *conferee;
/// 创建者标识
@property (nonatomic, copy) NSString *creator;
/// 参会类型
@property (nonatomic, assign) SEAMeetingAttendType attendType;
/// 会议类型
@property (nonatomic, assign) SEAMeetingType meetingType;
/// 会议模式
@property (nonatomic, assign) SEAMeetingMode meetingMode;
/// 会议布局
@property (nonatomic, strong) SEALayoutDataModel *layoutData;
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
/// 房间共享禁用状态，YES-禁用 NO-不禁用
@property (nonatomic, assign) BOOL shareDisabled;
/// 锁定状态，YES-开启 NO-关闭
@property (nonatomic, assign) BOOL locked;
/// 是否开启录制，YES-开启 NO-关闭
@property (nonatomic, assign) BOOL autoRecord;
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


/// 参会成员对象
@interface SEAMemberModel : NSObject

/// 记录标识
@property (nonatomic, copy) NSString *recordId;
/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 用户昵称
@property (nonatomic, copy) NSString *nickname;
/// 加入时间
@property (nonatomic, assign) NSInteger enterAt;
/// 离开时间
@property (nonatomic, assign) NSInteger exitAt;

@end


/// 参会成员列表对象
@interface SEAMemberListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 参会成员对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAMemberModel *> *listData;

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


/// 邀请设备对象
@interface SEAAgentModel : NSObject

/// 设备ID
@property (nonatomic, copy) NSString *deviceId;
/// 设备名称
@property (nonatomic, copy) NSString *name;
/// 设备类型
@property (nonatomic, assign) SEAAgentType type;
/// 设备状态
@property (nonatomic, assign) SEAAgentStatus status;
/// 设备标识
@property (nonatomic, copy) NSString *contact;
/// 设备备注
@property (nonatomic, copy) NSString *remark;

@end


/// 邀请设备列表对象
@interface SEAAgentListModel : NSObject

/// 数据分页对象
@property (nonatomic, strong) SEASectionModel *meta;
/// 代理设备对象列表
@property (nonatomic, strong, nullable) NSMutableArray <SEAAgentModel *> *listData;

@end


/// 邀请对象
@interface SEAInviteModel : NSObject

/// 设备标识
@property (nonatomic, copy) NSString *contact;
/// 设备类型
@property (nonatomic, assign) SEAAgentType type;

/// 创建邀请数据对象
/// - Parameters:
///   - contact: 设备标识
///   - type: 设备类型
- (instancetype)initWithContact:(NSString *)contact type:(SEAAgentType)type;

@end


/// 布局数据对象
@interface SEALayoutDataModel : NSObject

/// 布局类型，默认 auto
@property (nonatomic, copy) NSString *layout;
/// 是否轮询，默认 NO
@property (nonatomic, assign) BOOL isPolling;

/// 布局水印
@property (nonatomic, strong, nullable) SEALayoutWatermarkModel *watermark;
/// 布局标签
@property (nonatomic, strong, nullable) SEALayoutLabelModel *label;
/// 布局视图列表，即：逻辑块, 包含宫格与用户
@property (nonatomic, copy, nullable) NSArray <SEALayoutViewListModel *> *viewLists;

@end


/// 布局水印对象
@interface SEALayoutWatermarkModel : NSObject

/// 水印类型，默认 1；1-无，2-单排，3-多排
@property (nonatomic, assign) NSInteger type;
/// 字体大小，为0时，表示默认值
@property (nonatomic, assign) CGFloat size;
/// 字体颜色，为空时，表示默认值
@property (nonatomic, copy, nullable) NSString *color;
/// 轮廓颜色, 为空时，表示默认值
@property (nonatomic, copy, nullable) NSString *olColor;
/// 轮廓线宽, 为0时，表示默认值
@property (nonatomic, assign) CGFloat olWidth;

@end


/// 布局标签对象
@interface SEALayoutLabelModel : NSObject

/// 标签类型，默认 LT；字母或组合：L-左，R-右，T-上，B-下
@property (nonatomic, copy) NSString *type;
/// 字体大小，为0时，表示默认值
@property (nonatomic, assign) CGFloat size;
/// 字体颜色，为空时，表示默认值
@property (nonatomic, copy, nullable) NSString *color;
/// 背景颜色, 为空时，表示默认值
@property (nonatomic, copy, nullable) NSString *bgColor;

@end


/// 布局视图列表对象，即：逻辑块, 包含宫格与用户
@interface SEALayoutViewListModel : NSObject

/// 视图列表单元格
@property (nonatomic, copy, nullable) NSArray <SEALayoutViewListCellModel *> *itemLists;
/// 成员标识列表
@property (nonatomic, copy, nullable) NSArray <NSString *> *userIds;

@end


/// 布局视图列表单元格对象
@interface SEALayoutViewListCellModel : NSObject

/// 格子序号，排序规则按HTML中标签的顺序，默认 0
@property (nonatomic, assign) NSInteger index;
/// 是否优先绑定频道内的共享流，默认 NO
@property (nonatomic, assign) BOOL bindShare;
/// 单元格标签
@property (nonatomic, strong, nullable) SEALayoutLabelModel *label;

@end


/// 云录制参数
@interface SEACloudRecordParam : NSObject

/// 录制类型，默认 SEARecordTypeVideo
@property (nonatomic, assign) SEARecordType recordType;
/// 录制文件标题
@property (nonatomic, copy) NSString *title;
/// 录制布局
@property (nonatomic, strong) SEALayoutDataModel *layoutData;

@end


/// 云录制详情对象
@interface SEACloudRecordDetailsModel : NSObject

/// 任务标识
@property (nonatomic, copy) NSString *taskId;
/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 会议号码
@property (nonatomic, copy) NSString *roomNo;
/// 录制文件标题
@property (nonatomic, copy) NSString *title;
/// 操作人标识
@property (nonatomic, copy) NSString *opUid;
/// 操作人名称
@property (nonatomic, copy) NSString *opName;
/// 云录制状态
@property (nonatomic, assign) SEARecordStatus recordStatus;
/// 视频地址
@property (nonatomic, copy) NSString *videoKey;
/// 视频大小
@property (nonatomic, assign) NSInteger videoSize;
/// 录制标签
@property (nonatomic, copy) NSString *tags;
/// 错误描述
@property (nonatomic, copy) NSString *errorDesc;
/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;
/// 更新时间
@property (nonatomic, assign) NSInteger updatedAt;

@end


/// 云录制配置对象
@interface SEACloudRecordConfigModel : NSObject

/// 布局类型
@property (nonatomic, copy) NSString *layout;
/// 水印类型
@property (nonatomic, assign) NSInteger watermarkType;
/// 标签类型
@property (nonatomic, copy) NSString *labelType;
/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;
/// 更新时间
@property (nonatomic, assign) NSInteger updatedAt;

@end


/// 会议提醒对象
@interface SEAMeetingRemindModel : NSObject

/// 会议标识
@property (nonatomic, copy) NSString *meetingId;
/// 房间号码
@property (nonatomic, copy) NSString *roomNo;
/// 会议标题
@property (nonatomic, copy) NSString *title;
/// 创建者昵称
@property (nonatomic, copy) NSString *creatorName;
/// 预约时间
@property (nonatomic, assign) NSInteger planTime;
/// 预约时长，单位：分钟
@property (nonatomic, assign) NSInteger planDuration;

@end


NS_ASSUME_NONNULL_END
