/**
  ******************************************************************************
  * @file    user_mqtt.c
  * @brief   This file provides all the business logic functions.
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_03_09
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  ******************************************************************************
  */

#include "user_mqtt.h"
#include "user_server.h"

#include "c_types.h"
#include "ip_addr.h"
#include "espconn.h"
#include "mem.h"
#include "osapi.h"

u8 MQTT_Flag;

static u8 MQTTConnet[]=
{
	0x10, 0x14, 0x00, 0x04, 0x4d, 0x51, 0x54, 0x54, 0x04, 0x02,
	0x00, 0x3c, 0x00, 0x08, 0x38, 0x31, 0x34, 0x31, 0x30, 0x30,
	0x30, 0x32,
};

static u8 MQTTPublish[]=
{
	0x30, 0x19, 0x00, 0x15, 0x53, 0x5f, 0x4d, 0x5f, 0x38, 0x31,
	0x34, 0x31, 0x30, 0x30, 0x30, 0x32, 0x5f, 0x37, 0x53, 0x59,
	0x4a, 0x61, 0x73, 0x37, 0x33, 0x41, 0x42,
};

static u8 MQTTSubscribe[]=
{
	0x82, 0x1a, 0x00, 0x01, 0x00, 0x15, 0x53, 0x5f, 0x43, 0x5f,
	0x38, 0x31, 0x34, 0x31, 0x30, 0x30, 0x30, 0x32, 0x5f, 0x37,
	0x53, 0x59, 0x4a, 0x61, 0x73, 0x37, 0x33, 0x00,
};

/**
  * @brief MQTT初始化函数
  * @param DeviceId 设备ID
  * @return void
  */
void ICACHE_FLASH_ATTR MQTT_Init(u8 *DeviceId)
{
/*	int i;
	u8 SEC_OFFSET =  0;       //扇区内偏移量（必须是4的倍数）
	u8 *value;
	u8 SEC=123;*/
	u8 DevicePass[]="00000000";
	u8 SEC=124;
	u8 SEC_OFFSET = 0;
	u8 i,size;
	//DeviceStorage[0]=65;

	//spi_flash_erase_sector(SEC);
	//spi_flash_write(SEC*4*1024+SEC_OFFSET, (uint32 *)DeviceId,strlen(DeviceId));
	//spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)DeviceId, 8);
	//SEC=124;
	DigitalEncryption(DeviceId);
	//spi_flash_read(123*4*1024+0, (uint32 *)value, 8);
	//spi_flash_read(123*4*1024+0, (uint32 *)value, 8);

	spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)DevicePass, 8);

	size = sizeof(MQTTConnet);
	for(i=0;i<8;i++)
	{
		MQTTConnet[size-8+i] = DeviceId[i];
		//uart_tx_one_char(UART0, MQTTPublish[size-19+i]);
	}
	//uart_tx_one_char(UART0, size);
	size = sizeof(MQTTPublish);
	for(i=0;i<8;i++)
	{
		MQTTPublish[size-19+i] = DeviceId[i];
		//uart_tx_one_char(UART0, MQTTPublish[size-19+i]);
	}
	for(i=0;i<8;i++)
	{
		MQTTPublish[size-10+i] = DevicePass[i];
		//uart_tx_one_char(UART0, MQTTPublish[size-10+i]);
	}

	size = sizeof(MQTTSubscribe);
	for(i=0;i<8;i++)
	{
		MQTTSubscribe[size-18+i] = DeviceId[i];
		//uart_tx_one_char(UART0, MQTTSubscribe[size-18+i]);
	}
	for(i=0;i<8;i++)
	{
		MQTTSubscribe[size-9+i] = DevicePass[i];
		//uart_tx_one_char(UART0, MQTTSubscribe[size-9+i]);
	}
}

/**
  * @brief MQTT连接函数
  * @param arg TCP连接主体
  * @return void
  */
void ICACHE_FLASH_ATTR MQTT_Connet(void *arg)
{

	espconn_send((struct espconn *)arg,MQTTConnet,sizeof(MQTTConnet));//往客户机发送数据
}

/**
  * @brief MQTT发布函数
  * @param arg TCP连接主体
  * @return void
  */
void ICACHE_FLASH_ATTR MQTT_Publish(void *arg)
{

/*	spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)value, 8);

	for(i=i=strlen(send)-19;i<8;i++)
	{
		send[i] = value[i];
	}

	SEC_OFFSET = 8;
	SEC = 124;
	spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)value, 8);
	for(i=strlen(send)-10;i<8;i++)
	{
		send[i] = value[i];
	}*/

	//uart0_tx_buffer(MQTTPublish, sizeof(MQTTPublish));

	//uart0_sendStr("ABCDE");

	MQTTPublish[sizeof(MQTTPublish)-2] = USART0_RX_BUF[0];
	MQTTPublish[sizeof(MQTTPublish)-1] = USART0_RX_BUF[1];

	espconn_send((struct espconn *)arg,MQTTPublish,sizeof(MQTTPublish));//往客户机发送数据
}

/**
  * @brief MQTT订阅函数
  * @param arg TCP连接主体
  * @return void
  */
void ICACHE_FLASH_ATTR MQTT_Subscribe(void *arg)
{

	espconn_send((struct espconn *)arg,MQTTSubscribe,sizeof(MQTTSubscribe));//往客户机发送数据
}


/**
  * @brief MQTT数据发送协议
  * @param pdata Http数据指针
  * @return 0/1 初次登录/非初次登录
  */
void ICACHE_FLASH_ATTR
MQTT_Send(void *arg)
{
	static u8 count = 1;


	//Server_Scan_Remote();

	if(MQTT_Flag) count = 1;

	if(count == 1)
	{
		MQTT_Connet(&remote_server);
	}

	if(count == 2)
	{
		MQTT_Subscribe(&remote_server);
	}

	if(count == 3)
	{
		MQTT_Publish(&remote_server);
		MQTT_Flag  = 0;
	}
	if(count < 3)count++;
}
