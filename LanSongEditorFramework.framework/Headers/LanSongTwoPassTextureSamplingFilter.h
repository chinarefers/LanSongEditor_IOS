#import "LanSongTwoPassFilter.h"

@interface LanSongTwoPassTextureSamplingFilter : LanSongTwoPassFilter
{
    GLint verticalPassTexelWidthOffsetUniform, verticalPassTexelHeightOffsetUniform, horizontalPassTexelWidthOffsetUniform, horizontalPassTexelHeightOffsetUniform;
    GLfloat verticalPassTexelWidthOffset, verticalPassTexelHeightOffset, horizontalPassTexelWidthOffset, horizontalPassTexelHeightOffset;
    CGFloat _verticalTexelSpacing, _horizontalTexelSpacing;
}

// This sets the spacing between texels (in pixels) when sampling for the first. By default, this is 1.0
@property(readwrite, nonatomic) CGFloat verticalTexelSpacing, horizontalTexelSpacing;

@end
