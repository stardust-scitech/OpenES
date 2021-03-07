# 开源ESP8266服务器/Open ESP8266 Server
## 🎨 项目前言
截至本文件编辑当天，市面上没有系统性的开源的基于ESP8266数据采集传输和云端后台数据统计以及数据分发的系统性工程(包含基于ESP8266 SDK开发的UI交互界面等)，且相关开源工程较为零散。在民用市场和对大批量数据同步实时传输要求不高的场合中，ESP8266性价比相对较高。ESP8266 CPU时钟80MHz最高主频只有160MHz，不适合过于繁重的任务调度，但适合调度时间相对不太长的任务，官方已有RTOS支持。本工程往后也会逐步迁移至RTOS，目前任务数量较少的情况下无系统仍有较大优势。
## 🔧 版本发布
- 2021_03_ V1.0 凡尘(Kevin Brooks)
- 已实现功能：
	* (1)基础联网：
1.三种工作模式：STA、AP和STA+AP切换；
2.TCP连接；
3.MQTT订阅和发布；
	* (2)本地局域网：
4.服务器登录页面；
5.服务器菜单页面；
6.UI界面按钮控制；
7.UI界面生成设备随机密码；
8.UI界面修改登录服务器密码；
9.UI界面修改连接路由器密码；
10.APP远程控制。
- <span>待实现功能：
1.图像和数据同步传输；
2.OTA更新，要求稳定；
3.Fatfs文件系统；
4.STA+AP中转路由；
5.后台数据统计界面。
## 👉 工程环境
- 安信可科技IDE，本工程版本V0.5
- [ESP8266_NONOS_SDK，本工程版本V3.0.4](https://github.com/espressif/esp8266_nonos_sdk)
- 工程编码：UTF-8
- 晶振频率：26M
- SDI下载模式：DOUT
- Flash大小：4M(32Mbit)
## 📖 使用教程
- 1)将下载好的SDK解压并打开
- 2)删除driver_lib和example文件夹，并新建app文件夹
- 3)将本工程文件和文件夹拷贝到新建app文件夹中
- 4)将third_party中的Makefile文件名加上后缀bak
- 5)IDE导入工程，工具链选择Cygwin GCC
- 6)Clean project后Build Project
## 💻 技术细节
<span>硬件部分</span>
```
#define UART0 0 //TXD0 GPIO1(D10)  RXD0 GPIO3(D9)

#define I2C_MASTER_SDA_GPIO 4 //GPIO4(D2)
#define I2C_MASTER_SCL_GPIO 5 //GPIO5(D1)

#define HX710_SCK_PIN 12 //GPIO12(D6)
#define HX710_SDO_PIN 14 //GPIO14(D5)
```
<span>ESP8266软件部分</span>
```
u8 USART0_TX_BUF[256]; //USART0数据发送缓冲区
u8 USART0_RX_BUF[256]; //USART0数据接收缓冲区

#define GapValue 231.1 //电子秤校准参数

u8 SsidLocal[32] = "SmartBox"; //定义本地服务器名称
u8 PasswordLocal[32] = "stardust"; //定义本地服务器密码

u8 wifiname[36]={0}; //定义路由器名称
u8 wifipw[36]={0}; //定义路由器密码

const char esp_tcp_server_ip[4] = {52,36,58,151}; //远程MQTT服务器TCP地址,采用开放接口，感谢(broker.emqx.io)测试接口
remote_server.proto.tcp->remote_port = 1883; //开放1883接口
```
<span>OpenMV软件部分</span>
```
#UART通讯采用如下协议
uart.writechar(0x00)
uart.writechar(0x01)
uart.writechar(data)
uart.writechar(0xFE)
```
## 🚀 技术支持/更多深度科技
- 1)[相关技术博客](http://blog.stardust.live)
- 2)[技术交流群](https://jq.qq.com/?_wv=1027&amp;k=yrXYcrfz)
<p align="center">
    <span>技术交流群：星尘嵌入式社区</span>
    <br/>
    <span>群号：630581178</span>
    <br/>
    <a href="https://jq.qq.com/?_wv=1027&amp;k=yrXYcrfz" target="_blank" title="星尘嵌入式社区，群号：630581178">
        <img alt="星尘嵌入式社区，群号：630581178" width="220" src="http://stardust.live/res/img/group_chat_630581178.jpg">
    </a>
</p>
