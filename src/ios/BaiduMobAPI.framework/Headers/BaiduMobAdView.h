//
//  BaiduMobAdView.h
//  BaiduMobAdSdk
//
//  Created by jaygao on 11-9-6.
//  Copyright 2011年 Baidu. All rights reserved.
//
//  Baidu Mobads SDK Version 3.0
//

#import <UIKit/UIKit.h>
#import "BaiduMobAdDelegateProtocol.h"

#define kBaiduAdViewSizeDefaultWidth 320
#define kBaiduAdViewSizeDefaultHeight 48

#define kBaiduAdViewBanner320x48 CGSizeMake(320, 48)
#define kBaiduAdViewBanner468x60 CGSizeMake(468, 60)
#define kBaiduAdViewBanner728x90 CGSizeMake(728, 90)

#define kBaiduAdViewSquareBanner300x250 CGSizeMake(300, 250)
#define kBaiduAdViewSquareBanner600x500 CGSizeMake(600, 500)

/**
 *  投放广告的视图接口,更多信息请查看[百度移动联盟主页](http://munion.baidu.com)
 */
/**
 *  广告类型
 * 0 banner广告
 * 2 前贴片 BaiduMobAdViewTypeVABeforeVideo
 * 3 暂停视图 BaiduMobAdViewTypeVAPause
 * 4 切换视图 BaiduMobAdViewTypeVASwitchView
 */
typedef enum _BaiduMobAdViewType {
    BaiduMobAdViewTypeBanner = 0,
    BaiduMobAdViewTypeVABeforeVideo = 2,
    BaiduMobAdViewTypeVAPause = 3,
    BaiduMobAdViewTypeVASwitchView = 4,
} BaiduMobAdViewType;

@interface BaiduMobAdView : UIView {
    @private
    id<BaiduMobAdViewDelegate> delegate_;
    
    UIColor* textColor_;
    UIColor* backgroundColor_;
    CGFloat alpha_;
    BaiduMobAdViewType adType_;
    NSString* aduTag;
}

///---------------------------------------------------------------------------------------
/// @name 属性
///---------------------------------------------------------------------------------------

/**
 *  委托对象
 */
@property (nonatomic ,assign) id<BaiduMobAdViewDelegate>  delegate;

/**
 *  设置／获取当前广告（文字）的文本颜色
 */
@property (nonatomic, retain) UIColor* textColor;

/**
 *  设置／获取需要展示的广告类型
 */
@property (nonatomic) BaiduMobAdViewType AdType;

/**
 *  设置/获取广告位id
 */
@property (nonatomic,copy) NSString* AdUnitTag;


/**
 *  SDK版本
 */
@property (nonatomic, readonly) NSString* Version;


/**
 *  开始广告展示请求,会触发所有资源的重新加载，推荐初始化以后调用一次
 */
- (void) start;

/**
 *  关闭视频广告的方法，如果用户可以点击回退进入上一界面，
 *  请在dealloc方法中调用该方法，以防止广告不被计费
 */
- (void) close;


@end

