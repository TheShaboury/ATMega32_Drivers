/******************************************************************/
/******************************************************************/
/****************	  Author:  Ahmed Shaboury	*******************/
/****************	  Layer:   HAL				*******************/
/****************	  SWC:     SSD				*******************/
/****************     Version: 1.00				*******************/
/******************************************************************/
/******************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define SSD_u8ZERO			0
#define SSD_u8ONE			1
#define SSD_u8TWO			2
#define SSD_u8THREE			3
#define SSD_u8FOUR			4
#define SSD_u8FIVE			5
#define SSD_u8SIX			6
#define SSD_u8SEVEN			7
#define SSD_u8EIGHT			8
#define SSD_u8NINE			9

#define SSD_u8COM_CATHODE	0
#define SSD_u8COM_ANODE		1

typedef struct{
	uint8 SSD_u8COM_TYPE;
	uint8 SSD_u8PORT;
	uint8 SSD_u8ENABLE_PORT;
	uint8 SSD_u8ENABLE_PIN;
}SSD_t;

uint8 SSD_u8SetNumber(uint8 Copy_u8Number, SSD_t* Copy_pSSD);

uint8 SSD_u8Enable(SSD_t* Copy_pSSD);

uint8 SSD_u8Disable(SSD_t* Copy_pSSD);

#endif
