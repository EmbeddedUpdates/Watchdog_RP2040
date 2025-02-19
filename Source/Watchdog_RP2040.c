/**
 * 
* @file "Watchdog_RP2040.c"
* @author Madrick3
* @brief Provides an interface to interact with the Rp2040 watchdog. When enables
* 
* @COMPONENT: WATCHDOG_RP2040
* @VERSION: 01.00.00 
*/

/************************************************************
  TYPEDEFS AND DEFINES
************************************************************/

/************************************************************
  INCLUDES
************************************************************/
#include "Watchdog_RP2040.h"

/************************************************************
  GLOBAL FUNCTIONS
************************************************************/

/* Initialize the Watchdog module, start the systick timer */
void Watchdog_RP2040_Init( void )
{
    Watchdog_RP2040_Enable();
}

void Watchdog_RP2040_Enable( void )
{
    *WATCHDOG_REG_CTRL |= WATCHDOG_CTRL_ENABLE_SET;
}
// 42 // Helper function used by both watchdog_enable and watchdog_reboot
// 43 void _watchdog_enable(uint32_t delay_ms, bool pause_on_debug) {
// 44 valid_params_if(HARDWARE_WATCHDOG, delay_ms <= WATCHDOG_LOAD_BITS / (1000 *
// WATCHDOG_XFACTOR));
// 45 hw_clear_bits(&watchdog_hw->ctrl, WATCHDOG_CTRL_ENABLE_BITS);
// 46
// 47 48 // Reset everything apart from ROSC and XOSC
// hw_set_bits(&psm_hw->wdsel, PSM_WDSEL_BITS & ~(PSM_WDSEL_ROSC_BITS |
// PSM_WDSEL_XOSC_BITS));
// 49
// 50 uint32_t dbg_bits = WATCHDOG_CTRL_PAUSE_DBG0_BITS |
// 51 WATCHDOG_CTRL_PAUSE_DBG1_BITS |
// 52 WATCHDOG_CTRL_PAUSE_JTAG_BITS;
// 53
// 54 if (pause_on_debug) {
// 55 hw_set_bits(&watchdog_hw->ctrl, dbg_bits);
// 56 } else {
// 57 hw_clear_bits(&watchdog_hw->ctrl, dbg_bits);
// 58 }
// 59
// 60 if (!delay_ms) {
// 61 hw_set_bits(&watchdog_hw->ctrl, WATCHDOG_CTRL_TRIGGER_BITS);
// 62 } else {
// 63 load_value = delay_ms * 1000;
// 64 load_value *= 2;
// 65 if (load_value > WATCHDOG_LOAD_BITS)
// 66 load_value = WATCHDOG_LOAD_BITS;
// 67
// 69
// 71 }
// 72 }
// 68 watchdog_update();
// 70 hw_set_bits(&watchdog_hw->ctrl, WATCHDOG_CTRL_ENABLE_BITS);

/************************************************************
  LOCAL FUNCTIONS
************************************************************/
