//
//  CameraPen.h
//  LanSongEditorFramework
//
//  Created by sno on 2017/9/6.
//  Copyright © 2017年 sno. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>
#import "Pen.h"


#import "LanSongContext.h"
#import "LanSongOutput.h"
#import "LanSongColorConversion.h"

//Optionally override the YUV to RGB matrices
void setColorConvert601_CameraPen( GLfloat conversionMatrix[9] );
void setColorConvert601FullRange_CameraPen( GLfloat conversionMatrix[9] );
void setColorConvert709_CameraPen( GLfloat conversionMatrix[9] );


//Delegate Protocal for Face Detection.

///**
// 摄像头视频输出的回调, 拿到原画面后,可以把数据拉出去.
// */
@protocol CameraPenDelegate <NSObject>

@optional
- (void)willOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer;
@end


@interface CameraPen : Pen <AVCaptureVideoDataOutputSampleBufferDelegate, AVCaptureAudioDataOutputSampleBufferDelegate>
{
    NSUInteger numberOfFramesCaptured;
    CGFloat totalFrameTimeDuringCapture;
    
    AVCaptureSession *_captureSession;
    //采集的设备,有input和output.
    AVCaptureDevice *_inputCamera;//
    AVCaptureDevice *_microphone;
    
    AVCaptureDeviceInput *videoInput;
    AVCaptureVideoDataOutput *videoOutput;
    
    BOOL capturePaused;  //停止画面输出, 就是在回调中,直接返回.
    
    /*
     outputRotation: 下发到target中的角度.
     internalRotation: 当画面设置后, 需要在yuv2RGB的时候, 旋转角度.
     */
    LanSongRotationMode outputRotation, internalRotation;
    dispatch_semaphore_t frameRenderingSemaphore;
    
    BOOL captureAsYUV;
    GLuint luminanceTexture, chrominanceTexture;
    
    __unsafe_unretained id<CameraPenDelegate> _delegate;
}


/**
 是否在运行;
 */
@property(readonly, nonatomic) BOOL isRunning;

@property(readonly, retain, nonatomic) AVCaptureSession *captureSession;

/**
 当前相机实际工作设置的分辨率
 */
@property (readwrite, nonatomic, copy) NSString *captureSessionPreset;

/**
 当前Cemera 设置的帧率
 */
@property (readwrite) int32_t frameRate;


/**
 当前Camera输出的像素的宽度和高度.
 在开始预览后, 拿到第一帧的时候, 方有效;
 */
@property (readonly) int pixelWidth;
@property (readonly) int pixelheight;
/**
 当前是否是前置
 */
@property (readonly, getter = isFrontFacingCameraPresent) BOOL frontFacingCameraPresent;

/**
 当前是否是后置.
 */
@property (readonly, getter = isBackFacingCameraPresent) BOOL backFacingCameraPresent;


/**
 当前摄像头对象.
 */
@property(readonly) AVCaptureDevice *inputCamera;


/**
 当前软件的角度.
 */
@property(readwrite, nonatomic) UIInterfaceOrientation outputImageOrientation;


/**
 当前置相机的时候, 是否左右镜像.
 */
@property(readwrite, nonatomic) BOOL horizontallyMirrorFrontFacingCamera;


/**
 当后置相机的时候, 是否左右镜像.
 */
@property(readwrite, nonatomic) BOOL horizontallyMirrorRearFacingCamera;

@property(nonatomic, assign) id<CameraPenDelegate> delegate;

/**
 切换前后摄像头
 */
- (void)rotateCamera;

/*
 开启闪光灯
 */
- (void)openFlashLight;
/**
 关闭闪光灯
 */
- (void)closeFlashLight;
/**
 当前闪光灯是否在开着.
 */
-(BOOL)isFlashON;
/**
 获取当前是前置还是后置
 */
- (AVCaptureDevicePosition)cameraPosition;

//-----------------------------------以下均为内部使用-------------------------
/**
 内部使用
 */
- (id)init:(NSString *)sessionPreset position:(AVCaptureDevicePosition)pos drawpadSize:(CGSize)size drawpadTarget:(id<LanSongInput>)target;
- (BOOL)addAudioInputsAndOutputs;
- (void)removeInputsAndOutputs;
- (void)startCameraCapture;
- (void)stopCameraCapture;
- (void)pauseCameraCapture;
- (void)resumeCameraCapture;
- (void)processAudioSampleBuffer:(CMSampleBufferRef)sampleBuffer;
- (AVCaptureConnection *)videoCaptureConnection;
- (void)setAudioEncoderTarget:(id<LanSongInput>)newValue;



@end
