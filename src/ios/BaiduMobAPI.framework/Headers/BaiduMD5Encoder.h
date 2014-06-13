//
//  YKRC4.h
//  codedemo
//
//  Created by baidu on 14-5-19.
//  Copyright (c) 2014年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BaiduMD5Encoder : NSObject
+(NSData*)encode:(NSData*)sourceData withKey:(NSString*)keyString;
@end
