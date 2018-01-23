// Modbus Slave測試軟體 ICDT Modbus RTU Slave

#include "Arduino.h"
#include <ModbusRtu.h>
#include <SoftwareSerial.h>

modbus_t telegram;
uint16_t data[16];
unsigned long u32wait;
unsigned long previousMillis;

Modbus master(0, 0, 0);
SoftwareSerial debugSerial(10, 11); // RX | TX;

void setup()
{
    debugSerial.begin(9600);
    master.begin(19200, SERIAL_8E1);
    master.setTimeOut(2000);
    u32wait = 1000;
    previousMillis = 0;
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis > u32wait)
    {
        previousMillis = currentMillis;

        telegram.u8id = 1;
        
        //telegram.u8fct = 1; // Function code 1 and 2 still not implemented
        //要玩Master可以改測這一套 https://github.com/4-20ma/ModbusMaster
        
        telegram.u8fct = 3;
        telegram.u16RegAdd = 0;
        telegram.u16CoilsNo = 8; // number of elements (coils or registers) to read
        telegram.au16reg = data;        

        master.query(telegram);

        delay(100);

        master.poll();

        if (master.getState() == COM_IDLE) 
        {        
            debugSerial.println(data[0], BIN);            
        }
    }
}