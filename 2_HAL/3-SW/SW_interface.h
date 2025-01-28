/******************************************************************/
/******************************************************************/
/****************	  Author:  Ahmed Shaboury	*******************/
/****************	  Layer:   HAL				*******************/
/****************	  SWC:     SW				*******************/
/****************     Version: 1.00				*******************/
/******************************************************************/
/******************************************************************/

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#define SW_u8PULL_UP					1
#define SW_u8PULL_DOWN					0

#define SW_u8PULL_UP_PRESSED			0
#define SW_u8PULL_UP_NOT_PRESSED		1

#define SW_u8PULL_DOWN_PRESSED			1
#define SW_u8PULL_DOWN_NOT_PRESSED		0

typedef struct{
	uint8 SW_u8Port;
	uint8 SW_u8Pin;
	uint8 SW_u8PullType;
}SW_t;

uint8 SW_u8GetState(SW_t* Copy_pSW, uint8* Copy_pu8State);

#endif
