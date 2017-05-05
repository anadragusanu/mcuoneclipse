/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : GI2C1.h
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : GenericI2C
**     Version     : Component 01.033, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-05-05, 12:54, # CodeGen: 135
**     Abstract    :
**         This component implements a generic I2C driver wrapper to work both with LDD and non-LDD I2C components.
**     Settings    :
**          Component name                                 : GI2C1
**          Wait                                           : WAIT1
**          SDK                                            : MCUC1
**          Support STOP_NOSTART                           : no
**          Write Buffer Size                              : 16
**          non-LDD I2C                                    : Enabled
**            I2C                                          : I2C1
**          LDD I2C                                        : Disabled
**          RTOS                                           : Enabled
**            RTOS                                         : FRTOS1
**            Semaphore                                    : yes
**          Init() on startup                              : yes
**     Contents    :
**         SelectSlave       - uint8_t GI2C1_SelectSlave(uint8_t i2cAddr);
**         UnselectSlave     - uint8_t GI2C1_UnselectSlave(void);
**         RequestBus        - void GI2C1_RequestBus(void);
**         ReleaseBus        - void GI2C1_ReleaseBus(void);
**         WriteBlock        - uint8_t GI2C1_WriteBlock(void* data, uint16_t dataSize, GI2C1_EnumSendFlags...
**         ReadBlock         - uint8_t GI2C1_ReadBlock(void* data, uint16_t dataSize, GI2C1_EnumSendFlags...
**         ReadAddress       - uint8_t GI2C1_ReadAddress(uint8_t i2cAddr, uint8_t *memAddr, uint8_t...
**         WriteAddress      - uint8_t GI2C1_WriteAddress(uint8_t i2cAddr, uint8_t *memAddr, uint8_t...
**         ReadByteAddress8  - uint8_t GI2C1_ReadByteAddress8(uint8_t i2cAddr, uint8_t memAddr, uint8_t *data);
**         WriteByteAddress8 - uint8_t GI2C1_WriteByteAddress8(uint8_t i2cAddr, uint8_t memAddr, uint8_t data);
**         ReadWordAddress8  - uint8_t GI2C1_ReadWordAddress8(uint8_t i2cAddr, uint8_t memAddr, uint16_t...
**         WriteWordAddress8 - uint8_t GI2C1_WriteWordAddress8(uint8_t i2cAddr, uint8_t memAddr, uint16_t...
**         ProbeACK          - uint8_t GI2C1_ProbeACK(void* data, uint16_t dataSize, GI2C1_EnumSendFlags...
**         GetSemaphore      - void* GI2C1_GetSemaphore(void);
**         ScanDevice        - uint8_t GI2C1_ScanDevice(uint8_t i2cAddr);
**         Deinit            - void GI2C1_Deinit(void);
**         Init              - void GI2C1_Init(void);
**
**     * Copyright (c) 2013-2017, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file GI2C1.h
** @version 01.00
** @brief
**         This component implements a generic I2C driver wrapper to work both with LDD and non-LDD I2C components.
*/         
/*!
**  @addtogroup GI2C1_module GI2C1 module documentation
**  @{
*/         

#ifndef __GI2C1_H
#define __GI2C1_H

/* MODULE GI2C1. */
#include "MCUC1.h" /* SDK and API used */
#include "GI2C1config.h" /* configuration */

/* Include inherited beans */
#include "WAIT1.h"
#include "MCUC1.h"
#include "I2C1.h"
#include "FRTOS1.h"


#define GI2C1_WRITE_BUFFER_SIZE 16 /* size of internal buffer used, set in the component properties */

typedef enum GI2C1_EnumSendFlags_ {
  GI2C1_SEND_STOP,        /* STOP is sent */
  GI2C1_DO_NOT_SEND_STOP, /* STOP is not sent */
  GI2C1_STOP_NOSTART      /* send STOP without START condition */
} GI2C1_EnumSendFlags;

typedef enum GI2C1_EnumStartFlags_ {
  GI2C1_SEND_START,        /* Start is sent */
  GI2C1_DO_NOT_SEND_START  /* Start is not sent */
} GI2C1_EnumStartFlags;

typedef enum GI2C1_EnumAckFlags_ {
  GI2C1_SEND_LAST_ACK,   /* Nack after last received byte is sent */
  GI2C1_DO_NOT_LAST_ACK  /* Nack after last received byte is not sent */
} GI2C1_EnumAckFlags;

void GI2C1_Init(void);
/*
** ===================================================================
**     Method      :  GI2C1_Init (component GenericI2C)
**     Description :
**         Initializes the driver.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void GI2C1_Deinit(void);
/*
** ===================================================================
**     Method      :  GI2C1_Deinit (component GenericI2C)
**     Description :
**         Deinitializes the driver.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t GI2C1_ReadAddress(uint8_t i2cAddr, uint8_t *memAddr, uint8_t memAddrSize, uint8_t *data, uint16_t dataSize);
/*
** ===================================================================
**     Method      :  GI2C1_ReadAddress (component GenericI2C)
**     Description :
**         Read from the device. This writes (S+i2cAddr+0), (memAddr),
**         (Sr+i2cAddr+1), (data)...(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**       * memAddr         - Pointer to device memory address
**         memAddrSize     - number of address bytes
**       * data            - Pointer to read buffer
**         dataSize        - Size of read buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_WriteAddress(uint8_t i2cAddr, uint8_t *memAddr, uint8_t memAddrSize, uint8_t *data, uint16_t dataSize);
/*
** ===================================================================
**     Method      :  GI2C1_WriteAddress (component GenericI2C)
**     Description :
**         Write to the device: (S+i2cAddr+0), (memAddr), (data)...
**         (data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C address of device
**       * memAddr         - Pointer to device memory address
**         memAddrSize     - number of address bytes
**       * data            - Pointer to data write buffer
**         dataSize        - Size of data buffer in bytes
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void* GI2C1_GetSemaphore(void);
/*
** ===================================================================
**     Method      :  GI2C1_GetSemaphore (component GenericI2C)
**     Description :
**         Returns the currently allocated semaphore.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_ReadBlock(void* data, uint16_t dataSize, GI2C1_EnumSendFlags flags);
/*
** ===================================================================
**     Method      :  GI2C1_ReadBlock (component GenericI2C)
**     Description :
**         Read from the device a block.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Read buffer
**         dataSize        - Size of read buffer
**         flags           - flags for the transaction
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_WriteBlock(void* data, uint16_t dataSize, GI2C1_EnumSendFlags flags);
/*
** ===================================================================
**     Method      :  GI2C1_WriteBlock (component GenericI2C)
**     Description :
**         Write a block to the device.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Data write buffer
**         dataSize        - 
**         flags           - flags for the transaction
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void GI2C1_RequestBus(void);
/*
** ===================================================================
**     Method      :  GI2C1_RequestBus (component GenericI2C)
**     Description :
**         Starts a critical section for accessing the bus.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void GI2C1_ReleaseBus(void);
/*
** ===================================================================
**     Method      :  GI2C1_ReleaseBus (component GenericI2C)
**     Description :
**         Finishes a critical section for accessing the bus.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t GI2C1_SelectSlave(uint8_t i2cAddr);
/*
** ===================================================================
**     Method      :  GI2C1_SelectSlave (component GenericI2C)
**     Description :
**         Selects the slave device on the bus. Method might use a
**         semaphore to protect bus access.
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_UnselectSlave(void);
/*
** ===================================================================
**     Method      :  GI2C1_UnselectSlave (component GenericI2C)
**     Description :
**         Unselects the device. Method will release a used a semaphore.
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_ReadByteAddress8(uint8_t i2cAddr, uint8_t memAddr, uint8_t *data);
/*
** ===================================================================
**     Method      :  GI2C1_ReadByteAddress8 (component GenericI2C)
**     Description :
**         Read a byte from the device using an 8bit memory address.
**         This writes (S+i2cAddr+0), (memAddr), (Sr+i2cAddr+1), (data)..
**         .(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**         memAddr         - Device memory address
**       * data            - Pointer to read buffer (single byte)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_WriteByteAddress8(uint8_t i2cAddr, uint8_t memAddr, uint8_t data);
/*
** ===================================================================
**     Method      :  GI2C1_WriteByteAddress8 (component GenericI2C)
**     Description :
**         Write a byte to the device using an 8bit memory address:
**         (S+i2cAddr+0), (memAddr), (data)...(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C address of device
**         memAddr         - Device memory address
**         data            - Data value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_ScanDevice(uint8_t i2cAddr);
/*
** ===================================================================
**     Method      :  GI2C1_ScanDevice (component GenericI2C)
**     Description :
**         Checks if a device responds on the bus with an ACK.
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - 7bit I2C device address
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_ProbeACK(void* data, uint16_t dataSize, GI2C1_EnumSendFlags flags, uint16_t WaitTimeUS);
/*
** ===================================================================
**     Method      :  GI2C1_ProbeACK (component GenericI2C)
**     Description :
**         Accesses the bus to check if the device responds with an ACK
**         (ACK polling).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Data write buffer
**         dataSize        - 
**         flags           - flags for the transaction
**         WaitTimeUS      - Waiting time in microseconds
**                           to wait for the ACK on the bus.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_ReadWordAddress8(uint8_t i2cAddr, uint8_t memAddr, uint16_t *data);
/*
** ===================================================================
**     Method      :  GI2C1_ReadWordAddress8 (component GenericI2C)
**     Description :
**         Read a word from the device using an 8bit memory address.
**         This writes (S+i2cAddr+0), (memAddr), (Sr+i2cAddr+1), (data)..
**         .(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C Address of device
**         memAddr         - Device memory address
**       * data            - Pointer to read buffer (single byte)
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t GI2C1_WriteWordAddress8(uint8_t i2cAddr, uint8_t memAddr, uint16_t data);
/*
** ===================================================================
**     Method      :  GI2C1_WriteWordAddress8 (component GenericI2C)
**     Description :
**         Write a word to the device using an 8bit memory address:
**         (S+i2cAddr+0), (memAddr), (data)...(data+P)
**     Parameters  :
**         NAME            - DESCRIPTION
**         i2cAddr         - I2C address of device
**         memAddr         - Device memory address
**         data            - Data value
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

/* END GI2C1. */

#endif
/* ifndef __GI2C1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
