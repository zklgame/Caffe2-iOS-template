//
//  Prediction.h
//  caffe2-iOS-template
//
//  Created by zklgame on 2017/5/24.
//  Copyright © 2017年 Kaili Zhu. All rights reserved.
//

@interface Prediction : NSObject

@property (nonnull, strong) NSString *itemName;
@property (assign) double confidence;

- (nonnull instancetype)initWithItemName:(nonnull NSString *)itemName confidence:(double)confidence;

+ (nonnull NSString *)itemNameForClassIndex:(NSInteger)classIndex;

@end
