/**
  ******************************************************************************
  * @file    user_main.c
  * @brief   This file provides all the business logic functions.
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_03_07
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  ******************************************************************************
  */

#include "user_main.h"

os_timer_t	HX710_Os_Timer; //定义HX710定时器

/**
  * @brief HX710定时任务，用来定时读取和显示电子秤读数
  * @param void
  * @return void
  */
void ICACHE_FLASH_ATTR
HX710_Os_Timer_Task(void)
{
	static u8 add = 0;
	static u16 val_cur=0;
	static u8 val_pre_count=0;
	u8 val_cur_count=0;
	u8 i;
	u16 weight;

	weight = Get_Weight(); //获取电子秤称量结果

	/*为了使得OLED动态刷新时不闪烁*/
	val_cur = weight;
	while(val_cur)
	{
		val_cur /= 10;
		val_cur_count++;
	}
	if(val_cur_count<val_pre_count)
	{
		for(i=0; i<(val_pre_count-val_cur_count); i++)
		{
			OLED_ShowStr(6*(i+val_cur_count), 2, " ", 1);
		}
	}
	val_pre_count = val_cur_count;

	/*显示电子秤示数和摄像头传输的数据*/
	OLED_ShowStr(0, 0, "weight:", 1);
	OLED_6x8Int(0, 2, weight);
	OLED_ShowStr(0, 4, "color:", 1);
	OLED_6x8Int(0, 6, USART0_RX_BUF[0]);
}

/**
  * @brief 主函数
  * @param void
  * @return void
  */
void ICACHE_FLASH_ATTR
user_init(void)
{
	u8 ssid[36] = {0}; //本地服务器名称
	u8 pass[36] = {0}; //本地服务器密码
	u8 SEC = 126; //扇区编号
	u8 SEC_OFFSET = 0; //扇区偏移

	system_soft_wdt_stop(); //关闭软件看门狗

    uart0_init(115200); //串口初始化

	/*预设是否开启调试模式*/
#if !DEBUG
	system_set_os_print(0);
#endif

	/*初始化电子秤*/
	HX710_Init();
	Get_Maopi(); //称毛皮重量

	/*初始化显示屏*/
	i2c_master_gpio_init();
	OLED_Init();
	OLED_ShowStr(0, 3, "System Start", 2);
	os_delay_us(100000);
	os_delay_us(100000);
	os_delay_us(100000);
	os_delay_us(100000);
	OLED_CLS();

    /*获取flash存储的本地路由器和名称和密码*/
	SEC_OFFSET = 0;
	spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)ssid, 36);
	SEC_OFFSET = 36;
	spi_flash_read(SEC*4*1024+SEC_OFFSET, (uint32 *)pass, 36);

	/*判断是否写入过本地路由器和名称和密码*/
	if(strlen(ssid)>0 && strlen(ssid)<36 && strlen(pass)>0 && strlen(pass)<36)
	{
		strcpy(SsidLocal, ssid);
		strcpy(PasswordLocal, pass);
	}

	/*设置Station+SoftAP模式，即STA+AP*。串口打印输出当前模式*/
	wifi_set_opmode(0x03);
    os_printf("\r\n当前的工作模式:%d\r\n", wifi_get_opmode_default());

	Server_Init_Local(); //开启本地服务器

	/*开启HX710重复定时任务*/
	os_timer_setfn(&HX710_Os_Timer, (os_timer_func_t *)HX710_Os_Timer_Task, NULL);
	os_timer_arm(&HX710_Os_Timer, 200, 1);

	system_init_done_cb(To_Scan);	//系统初始化完成之后扫描WiFi
}

/**********初始化内存分配-Start**********/
#define SPI_FLASH_SIZE_MAP 4

#if ((SPI_FLASH_SIZE_MAP == 0) || (SPI_FLASH_SIZE_MAP == 1))
#error "The flash map is not supported"
#elif (SPI_FLASH_SIZE_MAP == 2)
#define SYSTEM_PARTITION_OTA_SIZE							0x6A000
#define SYSTEM_PARTITION_OTA_2_ADDR							0x81000
#define SYSTEM_PARTITION_RF_CAL_ADDR						0xfb000
#define SYSTEM_PARTITION_PHY_DATA_ADDR						0xfc000
#define SYSTEM_PARTITION_SYSTEM_PARAMETER_ADDR				0xfd000
#define SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM_ADDR           0x7c000
#elif (SPI_FLASH_SIZE_MAP == 3)
#define SYSTEM_PARTITION_OTA_SIZE							0x6A000
#define SYSTEM_PARTITION_OTA_2_ADDR							0x81000
#define SYSTEM_PARTITION_RF_CAL_ADDR						0x1fb000
#define SYSTEM_PARTITION_PHY_DATA_ADDR						0x1fc000
#define SYSTEM_PARTITION_SYSTEM_PARAMETER_ADDR				0x1fd000
#define SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM_ADDR           0x7c000
#elif (SPI_FLASH_SIZE_MAP == 4)
#define SYSTEM_PARTITION_OTA_SIZE							0x6A000
#define SYSTEM_PARTITION_OTA_2_ADDR							0x81000
#define SYSTEM_PARTITION_RF_CAL_ADDR						0x3fb000
#define SYSTEM_PARTITION_PHY_DATA_ADDR						0x3fc000
#define SYSTEM_PARTITION_SYSTEM_PARAMETER_ADDR				0x3fd000
#define SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM_ADDR           0x7c000
#elif (SPI_FLASH_SIZE_MAP == 5)
#define SYSTEM_PARTITION_OTA_SIZE							0x6A000
#define SYSTEM_PARTITION_OTA_2_ADDR							0x101000
#define SYSTEM_PARTITION_RF_CAL_ADDR						0x1fb000
#define SYSTEM_PARTITION_PHY_DATA_ADDR						0x1fc000
#define SYSTEM_PARTITION_SYSTEM_PARAMETER_ADDR				0x1fd000
#define SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM_ADDR           0xfc000
#elif (SPI_FLASH_SIZE_MAP == 6)
#define SYSTEM_PARTITION_OTA_SIZE							0x6A000
#define SYSTEM_PARTITION_OTA_2_ADDR							0x101000
#define SYSTEM_PARTITION_RF_CAL_ADDR						0x3fb000
#define SYSTEM_PARTITION_PHY_DATA_ADDR						0x3fc000
#define SYSTEM_PARTITION_SYSTEM_PARAMETER_ADDR				0x3fd000
#define SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM_ADDR           0xfc000
#else
#error "The flash map is not supported"
#endif

#define SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM                SYSTEM_PARTITION_CUSTOMER_BEGIN

static const partition_item_t at_partition_table[] = {
    { SYSTEM_PARTITION_BOOTLOADER, 						0x0, 												0x1000},
    { SYSTEM_PARTITION_OTA_1,   						0x1000, 											SYSTEM_PARTITION_OTA_SIZE},
    { SYSTEM_PARTITION_OTA_2,   						SYSTEM_PARTITION_OTA_2_ADDR, 						SYSTEM_PARTITION_OTA_SIZE},
    { SYSTEM_PARTITION_RF_CAL,  						SYSTEM_PARTITION_RF_CAL_ADDR, 						0x1000},
    { SYSTEM_PARTITION_PHY_DATA, 						SYSTEM_PARTITION_PHY_DATA_ADDR, 					0x1000},
    { SYSTEM_PARTITION_SYSTEM_PARAMETER, 				SYSTEM_PARTITION_SYSTEM_PARAMETER_ADDR, 			0x3000},
    { SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM,             SYSTEM_PARTITION_CUSTOMER_PRIV_PARAM_ADDR,          0x1000},
};

void ICACHE_FLASH_ATTR user_pre_init(void)
{
    if(!system_partition_table_regist(at_partition_table, sizeof(at_partition_table)/sizeof(at_partition_table[0]),SPI_FLASH_SIZE_MAP)) {
		os_printf("system_partition_table_regist fail\r\n");
		while(1);
	}
}
/**********初始化内存分配-End**********/
