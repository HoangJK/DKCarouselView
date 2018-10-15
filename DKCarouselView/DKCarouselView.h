//
//  DKCarouselView.h
//  DKCarouselView
//
//  Created by ZhangAo on 10/31/11.
//  Copyright 2011 DKCarouselView. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DKCarouselItem : NSObject

@property (nonatomic, strong) id userInfo;

@end

/**
 *  Online Image
 */
@interface DKCarouselURLItem : DKCarouselItem

@property (nonatomic, copy) NSString *imageUrl;

@end

/**
 *  Custom View
 */
@interface DKCarouselViewItem : DKCarouselItem

@property (nonatomic, strong) UIView *view;

@end

//////////////////////////////////////////////////////////////////////////////////////////

@interface DKCarouselView : UIView

typedef void(^DKCarouselViewDidSelectBlock)(DKCarouselItem *item, NSInteger index);
typedef void(^DKCarouselViewDidChangeBlock)(DKCarouselView *view, NSInteger index);
typedef void(^DKCarouselViewDidScrollBlock)(DKCarouselView *view, UIScrollView *scrollView, NSInteger offset);
typedef void(^DKCarouselViewWillBeginDraggingBlock)(DKCarouselView *view, UIScrollView *scrollView);

@property (nonatomic, readonly) NSUInteger numberOfItems;

// set clicked block
- (void)setDidSelectBlock:(DKCarouselViewDidSelectBlock)didSelectBlock;

// set page changed block
- (void)setDidChangeBlock:(DKCarouselViewDidChangeBlock)didChangeBlock;

// set page scrolling
- (void)setDidScrollBlock:(DKCarouselViewDidScrollBlock)didScrollBlock;

// set page scrolling
- (void)setWillBeginDraggingBlock:(DKCarouselViewWillBeginDraggingBlock)willBeginDragging;

// placeholder for DKCarouselURLItem
@property (nonatomic, strong) UIImage *defaultImage;

// set infinite slide or not, defaults to NO.
@property (nonatomic, assign, getter = isFinite) BOOL finite;

// set disable swipe right
@property (nonatomic, assign) BOOL swipeRightEnable;

- (void)setItems:(NSArray *)items;

// disable swipe left
- (void)setEnableSwipeRight:(BOOL)enable;

// auto paging.
- (void)setAutoPagingForInterval:(NSTimeInterval)timeInterval;
@property (nonatomic, assign, getter = isPause) BOOL pause;

// indicator
@property (nonatomic, assign) BOOL indicatorIsVisible; // by default page indicator is visible
@property (nonatomic, strong) UIColor *indicatorTintColor;
@property (nonatomic, assign) CGPoint indicatorOffset; // default offset is CGPointZero, the indicator is centered horizontally.
@property (nonatomic, readonly) CGSize indicatorSize; // returns minimum size for given items.

@end
