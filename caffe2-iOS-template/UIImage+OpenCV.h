//
//  UIImage+OpenCV.h
//  caffe2-iOS-template
//
//  Created by zklgame on 2017/5/24.
//  Copyright © 2017年 Kaili Zhu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <opencv2/opencv.hpp>

@interface UIImage (OpenCV)

// The correct input should be in rgb 8UC3 mat
- (instancetype)initWithCVMat:(const cv::Mat&)cvMat;

// RGBA
- (cv::Mat)cvMatRGBA;

// BGR
- (cv::Mat)cvMatBGR;

// Gray Scale
- (cv::Mat)cvMatGray;

@end
