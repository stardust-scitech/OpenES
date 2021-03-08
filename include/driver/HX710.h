/**
  ******************************************************************************
  * @file    HX710.h
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_03_08
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  * @brief   This file contains all the functions prototypes for the EC11_KNOB interface
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef __HX710_H
#define __HX710_H

#include "c_types.h"
#include "gpio.h"

#define HX710_SCK_MUX       PERIPHS_IO_MUX_MTDI_U
#define HX710_SCK_FUNC		FUNC_GPIO12
#define HX710_SCK_PIN		12

#define HX710_SDO_MUX       PERIPHS_IO_MUX_MTMS_U
#define HX710_SDO_FUNC		FUNC_GPIO14
#define HX710_SDO_PIN		14
 
u8  HX710_Init(void);
u32  HX710_Data_Read(void);

void Get_Gross(void);
u16 Get_Weight(void);

#endif /*__HX710_H*/
