//----------------------------------------------------------------------------
// Ports:
// P0_0 = MCLK
// P0_1 = XCLR adc reset
// P0_2 = Button SW
// P0_3 = windspeed input
// P0_4 = sunlight (solar) input
// P0_5 = rainsensor input
// P0_6 = I2C SDA
// P0_7 = I2C SCL
// P1_0 = Gray Code
// P1_1 = Gray Code
// P1_1 = Gray Code
// P2 = LCD
//----------------------------------------------------------------------------

#define LCD_LENGTH 16 // 16 plus \0 termination?

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include <stdio.h>

#include "sunsensor.h"
/*
typedef enum {
	overview = 0,
	temp = 1,
	humidity = 2,
	rain = 3,
	wind = 4,
} MODE;*/

void main(void)
{
	//Variables
	char lcdFirstLine[LCD_LENGTH], lcdSecondLine[LCD_LENGTH];
	unsigned int displaymode = 3; // FIXME: sollte 0 sein!
	
	/** init **/
	
	// interrupt and SleepTimer init
	M8C_EnableGInt ;                            // Turn on interrupts
	SleepTimer_Start();
    SleepTimer_SetInterval(SleepTimer_8_HZ);    // Set interrupt to a
    SleepTimer_EnableInt();                     // 8 Hz rate
	
	// init PGA and SAR6 for sun and rain sensor
	PGA_sun_SetGain(PGA_sun_G5_33);  // gain of 5,33
    PGA_sun_Start(PGA_sun_HIGHPOWER);
	//PGA_rain_SetGain(PGA_rain_G8_00);
    //PGA_rain_Start(PGA_rain_MEDPOWER);
	SAR6_sun_Start(SAR6_sun_HIGHPOWER);
	//SAR6_rain_Start(SAR6_sun_MEDPOWER);

	// LCD init
	LCD_Init();
	
	// print welcome screen to LCD
	csprintf(lcdFirstLine,"   Welcome to   ");
	csprintf(lcdSecondLine, " Weatherstation ");
	LCD_Position(0,0);
	LCD_PrString(lcdFirstLine);
	LCD_Position(1,0);
	LCD_PrString(lcdSecondLine);
	
	while(1) {
		// get temp and humidity here
		
		switch(displaymode) {
			case 0:
				// overview();
				break;
				
			case 1:
				// temp();
				break;
				
			case 2:
				// humidity();
				break;
				
			case 3:
				sunsensor(lcdFirstLine, lcdSecondLine);
				break;
				
			case 4:
				// wind();
				break;
		
			default:
				displaymode = 0;
				csprintf(lcdFirstLine,"     Error      ");
				csprintf(lcdSecondLine,"                ");
		}
		
		// lets see what we've got
		LCD_Position(0,0);
		LCD_PrString(lcdFirstLine);
		LCD_Position(1,0);
		LCD_PrString(lcdSecondLine);
		
		// lets sleep for a while
		SleepTimer_SyncWait(8, SleepTimer_WAIT_RELOAD);
	}
}
