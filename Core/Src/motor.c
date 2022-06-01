/*
 * motor.c
 *
 *  Created on: Jun 1, 2022
 *      Author: dz
 */

#include "motor.h"


void motor_init(TIM_HandleTypeDef* timx, GPIO_TypeDef* gpiox){
	motor_timx = timx;
	motor_gpiox = gpiox;

	HAL_TIM_PWM_Start(motor_timx, MOTOR_ENA);
	HAL_TIM_PWM_Start(motor_timx, MOTOR_ENB);

	HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN1, RESET);
	HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN2, RESET);
	HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN3, RESET);
	HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN4, RESET);

}


void motor_write(uint8_t motor, int16_t speed){

	if(speed > MOTOR_MAXSPEED){
		speed = MOTOR_MAXSPEED;
	}
	else if(speed < MOTOR_MINSPEED){
		speed = MOTOR_MINSPEED;
	}


	if(motor == MOTOR1){
		if(speed >= 0){
			speed *= -1;
			HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN1, ENABLE);
			HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN2, RESET);
			__HAL_TIM_SetCompare(motor_timx,MOTOR_ENA,speed);

		}
		else{
			HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN1, RESET);
			HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN2, ENABLE);
			__HAL_TIM_SetCompare(motor_timx,MOTOR_ENA,speed);

		}
	}
	else if(motor == MOTOR2){
		if(speed >= 0){
					speed *= -1;
					HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN3, ENABLE);
					HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN4, RESET);
					__HAL_TIM_SetCompare(motor_timx,MOTOR_ENB,speed);

				}
		else{
					HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN3, ENABLE);
					HAL_GPIO_WritePin(motor_gpiox, MOTOR_EN4, RESET);
					__HAL_TIM_SetCompare(motor_timx,MOTOR_ENB,speed);

				}
	}






}

