/*
 * motor.h
 *
 *  Created on: Jun 1, 2022
 *      Author: dz
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f4xx.h"

#define MOTOR1			5
#define MOTOR_ENA 		TIM_CHANNEL_1
#define MOTOR_EN1		GPIO_PIN_4
#define MOTOR_EN2		GPIO_PIN_5

#define MOTOR2			6
#define MOTOR_ENB		TIM_CHANNEL_2
#define MOTOR_EN3		GPIO_PIN_8
#define MOTOR_EN4		GPIO_PIN_9

#define MOTOR_MAXSPEED		100
#define MOTOR_MINSPEED		-100

TIM_HandleTypeDef* motor_timx;
GPIO_TypeDef* motor_gpiox;


void motor_init(TIM_HandleTypeDef* timx, GPIO_TypeDef* gpiox);


void motor_write(uint8_t motor, int16_t speed);







#endif /* INC_MOTOR_H_ */
