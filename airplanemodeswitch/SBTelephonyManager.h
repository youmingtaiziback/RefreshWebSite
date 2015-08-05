//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

//#import "NSObject.h"
//
//#import "RadiosPreferencesDelegate.h"

//@class NSObject<OS_dispatch_queue>, NSString, NSTimer, RadiosPreferences, SBAlertItem, TUCall;

@interface SBTelephonyManager : NSObject// <RadiosPreferencesDelegate>
{
//    struct __CTServerConnection *_serverConnection;
//    _Bool _containsCellularRadio;
//    _Bool _hasCellularTelephony;
//    _Bool _hasCellularData;
//    _Bool _hasAnyTelephony;
//    NSString *_cachedCTRegistrationCellStatus;
//    NSString *_cachedCTRegistrationDisplayStatus;
//    int _cachedCTRegistrationIsForcedHome;
//    int _cellRegistrationStatus;
//    int _registrationStatus;
//    NSTimer *_fakeServiceTimer;
//    NSTimer *_fakeCellServiceTimer;
//    _Bool _signalStrengthHasBeenSet;
//    int _signalStrength;
//    int _signalStrengthBars;
//    NSString *_operatorName;
//    NSString *_lastKnownNetworkCountryCode;
//    unsigned int _usingWifi:1;
//    int _vpnConnectionStatus;
//    unsigned int _iTunesNeedsToRecheckActivation:1;
//    unsigned int _pretendingToSearch:1;
//    unsigned int _callForwardingIndicator:2;
//    NSObject<OS_dispatch_queue> *_wirelessModemDynamicStoreQueue;
//    struct __SCDynamicStore *_queue_wirelessModemDynamicStore;
//    struct __CFString *_queue_wirelessModemDynamicStoreSharingKey;
//    _Bool _isNetworkTethering;
//    int _numberOfNetworkTetheredDevices;
//    unsigned int _hasShownWaitingAlert:1;
//    SBAlertItem *_activationAlertItem;
//    int _numActivationFailures;
//    int _inEmergencyCallbackMode;
//    unsigned int _loggingCallAudio:1;
//    NSString *_inCallStatusPreamble;
//    NSString *_inCallDurationString;
//    NSTimer *_inCallTimer;
//    NSTimer *_inCallStyleDelayTimer;
//    RadiosPreferences *_radioPrefs;
//    int _needsUserIdentificationModule;
//    NSString *_simStatus;
//    int _suppressesCellDataIndicator;
//    int _suppressesCellIndicators;
//    int _lteConnectionShows4G;
//    int _modemDataConnectionType;
//    _Bool _modemDataConnectionTypeIsKnown;
//    _Bool _fallingBackToCellular;
//    struct tcp_connection_fallback_watch_s *_cellularFallbackWatcher;
//    void *_queue_fastDormancySuspendAssertion;
//    TUCall *_incomingCall;
//    TUCall *_activeCall;
//    TUCall *_heldCall;
//    TUCall *_outgoingCall;
}

//+ (id)sharedTelephonyManagerCreatingIfNecessary:(_Bool)arg1;
+ (id)sharedTelephonyManager;
//@property(retain, nonatomic) TUCall *outgoingCall; // @synthesize outgoingCall=_outgoingCall;
//@property(retain, nonatomic) TUCall *heldCall; // @synthesize heldCall=_heldCall;
//@property(retain, nonatomic) TUCall *activeCall; // @synthesize activeCall=_activeCall;
//@property(retain, nonatomic) TUCall *incomingCall; // @synthesize incomingCall=_incomingCall;
//- (void)_setIsNetworkTethering:(_Bool)arg1 withNumberOfDevices:(int)arg2;
//- (int)numberOfNetworkTetheredDevices;
//- (_Bool)isNetworkTethering;
//- (void)noteSIMUnlockAttempt;
//- (int)registrationCauseCode;
//- (_Bool)needsUserIdentificationModule;
//- (id)SIMStatus;
//- (void)_setSIMStatus:(id)arg1;
//- (int)registrationStatus;
//- (int)cellRegistrationStatus;
//- (id)operatorName;
//- (void)_operatorBundleChanged;
//- (void)setOperatorName:(id)arg1;
//- (void)_reallySetOperatorName:(id)arg1;
//- (void)_fetchOperatorNameWithCompletion:(CDUnknownBlockType)arg1;
//- (int)signalStrengthBars;
//- (int)signalStrength;
//- (void)_setSignalStrength:(int)arg1 andBars:(int)arg2;
//- (void)_carrierBundleChanged;
//- (void)_prepareToAnswerCall;
//- (_Bool)_pretendingToSearch;
//- (void)_stopFakeCellService;
//- (void)_cancelFakeCellServiceTimer;
//- (void)_stopFakeService;
//- (void)_startFakeServiceIfNecessary;
//- (void)_cancelFakeServiceTimer;
//- (void)_updateRegistrationNow;
//- (void)_setRegistrationStatus:(int)arg1;
//- (void)_setCellRegistrationStatus:(int)arg1;
//- (void)_setCachedCTRegistrationCellStatus:(struct __CFString *)arg1 displayStatus:(struct __CFString *)arg2 forcedHome:(_Bool)arg3;
//- (struct __CFString *)_cachedCTRegistrationDisplayStatus;
//- (struct __CFString *)_cachedCTRegistrationCellStatus;
//- (void)postponementStatusChanged;
//- (void)_headphoneChanged:(id)arg1;
//- (void)_resetCTMMode;
//- (id)ttyTitle;
//- (_Bool)shouldPromptForTTY;
//- (void)configureForTTY:(_Bool)arg1;
//- (void)exitEmergencyCallbackMode;
//- (void)_setIsInEmergencyCallbackMode:(unsigned char)arg1;
//- (_Bool)isInEmergencyCallbackMode;
//- (_Bool)isEmergencyCallActive;
//- (void)_provisioningUpdateWithStatus:(int)arg1;
//- (void)_setCurrentActivationAlertItem:(id)arg1;
//- (id)copyTelephonyCapabilities;
//- (id)copyMobileEquipmentInfo;
//- (_Bool)isUsingVPNConnection;
//- (void)_setVPNConnectionStatus:(int)arg1;
//- (void)_setIsUsingWiFiConnection:(_Bool)arg1;
//- (_Bool)_isTTYEnabled;
//- (_Bool)isUsingSlowDataConnection;
//- (_Bool)registeredWithoutCellular;
//- (_Bool)isInAirplaneMode;
- (void)setIsInAirplaneMode:(_Bool)arg1;
//- (_Bool)cellDataIsOn;
//- (_Bool)cellularRadioCapabilityIsActive;
//- (void)_setSuppressesCellIndicators:(int)arg1;
//- (void)_postDataConnectionTypeChanged;
//- (int)dataConnectionType;
//- (void)_updateDataConnectionType;
//- (int)_updateModemDataConnectionTypeWithCTInfo:(id)arg1;
//- (_Bool)_suppressesCellDataIndicator;
//- (_Bool)_lteConnectionShows4G;
//- (void)_resetModemConnectionType;
//- (void)setNetworkRegistrationEnabled:(_Bool)arg1;
//- (_Bool)isNetworkRegistrationEnabled;
//- (_Bool)MALoggingEnabled;
//- (void)dumpBasebandState:(id)arg1;
//- (void)_setIsLoggingCallAudio:(_Bool)arg1;
//- (_Bool)isLoggingCallAudio;
//- (void)disconnectCallAndActivateHeld;
//- (void)disconnectCall;
//- (void)disconnectAllCalls;
//- (void)swapCalls;
//- (void)disconnectIncomingCall;
//- (_Bool)inCall;
//- (unsigned long long)faceTimeAudioCallCount;
//- (unsigned long long)telephonyCallCount;
//- (unsigned long long)_callCountForService:(int)arg1;
//- (_Bool)shouldHangUpOnLock;
//- (_Bool)callWouldUseReceiver:(_Bool)arg1;
//- (_Bool)inCallUsingSpeakerOrReceiver;
//- (id)_fastPickedRouteForCall;
//- (_Bool)multipleCallsExist;
//- (_Bool)outgoingCallExists;
//- (_Bool)incomingCallExists;
//- (_Bool)heldCallExists;
//- (_Bool)activeCallExists;
//- (id)displayedCall;
//- (void)telephonyAudioChangeHandler;
//- (int)callCount;
//- (void)callEventHandler:(id)arg1;
//- (void)handleCallAudioFinished:(id)arg1;
//- (void)handleCallControlFailure:(id)arg1;
//- (void)updateDisplaySettings:(id)arg1 forOutgoingCallURL:(id)arg2 outURL:(id *)arg3;
//- (_Bool)isEmergencyCallScheme:(id)arg1;
//- (id)lastKnownNetworkCountryCode;
//- (void)_updateLastKnownNetworkCountryCode;
//- (void)_updateNetworkLocale;
//- (_Bool)updateLocale;
//- (void)_updateState;
//- (void)updateCalls;
//- (void)airplaneModeChanged;
//- (void)updateAirplaneMode;
//- (void)setFastDormancySuspended:(_Bool)arg1;
//- (void)queue_setFastDormancySuspended:(_Bool)arg1 withConnection:(struct __CTServerConnection *)arg2;
//- (void)setLimitTransmitPowerPerBandEnabled:(_Bool)arg1;
//- (id)inCallDurationString;
//- (void)updateStatusBarCallDuration;
//- (id)preambleStringForKey:(id)arg1;
//- (void)_updateStatusBarCallStateForCall:(id)arg1;
//- (void)_noteInCallStyleDelayExpired;
//- (void)_noteInCallAlertDidActivate;
//- (id)_phoneApp;
//- (void)updateSpringBoard;
//- (int)callForwardingIndicator;
//- (void)updateCallForwardingIndicator;
//- (void)setCallForwardingIndicator:(int)arg1;
//- (double)inCallDuration;
//- (void)updateTTYIndicator;
//- (_Bool)emergencyCallSupported;
//- (_Bool)hasAnyTelephony;
//- (_Bool)hasCellularData;
//- (_Bool)hasCellularTelephony;
//- (_Bool)containsCellularRadio;
//- (void)SBTelephonyDaemonRestartHandler;
//- (void)_serverConnectionDidError:(CDStruct_1ef3fb1f)arg1;
//- (void)_avSystemControllerDidError:(id)arg1;
//- (struct __CTServerConnection *)_serverConnection;
//- (void)_performQueryInBackground:(CDUnknownBlockType)arg1 withMainQueueResultHandler:(CDUnknownBlockType)arg2;
//- (void)_postStartupNotification;
//- (id)init;

@end

