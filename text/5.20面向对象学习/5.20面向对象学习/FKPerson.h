//
//  main.m
//  5.20面向对象学习
//
//  Created by 王天亮 on 2019/5/20.
//  Copyright © 2019 王天亮. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface FKPerson : NSObject {
    NSString * _name;
        int _age;
    }
- (void) setName:(NSString *) name andAge: (int) age;
- (void) say: (NSString *) content;
-(NSString *) info;
+ (void) foo;
@end

