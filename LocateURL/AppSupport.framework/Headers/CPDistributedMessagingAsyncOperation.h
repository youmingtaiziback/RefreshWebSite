//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSOperation.h"

@class CPDistributedMessagingCenter, NSData, NSDictionary, NSError, NSString, NSThread;

@interface CPDistributedMessagingAsyncOperation : NSOperation
{
    CPDistributedMessagingCenter *_center;
    NSString *_name;
    NSData *_userInfoData;
    NSString *_oolKey;
    NSData *_oolData;
    id _target;
    SEL _selector;
    void *_context;
    BOOL _makeServer;
    NSThread *_calloutThread;
    NSDictionary *_reply;
    NSError *_error;
}

- (void)_performCallout;
- (void)main;
- (void)_releaseSendingData;
- (void)dealloc;
- (id)initWithCenter:(id)arg1 messageName:(id)arg2 userInfoData:(id)arg3 oolKey:(id)arg4 oolData:(id)arg5 target:(id)arg6 selector:(SEL)arg7 context:(void *)arg8 makeServer:(BOOL)arg9;

@end

