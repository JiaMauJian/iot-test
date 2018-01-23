// https://github.com/smarmengol/Modbus-Master-Slave-for-Arduino
// Modbus-Master-Slave-for-Arduino/examples/simple_slave/simple_slave2.ino

// Modbus Master
// http://www.modbusdriver.com/modpoll.html
// modpoll -t 0 -b 19200 -p even -m rtu -a 1 -r 1 -c 8 COM4
// -t 0          Discrete output (coil) data type
// -b #          Baudrate (e.g. 9600, 19200, ...) (9600 is default)
// -p even       Even parity (default)
// -m rtu        Modbus RTU protocol (default)
// -a #          Slave address (1-255, 1 is default)
// -r #          Start reference (1-65536, 100 is default)
// -c #          Number of values to poll (1-100, 1 is default)

#include "Arduino.h"
#include <ModbusRtu.h>
#define ID 1

// GND接pin2~9，模擬輸入
// 1 byte存8隻腳的狀態
// 1 byte = 0x00, binary = 0b00000000 
uint16_t data[1];

Modbus slave(ID, 0, 0); 

void setup()
{
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);

    slave.begin(19200, SERIAL_8E1); // 19200 baud, 8-bits, even, 1-bit stop
}

void loop()
{
    slave.poll(data, 1);

    bitWrite(data[0], 0, digitalRead(2));
    bitWrite(data[0], 1, digitalRead(3));
    bitWrite(data[0], 2, digitalRead(4));
    bitWrite(data[0], 3, digitalRead(5));
    bitWrite(data[0], 4, digitalRead(6));
    bitWrite(data[0], 5, digitalRead(7));
    bitWrite(data[0], 6, digitalRead(8));
    bitWrite(data[0], 7, digitalRead(9));
}