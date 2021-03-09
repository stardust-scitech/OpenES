/**
  ******************************************************************************
  * @file    user_http.h
  * @brief   This file contains all the functions prototypes for the business logic.
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_03_09
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  ******************************************************************************
  */

#ifndef _USER_HTTP_H
#define _USER_HTTP_H

#include "user_main.h"

void HttpPack(uint8 *target ,  uint8 *flag , uint8 *insert);
void HttpGet(u8 *target ,  u8 *flag_start , u8 *flag_end, u8 *value);

#endif
