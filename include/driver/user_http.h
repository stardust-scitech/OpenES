/**
*http.h
**/
#ifndef _USER_HTTP_H
#define _USER_HTTP_H

#include "user_main.h"

void HttpPack(uint8 *target ,  uint8 *flag , uint8 *insert);
void HttpGet(u8 *target ,  u8 *flag_start , u8 *flag_end, u8 *value);

#endif
