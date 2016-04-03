//
//  AEAudioUnitOutput.h
//  TheAmazingAudioEngine
//
//  Created by Michael Tyson on 23/03/2016.
//  Copyright © 2016 A Tasty Pixel. All rights reserved.
//
//  This software is provided 'as-is', without any express or implied
//  warranty.  In no event will the authors be held liable for any damages
//  arising from the use of this software.
//
//  Permission is granted to anyone to use this software for any purpose,
//  including commercial applications, and to alter it and redistribute it
//  freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//     claim that you wrote the original software. If you use this software
//     in a product, an acknowledgment in the product documentation would be
//     appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//     misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source distribution.
//

@import Foundation;
@import AudioToolbox;

#ifdef __cplusplus
extern "C" {
#endif

extern NSString * const _Nonnull AEAudioUnitOutputError;

@class AERenderer;

/*!
 * Audio unit output
 *
 *  Renders audio to the system output via an audio unit.
 */
@interface AEAudioUnitOutput : NSObject

/*!
 * Initialize with a renderer
 *
 * @param renderer Renderer to use to drive processing
 */
- (instancetype _Nullable)initWithRenderer:(AERenderer * _Nonnull)renderer;

/*!
 * Start the audio unit
 *
 * @param error If an error occured and this is not nil, it will be set to the error on output
 * @return YES on success, NO on failure
 */
- (BOOL)start:(NSError * __autoreleasing _Nullable * _Nullable)error;

/*!
 * Stop the audio unit
 */
- (void)stop;

@property (nonatomic, strong, readonly) AERenderer * _Nullable renderer; //!< The renderer
@property (nonatomic, readonly) AudioUnit _Nonnull audioUnit; //!< The audio unit
@property (nonatomic) double sampleRate; //!< The sample rate at which to run, or zero to track the hardware sample rate
@property (nonatomic, readonly) double currentSampleRate; //!< The current sample rate (key-value observable)
@property (nonatomic, readonly) BOOL running; //!< Whether unit is currently active
@property (nonatomic, readonly) int outputChannels; //!< The current number of output channels (key-value observable)

#if TARGET_OS_IPHONE
@property (nonatomic) BOOL latencyCompensation; //!< Whether to automatically perform latency compensation (default YES)
#endif

@end

#ifdef __cplusplus
}
#endif
