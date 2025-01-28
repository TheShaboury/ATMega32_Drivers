/******************************************************************/
/******************************************************************/
/****************	  Author:  Ahmed Shaboury	*******************/
/****************	  Layer:   MCAL				*******************/
/****************	  SWC:     DIO				*******************/
/****************     Version: 1.00				*******************/
/******************************************************************/
/******************************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_u8PIN_OUTPUT		1
#define DIO_u8PIN_INPUT			0

#define DIO_u8PIN_HIGH			1
#define DIO_u8PIN_LOW			0

#define DIO_u8PORT_OUTPUT		0xff
#define DIO_u8PORT_INPUT		0

#define DIO_u8PORT_HIGH			0xff
#define DIO_u8PORT_LOW			0

#define DIO_u8PORTA				0
#define DIO_u8PORTB				1
#define DIO_u8PORTC				2
#define DIO_u8PORTD				3

#define DIO_u8PIN0				0
#define DIO_u8PIN1				1
#define DIO_u8PIN2				2
#define DIO_u8PIN3				3
#define DIO_u8PIN4				4
#define DIO_u8PIN5				5
#define DIO_u8PIN6				6
#define DIO_u8PIN7				7

uint8 DIO_u8SetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction);

uint8 DIO_u8SetPortDirection(uint8 Copy_u8Port, uint8 Copy_u8Direction);

uint8 DIO_u8SetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Value);

uint8 DIO_u8SetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Value);

uint8 DIO_u8GetPinValue(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8* Copy_pu8Value);


#endif
