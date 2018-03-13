https://learn.adafruit.com/adafruit-led-backpack/0-dot-56-seven-segment-backpack

Wiring to the matrix is really easy

Connect CLK to the I2C clock - on Arduino UNO thats Analog #5, on the Leonardo it's Digital #3, on the Mega it's digital #21
Connect DAT to the I2C data - on Arduino UNO thats Analog #4, on the Leonardo it's Digital #2, on the Mega it's digital #20
Connect GND to common ground
Connect VCC+ to power - 5V is best but 3V also seems to work for 3V microcontrollers.
