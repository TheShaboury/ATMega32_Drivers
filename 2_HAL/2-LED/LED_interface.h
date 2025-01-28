/******************************************************************/
/******************************************************************/
/****************	  Author:  Ahmed Shaboury	*******************/
/****************	  Layer:   HAL				*******************/
/****************	  SWC:     LED				*******************/
/****************     Version: 1.00				*******************/
/******************************************************************/
/******************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_u8ON			1
#define LED_u8OFF			0

#define LED_u8SOURCE		1
#define LED_u8SINK			0

typedef struct{
	uint8 LED_u8Port;
	uint8 LED_u8Pin;
	uint8 LED_u8Type;
}LED_t;

uint8 LED_u8TurnOn(LED_t* Copy_pLED);

uint8 LED_u8TurnOff(LED_t* Copy_pLED);

#endif
