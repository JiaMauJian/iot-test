#include "Arduino.h"

void USART_init(void);
void USART_send(char data);
void USART_send_string(char *pStr);

void setup()
{    
    USART_init();

    // pinMode(2~7, INPUT_PULLUP);
    PORTD = (_BV(PORTD7) | _BV(PORTD6) | _BV(PORTD5) | _BV(PORTD4) | _BV(PORTD3) | _BV(PORTD2));

    // pinMode(8~9, INPUT_PULLUP);
    PORTB = (_BV(PORTB1) | _BV(PORTB0));  
}

void loop()
{
    byte inputs = PIND >> 2;
    inputs += PINB << 6;

    // Interger convert to String Binary
    String str = String(inputs, BIN);
    char datas[9];
    str.toCharArray(datas, 9);

    USART_send_string(datas);

    delay(1000);
}

void USART_init(void)
{
    //9600 Baud
    UBRR0 = 0x0067; 

    // Set frame format: No parity check, 8 Data bits, 1 stop bit
    UCSR0C = (_BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00));
    
    // Enable transmitter
    UCSR0B = _BV(TXEN0); 
}

void USART_send(char data)
{
    while(!(UCSR0A & (1 << UDRE0))); //Wait for empty transmit buffer
    UDR0 = data;
}

void USART_send_string(char *p)
{
    while (*p != '\0')
    {
        USART_send(*p);
        p++;
    }
    USART_send('\n');
}