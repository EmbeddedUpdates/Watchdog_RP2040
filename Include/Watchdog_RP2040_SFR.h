
/**
 * @file Watchdog_RP2040_SFR.h
 * @author pflaherty
 * @date 01.09.2024
 * @brief SFR definitions for the RP2040 Watchdog from RP2040 datasheet Chapter 4.7.6
 * 
 * COMPONENT: Watchdog_Rp2040
 * VERSION: 01.00.00
 *
 * Change History
 * 01.09.2024 - pflaherty - Initial Creation
 */

/************************************************************
  Version History
  -----------------------------------------------------------
  Revision |  Author   |  Change ID |  Description
  01.00.00 |  Madrick3 |  draft     |  Initial Creation.
************************************************************/

/************************************************************
  INCLUDES
************************************************************/
/* #include "Generic_SFR.h" */
#if defined (RP2040)
#ifndef SFR_IOS
#define SFR_IOS(x) ((unsigned int *)(x))
#endif
#endif /* VIRTUAL TARGET*/
#if defined (VIRTUAL_TARGET)
/* Virtual target has a 64 bit memory address which is marked as type long */
#define SFR_IOS(x) ((unsigned long *)(x))
#endif /* VIRTUAL TARGET*/
/************************************************************
  DEFINES
************************************************************/
#if !defined( VIRTUAL_TARGET )
/* Base Register Address */
#define WATCHDOG_BASE                      0x40058000uL

#else /* VIRTUAL TARGET */

// typedef struct vtt_RP2040_Timer
// {
//   uint32 TIMEHW;
//   uint32 TIMELW;
//   uint32 TIMEHR;
//   uint32 TIMELR;
//   uint32 ALARM0;
//   uint32 ALARM1;
//   uint32 ALARM2;
//   uint32 ALARM3;
//   uint32 ARMED;
//   uint32 TIMERAWH;
//   uint32 TIMERAWL;
//   uint32 DBGPAUSE;
//   uint32 PAUSE;
//   uint32 INTR;
//   uint32 INTE;
//   uint32 INTF;
//   uint32 INTS;
// } tRP2040_Timer;

/* Virtual Target has 64 bit word size and must be casted as such to accomodate virtual access */
// #define TIMER_BASE (uint64)&Timer_Live

#endif

// The watchdog registers start at a base address of 0x40058000 (defined as WATCHDOG_BASE in SDK).
// Table 545. List of
// WATCHDOG registers
// Offset Name Info
// 0x00 CTRL Watchdog control
// 0x04 LOAD Load the watchdog timer.
// 0x08 REASON Logs the reason for the last reset.
// 0x0c SCRATCH0 Scratch register
// 0x10 SCRATCH1 Scratch register
// 0x14 SCRATCH2 Scratch register
// 0x18 SCRATCH3 Scratch register
// 0x1c SCRATCH4 Scratch register
// 0x20 SCRATCH5 Scratch register
// 0x24 SCRATCH6 Scratch register
// 0x28 SCRATCH7 Scratch register
// 0x2c TICK Controls the tick generator


/* Register Offsets */
#define WATCHDOG_REG_CTRL_OFFSET         0x00uL
#define WATCHDOG_REG_LOAD_OFFSET         0x04uL
#define WATCHDOG_REG_REASON_OFFSET       0x08uL
/* Function like-macro for accessing SCRATCH based on index */
#define WATCHDOG_REG_SCRATCHn_OFFSET(n)  (0x0C + (0x04uL*n))
#define WATCHDOG_REG_TICK_OFFSET         0x2CuL

/* Offset Register Pointers */
#define WATCHDOG_REG_CTRL                SFR_IOS(WATCHDOG_BASE + WATCHDOG_REG_CTRL_OFFSET)
#define WATCHDOG_REG_LOAD                SFR_IOS(WATCHDOG_BASE + WATCHDOG_REG_LOAD_OFFSET)
#define WATCHDOG_REG_REASON              SFR_IOS(WATCHDOG_BASE + WATCHDOG_REG_REASON_OFFSET)
#define WATCHDOG_REG_SCRATCHn(n)         SFR_IOS(WATCHDOG_BASE + WATCHDOG_REG_SCRATCHn_OFFSET(n))
#define WATCHDOG_REG_TICK                SFR_IOS(WATCHDOG_BASE + WATCHDOG_REG_TICK_OFFSET)

// 31 TRIGGER: Trigger a watchdog reset SC 0x0
// 30 ENABLE: When not enabled the watchdog timer is paused RW 0x0
// 29:27 Reserved. - -
// 26 PAUSE_DBG1: Pause the watchdog timer when processor 1 is in debug mode RW 0x1
// 25 PAUSE_DBG0: Pause the watchdog timer when processor 0 is in debug mode RW 0x1
// 24 PAUSE_JTAG: Pause the watchdog timer when JTAG is accessing the bus
// RW 0x1
// fabric
// 23:0 TIME: Indicates the number of ticks / 2 (see errata RP2040-E1) before a
// watchdog reset will be triggered
// RO 0x0000
#define WATCHDOG_CTRL_ENABLE_MASK                0x40000000
#define WATCHDOG_CTRL_ENABLE_SET                 0x40000000
#define WATCHDOG_CTRL_ENABLE_CLR                 0x00000000

/************************************************************
  ENUMS AND TYPEDEFS
************************************************************/

/************************************************************
  EXTERN FUNCTIONS
************************************************************/

/************************************************************
  GLOBAL FUNCTIONS
************************************************************/

