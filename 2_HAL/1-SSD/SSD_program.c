/******************************************************************/
/******************************************************************/
/****************	  Author:  Ahmed Shaboury	*******************/
/****************	  Layer:   HAL				*******************/
/****************	  SWC:     SSD				*******************/
/****************     Version: 1.00				*******************/
/******************************************************************/
/******************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

uint8 SSD_u8SetNumber(uint8 Copy_u8Number, SSD_t* Copy_pSSD)
{
	uint8 Local_u8ErrorState = 0;

	if (Copy_pSSD != NULL && Copy_u8Number >= SSD_u8ZERO && Copy_u8Number <= SSD_u8NINE)
	{
		if (Copy_pSSD -> SSD_u8COM_TYPE == SSD_u8COM_CATHODE)
		{
			Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, DIO_u8PIN_OUTPUT);
			Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, DIO_u8PIN_HIGH);
			Local_u8ErrorState = DIO_u8SetPortDirection(Copy_pSSD -> SSD_u8PORT, DIO_u8PORT_OUTPUT);
			Local_u8ErrorState = DIO_u8SetPortValue(Copy_pSSD -> SSD_u8PORT, SSD_u8NumArray[Copy_u8Number]);

		}
		else if (Copy_pSSD -> SSD_u8COM_TYPE == SSD_u8COM_ANODE)
		{
			Local_u8ErrorState = DIO_u8SetPinDirection(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, DIO_u8PIN_OUTPUT);
			Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, DIO_u8PIN_LOW);
			Local_u8ErrorState = DIO_u8SetPortDirection(Copy_pSSD -> SSD_u8PORT, DIO_u8PORT_OUTPUT);
			Local_u8ErrorState = DIO_u8SetPortValue(Copy_pSSD -> SSD_u8PORT, SSD_u8NumArray[Copy_u8Number]);
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

uint8 SSD_u8Enable(SSD_t* Copy_pSSD)
{
	uint8 Local_u8ErrorState = 0;
	uint8 Local_u8EnablePinValue = 0;

	if (Copy_pSSD != NULL)
	{
		Local_u8ErrorState = DIO_u8GetPinValue(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, &Local_u8EnablePinValue);

		if (Copy_pSSD -> SSD_u8COM_TYPE == SSD_u8COM_CATHODE)
		{
			if (Local_u8EnablePinValue)
			{
				Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, DIO_u8PIN_LOW);
			}
		}
		else if (Copy_pSSD -> SSD_u8COM_TYPE == SSD_u8COM_ANODE)
		{
			if (!Local_u8EnablePinValue)
			{
				Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, DIO_u8PIN_HIGH);
			}
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

uint8 SSD_u8Disable(SSD_t* Copy_pSSD)
{
	uint8 Local_u8ErrorState = 0;
	uint8 Local_u8EnablePinValue = 0;

	if (Copy_pSSD != NULL)
	{
		Local_u8ErrorState = DIO_u8GetPinValue(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, &Local_u8EnablePinValue);

		if (Copy_pSSD -> SSD_u8COM_TYPE == SSD_u8COM_CATHODE)
		{
			if (!Local_u8EnablePinValue)
			{
				Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, DIO_u8PIN_HIGH);
			}
		}
		else if (Copy_pSSD -> SSD_u8COM_TYPE == SSD_u8COM_ANODE)
		{
			if (Local_u8EnablePinValue)
			{
				Local_u8ErrorState = DIO_u8SetPinValue(Copy_pSSD -> SSD_u8ENABLE_PORT, Copy_pSSD -> SSD_u8ENABLE_PIN, DIO_u8PIN_LOW);
			}
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
