/* 
 * This file is a part of Antares port of
 *
 * FreeModbus Libary: A portable Modbus implementation for Modbus ASCII/RTU.
 * Copyright (c) 2006 Christian Walter <wolti@sil.at>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * File: $Id: mbconfig.h,v 1.15 2010/06/06 13:54:40 wolti Exp $
 */
#ifndef _LIB_FREEMODBUS_MB_AUTOCONFIG_H
#define _LIB_FREEMODBUS_MB_AUTOCONFIG_H

/* Autoconfigure Freemodbus if we are in Antares environment */

#ifdef CONFIG_LIB_FREEMODBUS

/* Modbus ASCII is enabled */
#ifdef CONFIG_LIB_FREEMODBUS_ASCII
#define MB_ASCII_ENABLED        (1)
#else
#define MB_ASCII_ENABLED        (0)
#endif

/* Modbus RTU is enabled */
#ifdef CONFIG_LIB_FREEMODBUS_USE_RTU
#define MB_RTU_ENABLED        (1)
#else
#define MB_RTU_ENABLED        (0)
#endif

/* Modbus TCP is enabled */
#ifdef CONFIG_LIB_FREEMODBUS_TCP
#define MB_TCP_ENABLED        (1)
#else
#define MB_TCP_ENABLED        (0)
#endif

/* Character timeout value for Modbus ASCII */
#ifdef CONFIG_LIB_FREEMODBUS_ASCII_TIMEOUT
#define MB_ASCII_TIMEOUT_SEC (CONFIG_LIB_FREEMODBUS_ASCII_TIMEOUT)
#else
#define MB_ASCII_TIMEOUT_SEC (1)
#endif

/* Timeout to wait in ASCII prior to enabling transmitter */
#ifdef CONFIG_LIB_FREEMODBUS_ASCII_TIMEOUT_WAIT
#ifndef MB_ASCII_TIMEOUT_WAIT_BEFORE_SEND_MS
#define MB_ASCII_TIMEOUT_WAIT_BEFORE_SEND_MS (CONFIG_LIB_FREEMODBUS_ASCII_TIMEOUT_WAIT)
#endif
#else
#ifndef MB_ASCII_TIMEOUT_WAIT_BEFORE_SEND_MS
#define MB_ASCII_TIMEOUT_WAIT_BEFORE_SEND_MS (0)
#endif
#endif

/* Maximum number of Modbus functions */
#define MB_FUNC_HANDLERS_MAX (CONFIG_LIB_FREEMODBUS_FUNC_HANDLERS_MAX)

/* Report Slave ID buffer size */
#define MB_FUNC_OTHER_REP_SLAVEID_BUF (CONFIG_LIB_FREEMODBUS_SLAVEID_BUF)

/* ------------- Functions ------------------ */
/* Report Slave ID function */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_SLAVEID
#define MB_FUNC_OTHER_REP_SLAVEID_ENABLED       (1)
#else
#define MB_FUNC_OTHER_REP_SLAVEID_ENABLED       (0)
#endif

/* Read Input Registers */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_READ_INPUT
#define MB_FUNC_READ_INPUT_ENABLED              (1)
#else
#define MB_FUNC_READ_INPUT_ENABLED              (0)
#endif

/* Read Holding Registers */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_READ_HOLDING
#define MB_FUNC_READ_HOLDING_ENABLED            (1)
#else
#define MB_FUNC_READ_HOLDING_ENABLED            (0)
#endif

/* Write Single Register */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_WRITE_HOLDING
#define MB_FUNC_WRITE_HOLDING_ENABLED           (1)
#else
#define MB_FUNC_WRITE_HOLDING_ENABLED           (0)
#endif

/* Write Multiple Registers */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_WRITE_MULTI_HOLDING
#define MB_FUNC_WRITE_MULTIPLE_HOLDING_ENABLED  (1)
#else
#define MB_FUNC_WRITE_MULTIPLE_HOLDING_ENABLED  (0)
#endif

/* Read Coils */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_READ_COILS
#define MB_FUNC_READ_COILS_ENABLED              (1)
#else
#define MB_FUNC_READ_COILS_ENABLED              (0)
#endif

/* Write Coil */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_WRITE_COIL
#define MB_FUNC_WRITE_COIL_ENABLED              (1)
#else
#define MB_FUNC_WRITE_COIL_ENABLED              (0)
#endif

/* Write Multiple Coils */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_WRITE_MULTI_COILS
#define MB_FUNC_WRITE_MULTIPLE_COILS_ENABLED    (1)
#else
#define MB_FUNC_WRITE_MULTIPLE_COILS_ENABLED    (0)
#endif

/* Read Discrete Inputs */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_READ_DISCRETE
#define MB_FUNC_READ_DISCRETE_INPUTS_ENABLED    (1)
#else
#define MB_FUNC_READ_DISCRETE_INPUTS_ENABLED    (0)
#endif

/* Read/Write Multiple Registers */
#ifdef CONFIG_LIB_FREEMODBUS_FUNC_READWRITE_HOLDING
#define MB_FUNC_READWRITE_HOLDING_ENABLED       (1)
#else
#define MB_FUNC_READWRITE_HOLDING_ENABLED       (0)
#endif

#endif

#endif
