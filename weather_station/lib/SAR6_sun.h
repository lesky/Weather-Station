//*****************************************************************************
//*****************************************************************************
//  FILENAME:  SAR6_sun.h
//  Version: 1.5, Updated on 2012/3/2 at 9:15:12
//  Generated by PSoC Designer 5.2.2551
//
//  DESCRIPTION:  SAR6 User Module C Language interface file.
//
//-----------------------------------------------------------------------------
//      Copyright (c) Cypress Semiconductor 2012. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef SAR6_sun_INCLUDE
#define SAR6_sun_INCLUDE

#include "m8c.h"

//-------------------------------------------------
// Defines for SAR6_sun API's.
//-------------------------------------------------
#define SAR6_sun_OFF         0
#define SAR6_sun_LOWPOWER    1
#define SAR6_sun_MEDPOWER    2
#define SAR6_sun_HIGHPOWER   3
#define SAR6_sun_FULLPOWER   3

//-------------------------------------------------
// Prototypes of the SAR6_sun API.
//-------------------------------------------------
#pragma fastcall16 SAR6_sun_Start
#pragma fastcall16 SAR6_sun_SetPower
#pragma fastcall16 SAR6_sun_cGetSample
#pragma fastcall16 SAR6_sun_Stop

extern void SAR6_sun_Start( BYTE bPowerSetting );
extern void SAR6_sun_SetPower( BYTE bPowerSetting );
extern CHAR SAR6_sun_cGetSample( void );
extern void SAR6_sun_Stop( void );

//--------------------------------------------------
// WARNING!  This function prototype will be removed
//           in a future version.
//--------------------------------------------------
#pragma fastcall16 SAR6_sun_GetSample
extern CHAR SAR6_sun_GetSample( void );

//-------------------------------------------------
// Register Addresses for SAR6_sun
//-------------------------------------------------
#pragma ioport  SAR6_sun_CR0:   0x084
BYTE            SAR6_sun_CR0;
#pragma ioport  SAR6_sun_CR1:   0x085
BYTE            SAR6_sun_CR1;
#pragma ioport  SAR6_sun_CR2:   0x086
BYTE            SAR6_sun_CR2;
#pragma ioport  SAR6_sun_CR3:   0x087
BYTE            SAR6_sun_CR3;

#endif
// end of file SAR6_sun.h