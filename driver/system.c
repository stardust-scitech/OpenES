/**
  ******************************************************************************
  * @file    system.c
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_01_23
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  * @brief   This file provides all the HX710 firmware functions.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#include "system.h"
#include "osapi.h"
#include "c_types.h"

/**
  * @brief 延时，单位微秒
  * @param nus 延时微秒数
  * @return void
  */
void ICACHE_FLASH_ATTR
delay_us(u32 nus)
{
	os_delay_us(nus);
}

/**
  * @brief 延时，单位毫秒
  * @param nms 延时毫秒数
  * @return void
  */
void ICACHE_FLASH_ATTR
delay_ms(u16 nms)
{
	os_delay_us(1000*nms);
}

/**
  * @brief 产生指定长度的随机字符串（英文字母、数字）
  * @param target 目标指针
  * @return length 随机字符串长度
  * @note target应当申请比参数length多一位的空间
  */
void ICACHE_FLASH_ATTR
MakeRandStr(u8 *target, int length)
{
    u8 flag, i;
    srand((unsigned) time(NULL));
    for (i = 0; i < length; i++){
        flag = rand();
        switch (flag % 3){
            case 0:
                target[i] = 'A' + flag % 26;
                break;
            case 1:
                target[i] = 'a' + flag % 26;
                break;
            case 2:
                target[i] = '0' + flag % 10;
                break;
            default:
                break;
        }
    }
    target[length] = '\0';
}

/**
  * @brief 数字加密函数
  * @param target 需要加密的字符串
  * @return void
  */
void ICACHE_FLASH_ATTR
DigitalEncryption(u8 *target)
{
	u8 temp3=target[3], temp4=target[4], temp5=target[5];

	int n;
    int i;
    u8 temp;

	target[3] = target[6];
	target[4] = target[7];
	target[5] = temp3;
	target[6] = temp4;
	target[7] = temp5;

    n=strlen(target);
    for(i=0;i<(n/2);i++){
        temp=target[i];
        target[i]=target[n-i-1];
        target[n-i-1]=temp;
    }
}
