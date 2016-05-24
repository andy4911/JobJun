//
//  Authorization.h
//  Joker
//
//  Created by Apple on 16/5/14.
//  Copyright © 2016年 猫儿出墙. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JJCommon.h"

typedef NS_ENUM(int, JKSNSType){
    // 新浪微博
    JJSNSSinaWeibo  =1,
    
    // QQ
    JJSNSQQ         =2,
    
    // 微信
    JJSNSWeiXin      =3,
};

@interface JJAuthorizationManager : NSObject
/**
 *  单例创建
 */
+ (instancetype)manager;

/*
 上次登录若未登出，本次应自动登录
 @return 自动登录成功return YES，自动登录失败return NO需自己登录(因上次登出或此次登录出现问题)
 */
- (BOOL)automaticLogon;

/*
 第三方登录，不存在账号会自动创建
 @param plateform 第三方登录的平台
 @param block The block to execute. The block should have the following argument signature: (Bool  success, NSError *error)
 */
- (void)thirdPartySignInWithPlateform:(JKSNSType)plateform callBack:(JJBooleanResultBlock)block;

/*
 账号登录
 @param block The block to execute. The block should have the following argument signature: (Bool  success, NSError *error)
 @success 这个参数请无视
*/
- (void)signInWithUserName:(NSString *)name password:(NSString *)password callBack:(JJBooleanResultBlock)block;

- (void)registerWithUserName:(NSString *)name andPassword:(NSString *)password callBack:(JJBooleanResultBlock)block;

//登出
- (void)LoginOut;

//修改密码
//需要处于登录状态
//@param block The block to execute. The block should have the following argument signature: (id object, NSError *error)
- (void)changPasswordFrom:(NSString *)oldPassword to:(NSString *)newPassword callBack:(JJIdResultBlock)block;

/**
 *  根据一个或多个userID获取相应AVUser
 *
 *  @param userIDs 包含userID的array
 *  @param block
 */
- (void)findUsersByIDs:(NSArray *)userIDs callBack:(JJArrayResultBlock)block;

/**
 *  根据name的一部分获取相应AVUser
 *
 *  @param name
 *  @param block
 */
- (void)findUsersByPartname:(NSString *)name callBack:(JJArrayResultBlock)block;

@end
