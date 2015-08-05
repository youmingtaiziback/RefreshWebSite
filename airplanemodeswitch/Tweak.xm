
#include <substrate.h>
#import <objc/runtime.h>
#import <UIKit/UIApplication.h>
#import "SBTelephonyManager.h"
#import "rocketbootstrap.h"
#import "CPDistributedMessagingCenter.h"

#define kintervalbetweenswitchsinminutes 	10

// Hook

static SBTelephonyManager *manager;

%hook SBTelephonyManager

+ (id)sharedTelephonyManager {
	manager = %orig;
	return manager;
}

%end

@interface Controller : NSObject {
	NSTimer*	_timer;
}
@end

@implementation Controller

// Life Cycle

- (id)init {
	if (self = [super init]) {
		CPDistributedMessagingCenter *c = [CPDistributedMessagingCenter centerNamed:@"com.youmingtaizi.center"];
		rocketbootstrap_distributedmessagingcenter_apply(c);
		[c runServerOnCurrentThread];
		[c registerForMessageName:@"refreshIP" target:self selector:@selector(handleMessageNamed:withUserInfo:)];
	}
	return self;
}

// Callback

- (void)handleMessageNamed:(NSString *)name withUserInfo:(NSDictionary *)userInfo {
	[self action];
	[self startActionLoop];
}

// action loop

- (void)startActionLoop {
	[_timer invalidate];
	_timer = [NSTimer scheduledTimerWithTimeInterval:kintervalbetweenswitchsinminutes * 60 target:self selector:@selector(action) userInfo:nil repeats:YES];
}

- (void)action {
	NSLog(@"manager = %@", manager);
    [manager setIsInAirplaneMode:YES];
	dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
		[manager setIsInAirplaneMode:NO];
    });
}

@end

%ctor {
	%init;
	NSLog(@"************* init");
	NSString *identifier = [[NSBundle mainBundle] bundleIdentifier];
	if ([identifier isEqualToString:@"com.apple.springboard"]) {
		Controller *controller = [[Controller alloc] init];
		[controller action];
		[controller startActionLoop];
	}
}
