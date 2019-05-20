//
//  5.m
//  5.20面向对象学习
//
//  Created by 王天亮 on 2019/5/20.
//  Copyright © 2019 王天亮. All rights reserved.
//

#import "FKPerson.h"
#import <Foundation/Foundation.h>
@implementation FKPerson {
    int _textAttr;
}
- (void) setName: (NSString *) n andAge: (int) a {
    _name = n;
    _age = a;
}
- (void) say: (NSString *) content {
    NSLog(@"%@", content);
}
- (NSString *) info {
    [self text];
    return [NSString stringWithFormat:
            @"我是一个人，名字为： %@, 年龄为%d. ", _name, _age];
}
- (void) text {
    NSLog(@"--只在实现部分定义text方法--");
}
+ (void) foo {
    NSLog(@"FKPerson类的类方法， 通过类名调用");
}
@end
