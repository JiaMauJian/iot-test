// https://github.com/smarmengol/Modbus-Master-Slave-for-Arduino
// Modbus-Master-Slave-for-Arduino/examples/simple_slave/simple_slave2.ino

// Modbus Master
// http://www.modbusdriver.com/modpoll.html
// modpoll -t 4 -b 19200 -p even -m rtu -a 1 -r 1 -c 16 COM4
// -t 4          16-bit output (holding) register data type (default)
// -b #          Baudrate (e.g. 9600, 19200, ...) (9600 is default)
// -p even       Even parity (default)
// -m rtu        Modbus RTU protocol (default)
// -a #          Slave address (1-255, 1 is default)
// -r #          Start reference (1-65536, 100 is default)
// -c #          Number of values to poll (1-100, 1 is default)

#include "Arduino.h"
#include <ModbusRtu.h>
#define ID 1

uint16_t au16data[16] = {11, 22, 33, 44, 55, 66, 77, 88, 0, 0, 0, 0, 0, 0, 1 ,-1};

Modbus slave(ID, 0, 0); 

void setup()
{
    slave.begin(19200, SERIAL_8E1); // 19200 baud, 8-bits, even, 1-bit stop
}

void loop()
{
    slave.poll(au16data, 16);
}