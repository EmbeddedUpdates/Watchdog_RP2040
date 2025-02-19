/**
 * 
* @file "Watchdog_RP2040.h"
* @author Madrick3
* @brief Stub for Timer implementation
* 
* @COMPONENT: Watchdog_RP2040
* @VERSION: 00.00.00
*/
/************************************************************
  Version History
  -----------------------------------------------------------
  Revision |  Author   |  Change ID  |  Description
  00.00.00 |  AUTHOR   |  DRAFT      |  Initial Creation
************************************************************/
#ifndef WATCHDOG_RP2040_H
#define WATCHDOG_RP2040_H
/************************************************************
  DEFINES
************************************************************/

typedef enum Watchdog_RP2040_Status_Tag {
  WATCHDOG_RP2040_UNINIT = 0,
  WATCHDOG_RP2040_INIT = 1,
  WATCHDOG_RP2040_INVALID = 0xFF
} tWatchdog_RP2040_Status;

#define Watchdog_RP2040_IsInit() WATCHDOG_RP2040_INIT

/************************************************************
  INCLUDES
************************************************************/
#include "Watchdog_RP2040_SFR.h"

extern void Watchdog_RP2040_Init( void );
extern void Watchdog_RP2040_Enable( void );
#endif /* WATCHDOG_RP2040_H*/