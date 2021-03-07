# 开源ESP8266服务器/Open ESP8266 Server
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
<h1>硬件部分</h1>
```
#define UART0 0 //TXD0 GPIO1(D10)  RXD0 GPIO3(D9)

#define I2C_MASTER_SDA_GPIO 4 //GPIO4(D2)
#define I2C_MASTER_SCL_GPIO 5 //GPIO5(D1)

#define HX710_SCK_PIN 12 //GPIO12(D6)
#define HX710_SDO_PIN 14 //GPIO14(D5)
```
<h1>软件部分</h1>
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
