/******************************************************************/
/******************************************************************/
/****************	  Author:  Ahmed Shaboury	*******************/
/****************	  Layer:   HAL				*******************/
/****************	  SWC:     LED				*******************/
/****************     Version: 1.00				*******************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

uint8 LED_u8TurnOn(LED_t* Copy_pLED)
{
	uint8 Local_u8ErrorState = 0;

	if (Copy_pLED != NULL)
	{
		if (Copy_pLED -> LED_u8Type == LED_u8SOURCE)
		{
			Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pLED -> LED_u8Port, Copy_pLED -> LED_u8Pin, DIO_u8PIN_OUTPUT);
			Local_u8ErrorState = DIO_u8SetPinValue(Copy_pLED -> LED_u8Port, Copy_pLED -> LED_u8Pin, DIO_u8PIN_HIGH);
		}
		else if (Copy_pLED -> LED_u8Type == LED_u8SINK)
		{
			Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pLED -> LED_u8Port, Copy_pLED -> LED_u8Pin, DIO_u8PIN_OUTPUT);
			Local_u8ErrorState = DIO_u8SetPinValue(Copy_pLED -> LED_u8Port, Copy_pLED -> LED_u8Pin, DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}

uint8 LED_u8TurnOff(LED_t* Copy_pLED)
{
	uint8 Local_u8ErrorState = 0;

	if (Copy_pLED != NULL)
	{
		if (Copy_pLED -> LED_u8Type == LED_u8SOURCE)
		{
			Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pLED -> LED_u8Port, Copy_pLED -> LED_u8Pin, DIO_u8PIN_OUTPUT);
			Local_u8ErrorState = DIO_u8SetPinValue(Copy_pLED -> LED_u8Port, Copy_pLED -> LED_u8Pin, DIO_u8PIN_LOW);
		}
		else if (Copy_pLED -> LED_u8Type == LED_u8SINK)
		{
			Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pLED -> LED_u8Port, Copy_pLED -> LED_u8Pin, DIO_u8PIN_OUTPUT);
			Local_u8ErrorState = DIO_u8SetPinValue(Copy_pLED -> LED_u8Port, Copy_pLED -> LED_u8Pin, DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState = 1;
		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}

	return Local_u8ErrorState;
}
