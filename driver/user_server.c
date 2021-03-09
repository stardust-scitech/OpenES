/**
  ******************************************************************************
  * @file    user_server.c
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_03_09
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  * @brief   This file provides all the HX710 firmware functions.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#include "ip_addr.h"
#include "espconn.h"
#include "mem.h"

#include "user_server.h"
#include "user_mqtt.h"
#include "user_page.h"
#include "user_http.h"

static os_timer_t connect_timer;
static os_timer_t mqtt_timer;

struct espconn local_server;
struct espconn remote_server;

u8 SsidLocal[32] = "SmartBox";
u8 PasswordLocal[32] = "stardust";

static void Wifi_Scan_Done(void *arg,STATUS status);
static void Wifi_Conned(void *arg);

static void Server_Scan_Local(void);
static void Server_listen_Local(void *arg);

static void Server_Discon_Local(void *arg);
static void Server_Recon_Local(void *arg,sint8 err);
static void Server_Receive_Local(void *arg, char *pdata, unsigned short len);
static void Server_Send_Local(void *arg);

static void Server_Scan_Remote(void);
static void Server_listen_Remote(void *arg);

static void Server_Discon_Remote(void *arg);
static void Server_Recon_Remote(void *arg,sint8 err);
static void Server_Receive_Remote(void *arg, char *pdata, unsigned short len);
static void Server_Send_Remote(void *arg);

/******************************本地服务器相关函数-Start******************************/
/**
  * @brief 初始化本地服务器函数
  * @param void
  * @return void
  */
void ICACHE_FLASH_ATTR
Server_Init_Local(void)
{
    struct softap_config config;

	u8 DeviceId[]="20041801";

	u8 SEC=123;
	u8 SEC_OFFSET = 0;

	//spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)DeviceId, 8);
	spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)DeviceId, 8);
	MQTT_Init(DeviceId);
    HttpPack(Check_html, "设备编号：", DeviceId);	//设置设备编号

	wifi_softap_get_config(&config);
	os_strcpy(config.ssid,SsidLocal); //改成你自己的   路由器的用户名
	os_strcpy(config.password,PasswordLocal); //改成你自己的   路由器的密码
	config.ssid_len = strlen(SsidLocal);
	config.authmode = AUTH_WPA_WPA2_PSK;
	config.max_connection = 4;	//最多设备数
	wifi_softap_set_config(&config);

	Server_Scan_Local();	//开启tcp服务器
}

/**
  * @brief 扫描本地连接
  * @param void
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Scan_Local(void)
{
	local_server.proto.tcp = (esp_tcp *)os_zalloc(sizeof(esp_tcp));
	local_server.proto.tcp->local_port = 80;	//监听本地端口号
	local_server.type = ESPCONN_TCP;
	local_server.state = ESPCONN_NONE;

	espconn_regist_time(&local_server, 120, 0);	//设置服务器超时时间为120秒
	espconn_regist_connectcb(&local_server, Server_listen_Local);	//连接成功回调
	espconn_accept(&local_server);		//开启TCP服务器
}

/**
  * @brief 监听本地连接
  * @param void
  * @return void
  */
void ICACHE_FLASH_ATTR
Server_listen_Local(void *arg)//服务器被链接回调
{
	struct espconn *pespconn = (struct espconn *)arg;

	espconn_regist_disconcb(pespconn,Server_Discon_Local); //开启正常断开回调
	espconn_regist_reconcb(pespconn, Server_Recon_Local); //开启异常断开回调
	espconn_regist_recvcb(pespconn, Server_Receive_Local); //开启接收回调
	espconn_regist_sentcb(pespconn, Server_Send_Local); //开启发送成功回调
}

/**
  * @brief 异常断开回调函数
  * @param arg 回调主体
  * @param err 错误代码
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Recon_Local(void *arg,sint8 err)
{
    os_printf("本地连接错误，错误代码为：%s\r\n", err);	//输出重新连接的错误代码
}

/**
  * @brief 正常断开回调函数
  * @param arg 回调主体
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Discon_Local(void *arg)
{
    os_printf("本地连接已经断开\r\n");
}

/**
  * @brief 本地服务器数据接收函数
  * @param arg 回调主体
  * @param pdata 接收到的数据指针
  * @param len 接收到的数据长度
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Receive_Local(void *arg, char *pdata, unsigned short len)
{
	char * Console  = strstr(pdata," /Console.html");
	char * Login = strstr(pdata," /Login.html");
	char * Connect  = strstr(pdata," /Connect.html");
	char * Check  = strstr(pdata," /Check.html");
	char * AJAX  = strstr(pdata,"POST /CallBack.php");

	unsigned short i,web_len = 0;
	struct espconn *pespconn = (struct espconn *)arg;

	os_printf("本地服务器接收数据为：\r\n");

	if(Console != NULL)
	{
		char * button_1  = strstr(pdata,"button=1");
		char * button_2  = strstr(pdata,"button=2");

		if(button_1 != NULL)
		{
			char * lock  = strstr(pdata,"lock=on");
			if(lock != NULL)	USART0_TX_BUF[0] = 'o';
			else USART0_TX_BUF[0] = 'c';
			uart0_SendPackage(USART0_TX_BUF, 2);
		}else if(button_2 != NULL)
		{
			char * light  = strstr(pdata,"light=on");
			if(light != NULL)	USART0_TX_BUF[1] = 'o';
			else USART0_TX_BUF[1] = 'c';
			uart0_SendPackage(USART0_TX_BUF, 2);
		}else
		{
			espconn_send(pespconn,Console_html,sizeof(Console_html));
		}
	}else if (Login != NULL)
	{
		u8 * name = NULL;
		u8 * pass = NULL;
		u8 username[36]={0};
		u8 password[36]={0};
		u8 SEC=126;
		u8 SEC_OFFSET = 0;

		HttpGet(pdata, "username=", "&", username);
		HttpGet(pdata, "password=", "&", password);

		if(strlen(username)!=0 && strlen(password)!=0)
		{
			spi_flash_erase_sector(SEC);
			spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)username, 36);
			SEC_OFFSET = 36;
			spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)password, 36);

			espconn_send(pespconn,Console_html,sizeof(Console_html));
		}else
		{
			espconn_send(pespconn,Login_html,sizeof(Login_html));
		}
	}else if(Connect != NULL)
	{
		char *connect  = strstr(pdata,"connect=ture");

		if(connect != NULL)
		{
			u8 SEC=125;
			u8 SEC_OFFSET = 0;

			u8 wifiname[36]={0};
			u8 wifipw[36]={0};

			HttpGet(pdata, "wifiname=", "&", wifiname);
			HttpGet(pdata, "wifipw=", "&", wifipw);

			spi_flash_erase_sector(SEC);
			spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)wifiname, 36);
			SEC_OFFSET = 36;
			spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)wifipw, 36);

			wifi_station_scan(NULL,Wifi_Scan_Done);

			espconn_send(pespconn,Console_html,sizeof(Console_html));
		}
		espconn_send(pespconn,Connect_html,sizeof(Connect_html));
	}else if (Check != NULL)
	{
		u8 SEC=124;
		u8 SEC_OFFSET =  0;
		char * Renew  = strstr(pdata,"renew=ture");

		u8 DevicePass[9]={0};
		u32 *value;

		if (Renew != NULL)
		{
			u32 *value;

			MakeRandStr(DevicePass, 8);
			value=(u32*)DevicePass;
			spi_flash_erase_sector(SEC);
			spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)DevicePass, 8);
		}
		spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)DevicePass, 8);
		HttpPack(Check_html, "随机密码：", DevicePass);
		espconn_send(pespconn,Check_html,sizeof(Check_html));
	}else if(AJAX != NULL)
	{
		char * temperature = strstr(pdata,"temperature");
		char * humidity  = strstr(pdata,"humidity");
		char * collision = strstr(pdata,"collision");
		char * carbon  = strstr(pdata,"carbon");

		char TempValue[]="箱内温度:00℃";
		char HumValue[]="箱内湿度:00%RH";

		TempValue[13] = USART0_RX_BUF[0]/10+48;
		TempValue[14] = USART0_RX_BUF[0]%10+48;

		HumValue[13] = USART0_RX_BUF[1]/10+48;
		HumValue[14] = USART0_RX_BUF[1]%10+48;

		if(temperature != NULL) espconn_send(pespconn,TempValue,strlen(TempValue));
		else if(humidity != NULL) espconn_send(pespconn,HumValue,strlen(HumValue));
		else if(collision != NULL) espconn_send(pespconn,"箱内二氧化碳浓度:000ppm",strlen("箱内二氧化碳浓度:000ppm"));
		else if(carbon != NULL) espconn_send(pespconn,"碰撞检测记录",strlen("碰撞检测记录"));
	}else
	{
		espconn_send(pespconn,Console_html,sizeof(Console_html));
	}
}

/**
  * @brief 本地服务器数据发送函数
  * @param arg 回调主体
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Send_Local(void *arg)
{
	os_printf("本地服务器发送数据成功！\r\n");
}
/******************************本地服务器相关函数-End******************************/

/******************************路由器连接相关函数-Start******************************/
/**
  * @brief Wifi扫描函数，AP模式使用
  * @param void
  * @return void
  */
void ICACHE_FLASH_ATTR
Wifi_Scan(void)
{
	wifi_station_scan(NULL,Wifi_Scan_Done);
}

/**
  * @brief Wifi扫描结束函数
  * @param arg 扫描结果
  * @param status 扫描状态
  * @return void
  */
static void ICACHE_FLASH_ATTR
Wifi_Scan_Done(void *arg,STATUS status)
{
	uint8 ssid[33];
	char temp[128];
	struct station_config stationConf;

	if (status == OK)
	{
		struct bss_info *bss_link = (struct bss_info *)arg;

		u8 wifiname[36]={0};
		u8 wifipw[36]={0};
		u8 SEC=125;
		u8 SEC_OFFSET = 0;

		bss_link = bss_link->next.stqe_next;//ignore first
		while (bss_link != NULL)
		{
			os_memset(ssid, 0, 33);

			if (os_strlen(bss_link->ssid) <= 32)
			{
				os_memcpy(ssid, bss_link->ssid, os_strlen(bss_link->ssid));
			}
			else
			{
				os_memcpy(ssid, bss_link->ssid, 32);
			}
			os_sprintf(temp,"+CWLAP:(%d,\"%s\",%d,\""MACSTR"\",%d)\r\n",
			bss_link->authmode, ssid, bss_link->rssi,
			MAC2STR(bss_link->bssid),bss_link->channel);
			os_printf("%s\r\n",temp);
			bss_link = bss_link->next.stqe_next;
		}
		SEC_OFFSET = 0;
		spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)wifiname, 36);
		SEC_OFFSET = 36;
		spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)wifipw, 36);

		os_memcpy(&stationConf.ssid, wifiname, 32);
		os_memcpy(&stationConf.password, wifipw, 64);
		wifi_station_set_config_current(&stationConf);
		wifi_station_connect();

		os_timer_setfn(&connect_timer,(ETSTimerFunc *) ( Wifi_Conned ),NULL);
		os_timer_arm(&connect_timer,10,true);
	}
	else
	{
		os_printf("%s","基站扫描失败！\r\n");
	}
}

/**
  * @brief Wifi连接函数
  * @param arg 回调主体
  * @param status 扫描状态
  * @return void
  */
static void ICACHE_FLASH_ATTR
Wifi_Conned(void *arg)
{
    static uint8 count=0;
    uint8 status;

    count++;
    status=wifi_station_get_connect_status();
    if(status==STATION_GOT_IP){
        os_printf("Wifi连接成功！\r\n");
        os_timer_disarm(&connect_timer);
        Server_Init_Remote();
    }else{
        if(count>=300){
            os_printf("Wifi连接失败！\r\n");
        }else
        {
        	os_timer_arm(&connect_timer,3000,true);
        }
    }
}
/******************************路由器连接相关函数-End******************************/

/******************************远程服务器相关函数-Start******************************/
/**
  * @brief 初始化远程服务器函数
  * @param void
  * @return void
  */
void ICACHE_FLASH_ATTR
Server_Init_Remote(void)
{
	//struct ip_info info; //用于获取IP地址的信息

	remote_server.proto.tcp = (esp_tcp *)os_zalloc(sizeof(esp_tcp));
	remote_server.type      = ESPCONN_TCP;
	remote_server.state     = ESPCONN_NONE;

	const char esp_tcp_server_ip[4] = {52,36,58,151}; // remote IP of TCP server

	//wifi_get_ip_info(STATION_IF,&info);

	memcpy(remote_server.proto.tcp->remote_ip, esp_tcp_server_ip, 4);
	remote_server.proto.tcp->remote_port = 1883;

	espconn_connect(&remote_server);

	Server_Scan_Remote();
}

/**
  * @brief 扫描远程连接
  * @param void
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Scan_Remote(void)
{
	espconn_regist_time(&remote_server, 120, 0);	//设置服务器超时时间为120秒
	espconn_regist_connectcb(&remote_server, Server_listen_Remote);	//连接成功回调
	espconn_accept(&remote_server);		//开启TCP服务器
}

/**
  * @brief 监听远程连接
  * @param void
  * @return void
  */
static void ICACHE_FLASH_ATTR Server_listen_Remote(void *arg)//服务器被链接回调
{
	struct espconn *pespconn = (struct espconn *)arg;

	os_timer_setfn(&mqtt_timer,MQTT_Send,NULL);
	//espconn_connect(&remote_server);
	//Server_Scan_Remote();
	//os_timer_setfn(&mqtt_timer,espconn_connect,NULL);
	os_timer_arm(&mqtt_timer,1000,true);

	espconn_regist_disconcb(pespconn,Server_Discon_Remote);//开启正常断开回调
	espconn_regist_reconcb(pespconn, Server_Recon_Remote);//开启异常断开回调
	espconn_regist_recvcb(pespconn, Server_Receive_Remote);//开启接收回调
	espconn_regist_sentcb(pespconn, Server_Send_Remote);//开启发送成功回调
}

/**
  * @brief 正常断开回调函数
  * @param arg 回调主体
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Discon_Remote(void *arg)
{
    uint8 status;
    MQTT_Flag = 0;
    //espconn_clear_opt(&remote_server,ESPCONN_REUSEADDR);

    if(remote_server.proto.tcp != NULL)
	{
    	os_printf("开始销毁内存\r\n");
		os_free(remote_server.proto.tcp);
	}

	//espconn_abort(&remote_server);
	//espconn_clear_opt(&remote_server,ESPCONN_START);
	//espconn_connect(&remote_server);
	//Server_Scan_Remote();

	//espconn_abort(&remote_server);

	//espconn_connect(&remote_server);
    status=wifi_station_get_connect_status();

    if(status==STATION_GOT_IP && remote_server.proto.tcp!=NULL){
    	os_printf("正在重连\r\n");
        //Server_Init_Remote();
    }
/*    while(espconn_clear_opt(&remote_server,ESPCONN_REUSEADDR))
	{
    	os_delay_us(100000);
    	os_printf("失败\r\n");
	}

    os_printf("成功\r\n");*/
	//espconn_clear_opt(&remote_server,ESPCONN_REUSEADDR);
    //espconn_delete(&remote_server);
/*	espconn_connect(&remote_server);
	Server_Scan_Remote();
	os_printf("正在重连\r\n");*/
	//espconn_connect(&remote_server);
	//Server_Scan_Remote();
    //Server_Init_Remote();
}

/**
  * @brief 异常断开回调函数
  * @param arg 回调主体
  * @param err 错误代码
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Recon_Remote(void *arg,sint8 err)
{
    os_printf("远程连接错误，错误代码为：%s\r\n",err);	//输出重新连接的错误代码
}

/**
  * @brief 远程服务器数据接收函数
  * @param arg 回调主体
  * @param pdata 接收到的数据指针
  * @param len 接收到的数据长度
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Receive_Remote(void *arg,char *pdata,unsigned short len)
{
	os_printf("收到远程服务器发来的数据：");

	//uart0_sendStr(pdata);//将客户端发过来的数据打印出来
	//uart0_tx_buffer(pdata, 27);
	//uart0_sendStr("\r\n");
	//uart0_sendStr(&pdata[12]);//将客户端发过来的数据打印出来

	if(pdata[25] == '0')
	{
		if(pdata[26] == '1')
		{
			USART0_TX_BUF[0] = 'o';
		}else
		{
			USART0_TX_BUF[0] = 'c';
		}
		uart0_SendPackage(USART0_TX_BUF, 2);
	}else if(pdata[25] == '1')
	{
		if(pdata[26] == '1')
		{
			USART0_TX_BUF[1] = 'o';
		}else
		{
			USART0_TX_BUF[1] = 'c';
		}
		uart0_SendPackage(USART0_TX_BUF, 2);
	}
}

/**
  * @brief 远程服务器数据发送函数
  * @param arg 回调主体
  * @return void
  */
static void ICACHE_FLASH_ATTR
Server_Send_Remote(void *arg)
{
	os_printf("向远程服务器发送数据成功！\r\n");
}
/******************************远程服务器相关函数-End******************************/
