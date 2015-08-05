//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSData;

@interface CPSearchMatcher : NSObject
{
    int _options;
    NSArray *_components;
    NSArray *_asciiComponents;
    NSData *_wholeSearchStringData;
    NSData *_context;
}

- (void)dealloc;
- (id)initWithSearchString:(id)arg1 options:(int)arg2;
- (id)initWithSearchString:(id)arg1 andLocale:(id)arg2;
- (id)initWithSearchString:(id)arg1;
- (id)initWithSearchString:(id)arg1 andLocale:(id)arg2 andOptions:(int)arg3;
- (BOOL)matches:(id)arg1 matchType:(int)arg2;
- (BOOL)matches:(id)arg1;
- (BOOL)matchesUTF8String:(const char *)arg1 matchType:(int)arg2;
- (BOOL)matchesUTF8String:(const char *)arg1;
- (BOOL)matchesASCIIString:(const char *)arg1 matchType:(int)arg2;

@end

