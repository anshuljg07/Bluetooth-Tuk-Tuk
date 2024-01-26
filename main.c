/* 
 * RCTukTuk.c 
 * 
 * Created: 4/20/2023 3:14:14 PM 
 * Author : Rafael Rangel de la Tejera and Anshul Gowda 
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>

// Define baud connection constants  
#define F_CPU 16000000UL
#define USART_BAUD 9600

void USART_Init() {
    UCSR0A = 1 << U2X0;  // Explain lab report 
    UBRR0L = (F_CPU / (8UL * USART_BAUD)) - 1;
    UCSR0B = 1 << TXEN0 | 1 << RXEN0;
}

int usart_putchar(char c, FILE *f) {
    if (c == '\n') {
        usart_putchar('\r', f);
    }
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
    return 0;
}

int usart_getchar(FILE *f) {
    while (!(UCSR0A & (1 << RXC0)));
    uint8_t c = UDR0;
    return c;
}

static FILE usart_io = FDEV_SETUP_STREAM(usart_putchar, usart_getchar, _FDEV_SETUP_RW);

void pwm_init();
void delayNsec(int);

int main(void) {
    setup();
    startMotors();
    USART_Init();

    while (1) {
        char c = usart_getchar(&usart_io);

        if (c == 'F') {
            // Forward motor A
            PORTB |= (1 << 1);
            PORTB &= ~(1 << 0);

            // Forward motor B
            PORTB |= (1 << 3);
            PORTB &= ~(1 << 2);

            OCR2B = 199;
        } else if (c == 'N') {
            // Forward motor A
            PORTB |= (1 << 1);
            PORTB &= ~(1 << 0);

            // Forward motor B
            PORTB |= (1 << 3);
            PORTB &= ~(1 << 2);

            OCR2B = 160;
        } else if (c == 'S') {
            // Forward motor A
            PORTB |= (1 << 1);
            PORTB &= ~(1 << 0);

            // Forward motor B
            PORTB |= (1 << 3);
            PORTB &= ~(1 << 2);

            OCR2B = 120;
        } else if (c == 'R') {
            OCR0B = 30;
        } else if (c == 'L') {
            OCR0B = 20;
        } else if (c == 'D') {
            OCR2B = 50;
        } else if (c == 'M') {
            OCR0B = 25;
        } else if (c == 'B') {
            // Back up motor A
            PORTB |= (1 << 2);
            PORTB &= ~(1 << 3);

            // Back up motor A
            PORTB |= (1 << 0);
            PORTB &= ~(1 << 1);

            OCR2B = 160;
        }
    }
}

void setup() {
    // Set all the motor control pins to outputs
    DDRB |= (1 << DDB0); // in1
    DDRB |= (1 << DDB1); // in2
    DDRB |= (1 << DDB2); // in3
    DDRB |= (1 << DDB3); // in4

    pwm_init();
}

void startMotors() {
    // Turn on motor A
    PORTB |= (1 << 1);
    PORTB &= ~(1 << 0);

    // Turn on motor B
    PORTB |= (1 << 3);
    PORTB &= ~(1 << 2);
}

void pwm_init() {
    DDRD |= (1 << DDD3); // PWM generated on PD3
    DDRD |= (1 << DDD5);

    // Settings for generating duty cycle for the motors
    TCCR2A = 0b10100011;
    TCCR2B = 0b00001001;

    // Settings for generating duty cycle for the servomotor
    TCCR0A = 0b10100011;
    TCCR0B = 0b00001101;

    OCR2A = 200;
    OCR0A = 255;

    OCR2B = 50;
    OCR0B = 25; // new middle for servo motor
}

void delayNsec(int n) {
    for (int i = 0; i < n * 100; i++) {
        _delay_ms(100);
    }
}
