/**
  ******************************************************************************
  * @file OLED.h
  * @author Kevin Brooks
  * @version 1.0.0
  * @date 2019-12-29
  * @email fanchen995@gmail.com
  * @license Copyright (C) 2016, Stardust Studio,  All Rights Reserved
  * @brief   This file contains all the functions prototypes for the OLED interface
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef __OLED_H
#define	__OLED_H

#include "c_types.h"

extern u8 OLED_GRAM[128][8];
extern const unsigned char F6x8[][6];
extern const unsigned char F8X16[];

#define OLED_DISPLAY_TYPE 0

//#define OLED_SCL_MUX 		PERIPHS_IO_MUX_GPIO5_U
//#define OLED_SCL_FUNC		FUNC_GPIO5
//#define OLED_SCL_PIN		5
//
//#define OLED_SDA_MUX 		PERIPHS_IO_MUX_GPIO4_U
//#define OLED_SDA_FUNC		FUNC_GPIO4
//#define OLED_SDA_PIN		4

#define OLED_ADDRESS	0x78 //By adjusting 0r resistance, the screen can have two addresses 0x78 and 0x7a -- default 0x78

typedef enum 
{
	LEFT, 
	RIGHT,
	CENTER
}OLED_ALIGNMENT;

typedef enum 
{
	NORMAL, 
	INVERSE 
}OLED_DISPLAY;

void OLED_SetPos(u8 x, u8 y);
void WriteDat(u8 I2C_Data, u8 t);
extern u8 G_X_Pointer, G_Y_Pointer;

void OLED_Init(void);
void OLED_BrightnessAdjustment(u8 val);

void OLED_ON(void);
void OLED_OFF(void);

void OLED_Fill(u8 fill_Data);
void OLED_Refresh_Gram(void);

void OLED_CLS(void);

void OLED_DrawPoint(int16_t x,int16_t y,u8 t);

void OLED_ShowStr(u8 x, u8 y, u8 ch[], OLED_ALIGNMENT mode, u8 TextSize, OLED_DISPLAY type);
void OLED_ShowInt(u8 x, u8 y,int number, OLED_ALIGNMENT mode, u8 TextSize, OLED_DISPLAY type);
void OLED_ShowStrInt(u8 x, u8 y, u8 ch[], int number, OLED_ALIGNMENT mode, u8 TextSize, OLED_DISPLAY type);
void OLED_ShowFloat(u16 x, u16 y, double dat, u8 num, u8 pointnum, u8 TextSize);
void OLED_ShowCN(u8 x, u8 y, u8 N);
void OLED_ShowBMP(u8 x0,u8 y0,u8 x1,u8 y1,u8 BMP[]);
void OLED_DrawPicture(u8 x, u8 y, u8 width, u8 length, u8 bmp[]);
void OLED_ShowBinary(u16 high, u16 width, u8 *p, u8 value);

void OLED_DisplayAdjustment(OLED_DISPLAY type);

#endif /*__OLED_H*/
