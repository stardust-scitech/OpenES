/**
  ******************************************************************************
  * @file    system.h
  * @brief   This file contains all the functions prototypes for the business logic.
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_01_23
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  ******************************************************************************
  */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "c_types.h"

void delay_us(u32 nus);
void delay_ms(u16 nms);

void MakeRandStr(u8 *target, int length);
void DigitalEncryption(u8 *target);

#endif /* SYSTEM_H_ */
