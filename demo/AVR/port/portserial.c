/*
 * FreeModbus Libary: ATMega168 Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *   - Initial version and ATmega168 support
 * Modfications Copyright (C) 2006 Tran Minh Hoang:
 *   - ATmega8, ATmega16, ATmega32 support
 *   - RS485 support for DS75176
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: portserial.c,v 1.6 2006/09/17 16:45:53 wolti Exp $
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"

#define UART_BAUD_RATE          9600
#define UART_BAUD_CALC(u,f) \
    ( ( f ) / ( ( u ) * 16UL ) - 1 ) /* f -> F_CPU, u -> baudrate */

void
vMBPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable )
{
#ifdef RTS_ENABLE
    _MB_UCSRB |= _BV( _MB_TXEN ) | _BV( _MB_TXCIE );
#else
    _MB_UCSRB |= _BV( _MB_TXEN );
#endif

    if( xRxEnable )
    {
        _MB_UCSRB |= _BV( _MB_RXEN ) | _BV( _MB_RXCIE );
    }
    else
    {
        _MB_UCSRB &= ~( _BV( _MB_RXEN ) | _BV( _MB_RXCIE ) );
    }

    if( xTxEnable )
    {
        _MB_UCSRB |= _BV( _MB_TXEN ) | _BV( _MB_UDRE );
#ifdef RTS_ENABLE
        _MB_RTS_HIGH();
#endif
    }
    else
    {
        _MB_UCSRB &= ~( _BV( _MB_UDRE ) );
    }
}

BOOL
xMBPortSerialInit( UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity )
{
    UCHAR ucUCSRC = 0;

    /* prevent compiler warning. */
    (void) ucPORT;
	
    _MB_UBRR = UART_BAUD_CALC( ulBaudRate, F_CPU );

    switch ( eParity )
    {
        case MB_PAR_EVEN:
            ucUCSRC |= _BV( _MB_UPM1 );
            break;
        case MB_PAR_ODD:
            ucUCSRC |= _BV( _MB_UPM1 ) | _BV( _MB_UPM0 );
            break;
        case MB_PAR_NONE:
            break;
    }

    switch ( ucDataBits )
    {
        case 8:
            ucUCSRC |= _BV( _MB_UCSZ0 ) | _BV( _MB_UCSZ1 );
            break;
        case 7:
            ucUCSRC |= _BV( _MB_UCSZ1 );
            break;
    }

#if defined (__AVR_ATmega168__) || defined (__AVR_ATmega169__) || \
    defined (__AVR_ATmega128__)
    _MB_UCSRC |= ucUCSRC;
#else
    _MB_UCSRC = _BV( _MB_URSEL ) | ucUCSRC;
#endif

    vMBPortSerialEnable( FALSE, FALSE );

#ifdef RTS_ENABLE
    _MB_RTS_INIT();
#endif
    return TRUE;
}

BOOL
xMBPortSerialPutByte( CHAR ucByte )
{
    _MB_UDR = ucByte;
    return TRUE;
}

BOOL
xMBPortSerialGetByte( CHAR * pucByte )
{
    *pucByte = _MB_UDR;
    return TRUE;
}

ISR( _MB_USART_UDRE_vect )
{
    pxMBFrameCBTransmitterEmpty(  );
}

ISR( _MB_USART_RX_vect )
{
    pxMBFrameCBByteReceived(  );
}

#ifdef RTS_ENABLE
ISR( _MB_USART_TX_vect )
{
    _MB_RTS_LOW();
}
#endif

#undef UART_BAUD_RATE
#undef UART_BAUD_CALC
