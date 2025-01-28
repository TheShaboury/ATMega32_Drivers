/******************************************************************/
/******************************************************************/
/****************	  Author:  Ahmed Shaboury	*******************/
/****************	  Layer:   HAL				*******************/
/****************	  SWC:     SW				*******************/
/****************     Version: 1.00				*******************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_config.h"
#include "SW_private.h"

uint8 SW_u8GetState(SW_t* Copy_pSW, uint8* Copy_pu8State)
{
	uint8 Local_u8ErrorState = 0;

	if ((Copy_pSW != NULL) && (Copy_pu8State != NULL))
	{
		if (Copy_pSW -> SW_u8PullType == SW_u8PULL_UP)
		{
			Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pSW -> SW_u8Port, Copy_pSW -> SW_u8Pin, DIO_u8PIN_INPUT);
			Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSW -> SW_u8Port, Copy_pSW -> SW_u8Pin, DIO_u8PIN_HIGH);
			Local_u8ErrorState = DIO_u8GetPinValue(Copy_pSW -> SW_u8Port, Copy_pSW -> SW_u8Pin, Copy_pu8State);
		}
		else if (Copy_pSW -> SW_u8PullType == SW_u8PULL_DOWN)
		{
			Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pSW -> SW_u8Port, Copy_pSW -> SW_u8Pin, DIO_u8PIN_INPUT);
			Local_u8ErrorState = DIO_u8GetPinValue(Copy_pSW -> SW_u8Port, Copy_pSW -> SW_u8Pin, Copy_pu8State);
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
