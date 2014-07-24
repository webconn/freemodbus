/*
 * FreeModbus Libary: AVR Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *   - Initial version + ATmega168 support
 * Modfications Copyright (C) 2006 Tran Minh Hoang:
 *   - ATmega8, ATmega16, ATmega32 support
 *   - RS485 support for DS75176
 * Modifications Copyright (C) 2014 Maslov Nikita
 *   - Rework dummy definitions
 *   - Switch to ISR instead of SIGNAL interrupt handlers syntax
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
 * File: $Id: port.h,v 1.6 2006/09/17 16:45:52 wolti Exp $
 */

#ifndef _FREEMODBUS_PORT_H
#define _FREEMODBUS_PORT_H

/* ----------------------- Platform includes --------------------------------*/

#include <avr/io.h>
#include <avr/interrupt.h>

/* ----------------------- Defines ------------------------------------------*/
#define	INLINE                      inline
#define PR_BEGIN_EXTERN_C           extern "C" {
#define	PR_END_EXTERN_C             }

#define ENTER_CRITICAL_SECTION( )   cli()
#define EXIT_CRITICAL_SECTION( )    sei()

#define assert( x )

typedef char    BOOL;

typedef unsigned char UCHAR;
typedef char    CHAR;

typedef unsigned short USHORT;
typedef short   SHORT;

typedef unsigned long ULONG;
typedef long    LONG;

#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE           0
#endif

/* ----------------------- AVR platform specifics ---------------------------*/

/* UART interrupt vectors */
#if defined (USART_RXC_vect)
        #define _MB_USART_RX_vect USART_RXC_vect
#elif defined (USART_RX_vect)
        #define _MB_USART_RX_vect USART_RX_vect
#elif defined (UART_RX_vect)
        #define _MB_USART_RX_vect UART_RX_vect
#else
        /** TODO: implement multi-UART AVR support */
        #define _MB_USART_RX_vect USART0_RX_vect /* this is to keep ATmega128 support */
#endif

#if defined (USART_TXC_vect)
        #define _MB_USART_TX_vect USART_TXC_vect
#elif defined (USART_TX_vect)
        #define _MB_USART_TX_vect USART_TX_vect
#elif defined (UART_TX_vect)
        #define _MB_USART_TX_vect UART_TX_vect
#else
        /** TODO: implement multi-UART AVR support */
        #define _MB_USART_TX_vect USART0_TX_vect /* this is to keep ATmega128 support */
#endif

#if defined (USART_UDRE_vect)
        #define _MB_USART_UDRE_vect USART_UDRE_vect
#elif defined (UART_UDRE_vect)
        #define _MB_USART_UDRE_vect UART_UDRE_vect
#else
        /** TODO: implement multi-UART AVR support */
        #define _MB_USART_UDRE_vect USART0_UDRE_vect /* this is to keep ATmega128 support */
#endif

/* Timer COMPA vector */
#if defined (TIMER1_COMPA_vect)
        #define _MB_TIMER_COMPA_vect TIMER1_COMPA_vect
#endif

/* AVR register sets */

/* Default set of defines */
#define _MB_UCSRB               UCSRB
#define _MB_TXEN                TXEN
#define _MB_RXEN                RXEN
#define _MB_RXCIE               RXCIE
#define _MB_TXCIE               TXCIE
#define _MB_UDRE                UDRE
#define _MB_UBRR                UBRR
#define _MB_UCSRC               UCSRC
#define _MB_UPM1                UPM1
#define _MB_UPM0                UPM0
#define _MB_UCSZ0               UCSZ0
#define _MB_UCSZ1               UCSZ1
#define _MB_UDR                 UDR
#define _MB_URSEL               URSEL
#define _MB_TCCR1A              TCCR1A
#define _MB_TCCR1B              TCCR1B
#define _MB_TCCR1C              TCCR1C
#define _MB_TIFR1               TIFR1
#define _MB_TIMSK1              TIMSK1
#define _MB_TCNT1               TCNT1
#define _MB_OCIE1A              OCIE1A
#define _MB_OCR1A               OCR1A
#define _MB_OCF1A               OCF1A
#define _MB_CS12                CS12
#define _MB_CS10                CS10

#if defined (__AVR_ATmega168__)
#undef _MB_UCSRB
#undef _MB_TXEN
#undef _MB_RXEN
#undef _MB_RXCIE
#undef _MB_TXCIE
#undef _MB_UDRE
#undef _MB_UBRR
#undef _MB_UCSRC
#undef _MB_UPM1
#undef _MB_UPM0
#undef _MB_UCSZ0
#undef _MB_UCSZ1
#undef _MB_UDR

#define _MB_UCSRB               UCSR0B
#define _MB_TXEN                TXEN0
#define _MB_RXEN                RXEN0
#define _MB_RXCIE               RXCIE0
#define _MB_TXCIE               TXCIE0
#define _MB_UDRE                UDRE0
#define _MB_UBRR                UBRR0
#define _MB_UCSRC               UCSR0C
#define _MB_UPM1                UPM01
#define _MB_UPM0                UPM00
#define _MB_UCSZ0               UCSZ00
#define _MB_UCSZ1               UCSZ01
#define _MB_UDR                 UDR0

#elif defined (__AVR_ATmega8__)
#undef _MB_UBRR
#undef _MB_TCCR1C
#undef _MB_TIMSK1
#undef _MB_TIFR1

#define _MB_UBRR                UBRRL
#define _MB_TCCR1C              TCCR1A /* dummy */
#define _MB_TIMSK1              TIMSK
#define _MB_TIFR1               TIFR

#elif defined (__AVR_ATmega16__)
#undef _MB_UBRR
#undef _MB_TCCR1C
#undef _MB_TIMSK1
#undef _MB_TIFR1

#define _MB_UBRR                UBRRL
#define _MB_TCCR1C              TCCR1A /* dummy */
#define _MB_TIMSK1              TIMSK
#define _MB_TIFR1               TIFR

#elif defined (__AVR_ATmega32__)
#undef _MB_UBRR
#undef _MB_TCCR1C
#undef _MB_TIMSK1
#undef _MB_TIFR1

#define _MB_UBRR                UBRRL
#define _MB_TCCR1C              TCCR1A  /* dummy */
#define _MB_TIMSK1              TIMSK
#define _MB_TIFR1               TIFR

#elif defined (__AVR_ATmega128__)
#undef _MB_UCSRB
#undef _MB_UBRR
#undef _MB_UDR
#undef _MB_TIMSK1
#undef _MB_TIFR1
#undef _MB_UCSZ0
#undef _MB_UCSZ1
#undef _MB_UPM0
#undef _MB_UPM1
#undef _MB_UCSRC

#define _MB_UCSRB               UCSR0B
#define _MB_UBRR                UBRR0L
#define _MB_UDR                 UDR0
#define _MB_TIMSK1              TIMSK
#define _MB_TIFR1               TIFR
#define _MB_UCSZ0               UCSZ00
#define _MB_UCSZ1               UCSZ01
#define _MB_UPM0                UPM00
#define _MB_UPM1                UPM01
#define _MB_UCSRC               UCSR0C

#endif

/* ----------------------- RS485 specifics ----------------------------------*/
/* ----- From Antares environment ------------ */
#ifdef CONFIG_LIB_FREEMODBUS 
#undef RTS_ENABLE
#ifdef CONFIG_LIB_FREEMODBUS_PORT_RTS_ENABLE
#define RTS_ENABLE
#endif
#endif

#ifdef  RTS_ENABLE

/* ---------- From Antares environment ---------- */
#ifdef CONFIG_LIB_FREEMODBUS

#define _port_def(a) __port_def(a)
#define _ddr_def(a) __ddr_def(a)
#define __port_def(a) PORT ## a
#define __ddr_def(a) DDR ## a
#define RTS_PIN (CONFIG_LIB_FREEMODBUS_PORT_RTS_PIN)
#define RTS_PORT _port_def(CONFIG_LIB_FREEMODBUS_PORT_RTS_PORT)
#define RTS_DDR _ddr_def(CONFIG_LIB_FREEMODBUS_PORT_RTS_PORT)

#else

/* Old-style configuration */
#define RTS_PIN         PB0
#define RTS_DDR         DDRB
#define RTS_PORT        PORTB

#endif

#define _MB_RTS_INIT()      \
    do { \
        RTS_DDR |= _BV( RTS_PIN ); \
        RTS_PORT &= ~( _BV( RTS_PIN ) ); \
    } while( 0 );

#define _MB_RTS_HIGH()      \
    do { \
        RTS_PORT |= _BV( RTS_PIN ); \
    } while( 0 );

#define _MB_RTS_LOW()       \
    do { \
        RTS_PORT &= ~( _BV( RTS_PIN ) ); \
    } while( 0 );

#endif

#endif
