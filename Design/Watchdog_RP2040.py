
# import cog
from common_types import fileMetaData, function, parameter

"""
VERSION CHECK
"""
WATCHDOG_RP2040_TEMPLATE_MAJOR_VERSION = "00"
WATCHDOG_RP2040_TEMPLATE_MINOR_VERSION = "01"
WATCHDOG_RP2040_TEMPLATE_BUGFIX_VERSION = "00"
if fileMetaData.majorVersion != WATCHDOG_RP2040_TEMPLATE_MAJOR_VERSION:
    raise ValueError(" common_types.fileMetaData.majorVersion %s is incompatible with WATCHDOG_RP2040 major version %s" % (fileMetaData.majorVersion, WATCHDOG_RP2040_TEMPLATE_MAJOR_VERSION))
if fileMetaData.minorVersion != WATCHDOG_RP2040_TEMPLATE_MINOR_VERSION:
    raise ValueError(" common_types.fileMetaData.majorVersion %s is incompatible with WATCHDOG_RP2040 major version %s" % (fileMetaData.minorVersion, WATCHDOG_RP2040_TEMPLATE_MINOR_VERSION))


FUNC_PREFIX = "WATCHDOG_RP2040_"

STANDARD_RETURN_DESCR_VOID_INIT = \
"\
 * @return \n\
 *         0: 'E_OK' if successful \n\
 *         1: 'E_NOT_OK' if the operation is not successful"

STANDARD_RETURN_DESCR = \
"\
 * @return \n\
 *         0: 'E_OK' if successful \n\
 *         1: 'E_NOT_OK' if the operation is not successful \n\
 *         2: 'E_PARAM' if the input parameter is not valid \n\
 *         3: 'E_MODULE_UNINIT' if the timer is not yet initialized"

STANDARD_RETURN_DESCR_VOID = \
"\
 * @return \n\
 *         0: 'E_OK' if successful \n\
 *         1: 'E_NOT_OK' if the operation is not successful \n\
 *         3: 'E_MODULE_UNINIT' if the timer is not yet initialized"


"""
FILE DATA
"""
fileData = fileMetaData()
fileData.setModuleName("WATCHDOG_RP2040")
fileData.setAuthor("Madrick3")
fileData.setBrief("Provides a global timebase for software through the generation of a global microsecond timebase. The timebase relies on a  one microsend reference that is generated in the watchdog, and is derived from the reference clock (REFCLK). A 64-bit timer is managed, and is not able to overflow on it's own - thoughtful use of the module provides completely monotic use in practice, although setting the time to a specific large value like 0xFFFFFFFF will result in overflow. Otherwise, the module initializes, manages, and clears the timer, also manages the alarms which may trigger interrupts.")
fileData.includeList.append("Platform_Types.h")
fileData.includeList.append("WATCHDOG_RP2040_SFR.h")

"""
Local Functions
"""

# #Timer Pause
# WATCHDOG_PAUSE = function()
# WATCHDOG_PAUSE.setFuncName(FUNC_PREFIX + "Pause")
# WATCHDOG_PAUSE.setDescription("Writes to the WATCHDOG_PAUSE register, reports E_OK if Timer is paused. Reports E_NOT_OK if the timer did not pause.")
# WATCHDOG_PAUSE.setReturnType("Std_ErrorCode")
# WATCHDOG_PAUSE.setReturnDesc(STANDARD_RETURN_DESCR_VOID)
# fileData.addPrivateFunctions(WATCHDOG_PAUSE)


"""
Public Functions
"""

#Watchdog Enable
WATCHDOG_INIT = function()
WATCHDOG_INIT.setFuncName(FUNC_PREFIX + "Init")
WATCHDOG_INIT.setDescription("Initializes the timer module for a basic runtime implemetations: Arms ALARM0 as a 1ms timer, clears TIME, and begins the timer. Can fail if the RP2040_Watchdog is not already initialized. (See RP2040 datasheet section 4.7.2 'Tick Generation'). Interrupts are not necessarily enabled at this stage.")
WATCHDOG_INIT.setBrief("Initializes the RP2040  timer. Prepares ALARM0 for 1ms triggeers. Will fail if the tick generation is not yet initialized.")
WATCHDOG_INIT.setReturnType("Std_ErrorCode")
WATCHDOG_INIT.setReturnDesc(STANDARD_RETURN_DESCR_VOID_INIT)
WATCHDOG_INIT.setPreCondition(" Tick generation is already started in the watchdog module. ")
WATCHDOG_INIT.setPostCondition(" ALARM0 is armed. ")
fileData.addPublicFunctions(WATCHDOG_INIT)
