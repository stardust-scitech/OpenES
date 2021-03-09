/*
 * system.h
 *
 *  Created on: 2021年1月23日
 *      Author: kevin
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "c_types.h"

void delay_us(u32 nus);
void delay_ms(u16 nms);

void MakeRandStr(u8 *target, int length);
void DigitalEncryption(u8 *target);

#endif /* SYSTEM_H_ */
