//
//  ViewController.m
//  LocateURL
//
//  Created by youmingtaizi on 7/31/15.
//  Copyright (c) 2015 edu. All rights reserved.
//

#import "ViewController.h"
#import <ObjectiveGumbo.h>
#import <Reachability.h>
#import "rocketbootstrap.h"
#import "CPDistributedMessagingCenter.h"

@interface ViewController () <UIWebViewDelegate> {
    IBOutlet UIWebView* _webView;
    BOOL        _shouldLocate;
    NSArray*    _keywords;
    NSString*   _lastIP;
}
@end

@implementation ViewController

#pragma mark - Life Cycle

- (void)viewDidLoad {
    [super viewDidLoad];

    //get the original user-agent of webview
    NSString *oldAgent = [_webView stringByEvaluatingJavaScriptFromString:@"navigator.userAgent"];
    NSLog(@"old agent :%@", oldAgent);
    
    //add my info to the new agent
    NSString *newAgent = @"Mozilla/5.0 (iPhone; CPU iPhone OS 8_2 like Mac OS X) AppleWebKit/600.1.4 (KHTML, like Gecko) Version/8.0 Mobile/12D508 Safari/600.1.4";
    NSLog(@"new agent :%@", newAgent);
    
    //regist the new agent
    [[NSUserDefaults standardUserDefaults] registerDefaults:@{@"UserAgent":newAgent}];
    
    _keywords = @[@"开ktv要多少钱",
                  @"ktv加盟",
                  @"量贩式ktv加盟",
                  @"量版式ktv加盟",
                  @"加盟ktv",
                  @"开一间ktv要多少钱",
                  @"开一家ktv要多少钱",
                  @"量贩ktv加盟",
                  @"开一个ktv多少钱",
                  @"开个ktv大概需要多少钱",
                  @"开ktv需要什么条件",
                  @"开ktv需要多少资金",
                  @"开ktv需要多少钱",
                  @"我想加盟ktv",
                  @"开个小型ktv要多少钱",
                  @"开个量贩ktv要多少钱",
                  @"ktv加盟店排行榜",
                  @"加盟ktv需要投资多少钱",
                  @"加盟量贩式ktv",
                  @"量贩式ktv加盟费"];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(reachabilityChanged:)
                                                 name:kReachabilityChangedNotification
                                               object:nil];
    
    Reachability* reach = [Reachability reachabilityForInternetConnection];
    [reach startNotifier];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [self refreshIP];
}

#pragma mark - Private Methods

// 如果当前ip和上一次的ip相同，则通知SpringBoard进程再重新开启关闭飞行模式
- (void)reachabilityChanged:(NSNotification *)noti {
    Reachability *reach = [noti object];
    if ([reach currentReachabilityStatus] == ReachableViaWWAN) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            NSString *IP = nil;
            //            NSURL *url = [NSURL URLWithString:@"http://ifconfig.me/ip"];
            NSURL *url = [NSURL URLWithString:@"http://myip.dnsomatic.com/"];
            NSURLRequest *request = [NSURLRequest requestWithURL:url cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:8.0];
            NSData *data = [NSURLConnection sendSynchronousRequest:request returningResponse:nil error:nil];
            if (data)
                IP = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            
            if (IP.length > 0) {
                NSLog(@"******** IP = %@", IP);
                dispatch_async(dispatch_get_main_queue(), ^{
                    if ([_lastIP isEqualToString:IP])
                        [self refreshIP];
                    else {
                        _lastIP = IP;
                        [self searchKeyword];
                    }
                });
            }
        });
    }
}

- (void)searchKeyword {
    NSString *keyword = [_keywords[arc4random() % _keywords.count] stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    NSLog(@"******** keyword = %@", keyword);
    NSString *urStr = [NSString stringWithFormat:@"https://www.baidu.com/s?wd=%@", keyword];
    NSURL *url = [NSURL URLWithString:urStr];
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:url];
    [_webView loadRequest:request];
    _shouldLocate = YES;
}

- (void)refreshIP {
    CPDistributedMessagingCenter *c = [CPDistributedMessagingCenter centerNamed:@"com.youmingtaizi.center"];
    rocketbootstrap_distributedmessagingcenter_apply(c);
    [c sendMessageName:@"refreshIP" userInfo:nil];
}

#pragma mark - UIWebViewDelegate

- (void)webViewDidFinishLoad:(UIWebView *)webView {
    if (_shouldLocate) {
        _shouldLocate = NO;
        NSString *htmlSource = [webView stringByEvaluatingJavaScriptFromString:@"document.body.innerHTML"];
        OGNode * data = [ObjectiveGumbo parseDocumentWithString:htmlSource];
        OGElement *body = [data elementsWithTag:GUMBO_TAG_BODY][0];
        NSArray *wiseAds = [body elementsWithClass:@"ec_wise_ad"];
        
        BOOL findTarget = NO;
        
        for (OGElement *wiseAd in wiseAds) {
            if (!findTarget) {
                NSArray *tagetDivs = [wiseAd elementsWithClass:@"ec_resitem"];
                for (OGElement *tagetDiv in tagetDivs) {
                    if (!findTarget) {
                        if ([tagetDiv.text rangeOfString:@"dumaiktv.com"].location != NSNotFound) {
                            NSString *parten = @"(?<=href=\").*?m\.baidu\.com.*?url=.*?(?=\")";
                            NSRegularExpression *reg = [NSRegularExpression regularExpressionWithPattern:parten options:0 error:nil];
                            NSArray* match = [reg matchesInString:tagetDiv.html options:NSMatchingReportCompletion range:NSMakeRange(0, [tagetDiv.html length])];
                            
                            if (match.count != 0) {
                                for (NSTextCheckingResult *matc in match) {
                                    NSString *url = [tagetDiv.html substringWithRange:[matc range]];
                                    NSString *js = [NSString stringWithFormat:@"window.location.href=\"%@\"", url];
                                    [webView stringByEvaluatingJavaScriptFromString:js];
                                    NSLog(@"******** location = %@", url);
                                    findTarget = YES;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        // 如果没有找到指定的URL，则重新刷IP
        if (!findTarget) {
            [self refreshIP];
        }
    }
}

@end
