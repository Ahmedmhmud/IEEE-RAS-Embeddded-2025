/*
*<<<<<<<<<<ADC_program.c>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  MCAL
*   SWC     :  ADC
*
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

static u_16 * ADC_pu16AsynchConversionResult = NULL;
static void (* ADC_pvNotificationFunc)(void)= NULL;
static u_8 ADC_u8ISRState ;
static u_8 * ADC_pu8ChainChannel ;
static u_8 ADC_u8ChainSize ;
static u_8 ADC_u8Index ;
static u_8 ADC_u8State= IDLE ;

void ADC_voidInit(void)
{
	#if ADC_VREF == AREF
		CLR_BIT(ADMUXR, ADC_REF0) ;
		CLR_BIT(ADMUXR, ADC_REF1) ;
	#elif ADC_VREF == AVCC
		SET_BIT(ADMUXR, ADC_REF0) ;
		CLR_BIT(ADMUXR, ADC_REF1) ;
	#elif ADC_VREF == INTERNAL_2_56
		SET_BIT(ADMUXR, ADC_REF0) ;
		SET_BIT(ADMUXR, ADC_REF1) ;
	#endif


	#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
		CLR_BIT(ADMUXR, ADC_LAR) ;
	#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
		SET_BIT(ADMUXR, ADC_LAR) ;
	#endif 

	ADCSAR &= 0b11111000;
    ADCSAR |= ADC_PRESCALER;
	
	#if ADC_STATUS == ADC_DISABLE
		CLR_BIT(ADCSAR, ADC_EN) ;
	#elif ADC_STATUS == ADC_ENABLE
		SET_BIT(ADCSAR, ADC_EN) ;
	#endif 

	#if INT_STATUS == INT_DISABLE
		CLR_BIT(ADCSAR, ADC_IE) ;
	#elif INT_STATUS == INT_ENABLE
		SET_BIT(ADCSAR, ADC_IE) ;
	#endif 

}

void ADC_voidEnable           (void)
{
    SET_BIT(ADCSAR, ADC_EN);
}

void ADC_voidDisable          (void)
{
    CLR_BIT(ADCSAR, ADC_EN);
}
void ADC_voidInterruptEnable  (void)
{
    SET_BIT(ADCSAR, ADC_IE);
}

void ADC_voidInterruptDisable (void)
{
    CLR_BIT(ADCSAR, ADC_IE);
}

u_8 ADC_u8SetPrescaler (u_8 Copy_u8Prescaler)
{
    if(Copy_u8Prescaler < 7)
    {
        ADCSAR &= 0b11111000;
        ADCSAR |= Copy_u8Prescaler;
    }
}

u_8   ADC_u8GetResultSync ( u_8 Copy_u8Channel , u_16* Copy_pu16Result )
{
    u_8 errorState = OK;
    u_32 timeOut = 0;
    if( Copy_pu16Result != NULL)
    {
        if(ADC_u8State == IDLE)
        {
            ADC_u8State = BUSY;

            ADMUXR &= 0b11100000;
            ADMUXR |= Copy_u8Channel;

            SET_BIT(ADCSAR, ADC_SC);

            while((GET_BIT(ADCSAR, ADC_IF)) == 0 && timeOut < ADC_TIMEOUT)
            {
                timeOut++;
            }
            if(timeOut == ADC_TIMEOUT)
            {
                errorState = NOK;
            }
            else
            {
                SET_BIT(ADCSAR, ADC_IF);
                #if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
                    *Copy_pu16Result = (ADC_LR | (ADC_HR<<8));
                #elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
                    *Copy_pu16Result = ADC_HR;
                #endif

                ADC_u8State = IDLE;
            }
        }
        else
        {
            errorState = NOK;
        }
    }
    else
    {
        errorState = NOK;
    }
    return errorState;
}

u_8   ADC_u8StartConversionAsynch( u_8 Copy_u8Channel , u_16* Copy_pu16Reading , void(*Copy_pvNotificationFunc)(void) )
{
    u_8 errorState = OK;
    if(Copy_pu16Reading != NULL && Copy_pvNotificationFunc != NULL)
    {
        if(ADC_u8State == IDLE)
        {
            ADC_u8State = BUSY;
            ADC_u8ISRState = SINGLE_CHANNEL_ASYNCH;
            ADC_pu16AsynchConversionResult = Copy_pu16Reading;
            ADC_pvNotificationFunc = Copy_pvNotificationFunc;
            ADMUXR &= 0b11100000;
			ADMUXR |= Copy_u8Channel;
            SET_BIT(ADCSAR, ADC_SC);
            SET_BIT(ADCSAR, ADC_IE);
        }
        else
        {
            errorState = NOK;
        }
    }
    else
    {
        errorState = NOK;
    }
    return errorState;
}

u_8 ADC_u8StartChainAsynch (Chain_t * Copy_Chain)
{
	u_8 errorState = OK ;

	if ((Copy_Chain != NULL) && (Copy_Chain->Channel != NULL) && (Copy_Chain->NotificationFunc != NULL) && (Copy_Chain->Result))
	{
		if (ADC_u8State == IDLE)
		{
			ADC_u8State = BUSY ;

			ADC_u8ISRState = CHAIN_CHANNEL_ASYNCH ;

			ADC_pu16AsynchConversionResult = Copy_Chain->Result ;
			ADC_pu8ChainChannel = Copy_Chain->Channel ;
			ADC_u8ChainSize = Copy_Chain->Size ;
			ADC_pvNotificationFunc = Copy_Chain->NotificationFunc ;

			ADC_u8Index = 0 ;

			ADMUXR &= 0b11100000 ;
			ADMUXR |= ADC_pu8ChainChannel[ADC_u8Index] ;

			SET_BIT(ADCSAR , ADC_SC) ;
			SET_BIT(ADCSAR , ADC_IE) ;
		}
		else
		{
			errorState = NOK ;
		}
	}
	else
	{
		errorState = NOK ;
	}
	return errorState ;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
    if(ADC_u8ISRState == SINGLE_CHANNEL_ASYNCH)
    {
        #if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
            *ADC_pu16AsynchConversionResult = (ADC_LR | (ADC_HR<<8));
        #elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
            *ADC_pu16AsynchConversionResult = ADC_HR;
        #endif

        ADC_u8State = IDLE;

        ADC_pvNotificationFunc();
        CLR_BIT(ADCSAR, ADC_IE);
    }
    else
    {
        #if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
			*ADC_pu16AsynchConversionResult = (ADC_LR | (ADC_HR<<8));
		#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
			*ADC_pu16AsynchConversionResult = ADC_HR;
		#endif

		ADC_u8Index++ ;

		if (ADC_u8Index == ADC_u8ChainSize)
		{
			ADC_u8State = IDLE ;

			ADC_pvNotificationFunc() ;

            CLR_BIT(ADCSAR, ADC_IE);
        }
		else
		{
			ADMUXR &= 0b11100000;
			ADMUXR |= ADC_pu8ChainChannel[ADC_u8Index] ;

			SET_BIT(ADCSAR, ADC_SC);
		}
    }
}
