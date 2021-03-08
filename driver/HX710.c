/**
  ******************************************************************************
  * @file    HX710.c
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_03_08
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  * @brief   This file provides all the HX710 firmware functions.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#include "HX710.h"
#include "gpio.h"
#include "eagle_soc.h"
#include "system.h"

#define HIGH 1
#define LOW 0

#define GapValue 231.1 //校准参数，因为不同的传感器特性曲线不是很一致，因此，每一个传感器需要矫正这里这个参数才能使测量值很准确。当发现测试出来的重量偏大时，增加该数值。如果测试出来的重量偏小时，减小改数值。


//u32 HX710_Value;

u64 Weight_Gross = 0; //电子秤毛重

/**
  * @brief Chip clock pin initialization
  * @param void
  * @return void
  * @note
  *      Internal function
  */
static void ICACHE_FLASH_ATTR
HX710_SCK_Set(u8 state)
{
    if(state == HIGH)
    {
    	GPIO_OUTPUT_SET(HX710_SCK_PIN, 1);
    }
    else
    {
    	GPIO_OUTPUT_SET(HX710_SCK_PIN, 0);
    }
}
 
/**
  * @brief Chip output pin initialization
  * @param void
  * @return void
  * @note
  *      Internal function
  */
static u8 ICACHE_FLASH_ATTR
HX710_SDO_Get(void)
{
    return GPIO_INPUT_GET(HX710_SDO_PIN);
}

 
/**
  * @brief Initialization of air pressure sensor chip
  * @param void
  * @return void
  */
u8 ICACHE_FLASH_ATTR
HX710_Init(void)
{
	u8 err=0;
    u8 i, j;

    /*SCK*/
	PIN_FUNC_SELECT(HX710_SCK_MUX, HX710_SCK_FUNC);
	PIN_PULLUP_DIS(HX710_SCK_MUX);

    /*SDO*/
	PIN_FUNC_SELECT(HX710_SDO_MUX, HX710_SDO_FUNC);
	GPIO_DIS_OUTPUT(HX710_SDO_PIN);
	PIN_PULLUP_DIS(HX710_SDO_MUX);

    return 0;
}
 
/**
  * @brief Obtain air pressure sensor readings
  * @param void
  * @return u32AdValue Air pressure sensor reading
  */
u32 ICACHE_FLASH_ATTR
HX710_Data_Read(void)
{
    u8  i;
    u32  u32AdValue = 0;
 
    HX710_SCK_Set(LOW);
 
    while (HX710_SDO_Get());

    for (i = 0; i < 24; i++)
    {
        HX710_SCK_Set(HIGH);
        delay_us(2);
        u32AdValue <<= 1;
        HX710_SCK_Set(LOW);
        delay_us(2);
        if(HX710_SDO_Get())
        {
            u32AdValue++;
        }
    }
 
    HX710_SCK_Set(HIGH);
    delay_us(2);
    HX710_SCK_Set(LOW);
    delay_us(2);
 
    HX710_SCK_Set(HIGH);
    delay_us(2);
    HX710_SCK_Set(LOW);
    delay_us(2);
 
    HX710_SCK_Set(HIGH);
    delay_us(2);
    HX710_SCK_Set(LOW);
    delay_us(2);
 
	u32AdValue ^= 0x800000; //u32AdValue与800000按位异或如果u32AdValue最高位是1（为负数）则 最高位置零 所以结果都是正数 。最高位取反后表示数值为0～16777215，没有负载时候显示为8388608，这样做的目的是避免出现负数，方便计算。

	return u32AdValue;
}

/**
  * @brief 获取电子秤视重
  * @void
  * @void
  */
u16 ICACHE_FLASH_ATTR
Get_Weight(void)
{
	static u8 Flag_ERROR = 0;
	long Weight_Net = 0;

	Weight_Net = HX710_Data_Read();
	Weight_Net -= Weight_Gross; //获取净重
	if(Weight_Net >= 0)
	{
		Weight_Net = (unsigned int)((float)Weight_Net/GapValue); //计算实物的实际重量


		if(Weight_Net > 5000) //超重报警
		{
			Flag_ERROR = 1;
		}
		else
		{
			Flag_ERROR = 0;
		}
	}
	else
	{
		Weight_Net = 0;
		Flag_ERROR = 2; //负重报警
	}

	return Weight_Net;
}

/**
  * @brief 获取电子秤毛重
  * @void
  * @void
  */
void ICACHE_FLASH_ATTR
Get_Gross(void)
{
	Weight_Gross = HX710_Data_Read();
}
