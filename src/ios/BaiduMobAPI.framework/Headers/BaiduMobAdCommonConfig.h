//
//  BaiduMobAdCommonConfig.h
//  BaiduMobAdSdk
//
//  Created by dengjinxiang on 13-8-22.
//
//

#ifndef BaiduMobAdSdk_BaiduMobAdCommonConfig_h
#define BaiduMobAdSdk_BaiduMobAdCommonConfig_h


/**
 *  性别类型
 */
typedef enum
{
	BaiduMobAdMale=0,
	BaiduMobAdFeMale=1,
    BaiduMobAdSexUnknown=2,
} BaiduMobAdUserGender;

/**
 *  广告展示失败类型枚举
 */
typedef enum _BaiduMobFailReason
{
    BaiduMobFailReason_NOAD = 0,
    // 没有推广返回
    BaiduMobFailReason_EXCEPTION
    //网络或其它异常
} BaiduMobFailReason;

#endif