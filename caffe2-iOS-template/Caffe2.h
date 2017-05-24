//
//  Caffe2.h
//  caffe2-iOS-template
//
//  Created by zklgame on 2017/5/24.
//  Copyright © 2017年 Kaili Zhu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class Prediction;

@interface Caffe2 : NSObject

- (null_unspecified instancetype)init UNAVAILABLE_ATTRIBUTE;
- (nonnull instancetype)initWithInitNetName:(nonnull NSString *)initNetName
                             predictNetName:(nonnull NSString *)predictNetName;

// return: sorted array of prediction result
- (nonnull NSArray<Prediction *> *)predictFromImage:(nonnull UIImage *)image;

@end
