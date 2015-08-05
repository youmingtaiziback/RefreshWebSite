ARCHS = armv7 arm64

include theos/makefiles/common.mk

TWEAK_NAME = AirPlaneModeSwitch
AirPlaneModeSwitch_FILES = Tweak.xm
AirPlaneModeSwitch_LDFLAGS = -lrocketbootstrap
AirPlaneModeSwitch_FRAMEWORKS = Foundation, UIKit
AirPlaneModeSwitch_PRIVATE_FRAMEWORKS = AppSupport

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"
