/**
  ******************************************************************************
  * @file    user_server.h
  * @brief   This file contains all the functions prototypes for the business logic.
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_03_09
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  ******************************************************************************
  */

#ifndef __USER_SERVER_H
#define __USER_SERVER_H

#include "user_main.h"
#include "ip_addr.h"

//#define DeviceId "20011401"
//#define DevicePass "A34S1234"
extern u8 SEC;
extern u8 SsidLocal[32], PasswordLocal[32];

extern struct espconn remote_server;

void Wifi_Scan(void);

void Server_Init_Local(void);
void Server_Init_Remote(void);

#endif/*__USER_SERVER_H*/
