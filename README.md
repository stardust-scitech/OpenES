# 开源ESP8266服务器/Open ESP8266 server
## 👉 工程环境
- 安信可科技IDE,本工程版本V0.5
- [ESP8266_NONOS_SDK,本工程版本V3.0.4](https://github.com/espressif/esp8266_nonos_sdk)
- 工程编码：UTF-8
- 晶振频率：26M
- SDI下载模式：DOUT
- Flash大小：4M(32Mbit)
## 📖 使用教程
1 将下载好的SDK解压并打开
2 删除driver_lib和example文件夹，并新建app文件夹
- 3) 将本工程文件和文件夹拷贝到新建app文件夹中
- 4) 将third_party中的Makefile文件名加上后缀bak
- 5) IDE导入工程，工具链选择Cygwin GCC
- 6) Clean project后Build Project
