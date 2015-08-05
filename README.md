# RefreshWebSite

## 服务端
在SpringBoard进程里面运行，负责
  
* 定时开启、关闭飞行模式
  
* 已更换IP接受来自客户端的通知，这样做是为了如果更换后的IP和上一次的IP相同，则一直重复开启、关闭飞行模式，直到IP有变化

## 客户端

在沙箱环境中运行，负责

* 监听网络变化，如果有网络变化，则判断此次的外网IP是否和上次相同

* 如果IP和上次相同，则通过进程间通信通知SpringBoard进程，刷新IP

* 如果不相同，则执行刷网站的流程

## 其中涉及的技术细节

### 服务端

* 开启/关闭飞行模式的接口，通过逆向获得，[SBTelephonyManager setIsInAirplaneMode:(BOOL)on]

* 进程间通信的服务端，用到了librocketbootstrap.dylib这个库和rocketbootstrap.h头文件。具体操作流程见http://iphonedevwiki.net/index.php/Updating_extensions_for_iOS_7#Inter-process_communication

### 客户端

* 进程间通信的客户端实现，见http://iphonedevwiki.net/index.php/Updating_extensions_for_iOS_7#Inter-process_communication

* 在实现进程间通信的过程中，涉及到了Xcode引入私有framework，见http://chenjohney.blog.51cto.com/4132124/1288551

* 在刷网站的过程中，用到了HTML的解析，用到了三方库，见https://github.com/programmingthomas/ObjectiveGumbo
