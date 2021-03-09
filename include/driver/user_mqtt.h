/**
  ******************************************************************************
  * @file    user_mqtt.h
  * @brief   This file contains all the functions prototypes for the business logic.
  * @author  Kevin Brooks
  * @version 1.0
  * @date    2021_03_09
  * @email   kevin@stardust.live
  * @license Copyright (C) 2018, Stardust Studio,  All Rights Reserved
  ******************************************************************************
  */

#ifndef __USER_MQTT_H
#define __USER_MQTT_H

#include "user_main.h"

extern u8 MQTT_Flag;

#define MQTT_HOST            " " // the IP address or domain name of your MQTT server or MQTT broker ,such as "mqtt.yourdomain.com"
#define MQTT_PORT            1883    // the listening port of your MQTT server or MQTT broker
#define MQTT_CLIENT_ID       " "    // the ID of yourself, any string is OK,client would use this ID register itself to MQTT server
#define MQTT_USER            " " // your MQTT login name, if MQTT server allow anonymous login,any string is OK, otherwise, please input valid login name which you had registered
#define MQTT_PASS            " " // you MQTT login password, same as above

void MQTT_Init(u8 *DeviceId);
void MQTT_Connet(void *arg);
void MQTT_Publish(void *arg);
void MQTT_Subscribe(void *arg);

void MQTT_Send(void *arg);

#endif /*__USER_MQTT_H*/
