# Arduino Mega 2560 Serial RX1 問題解
 
[http://stackoverflow.com/questions/23122294/arduino-mega-receiving-correct-data-through-serial-0-but-not-serial-1-3](http://stackoverflow.com/questions/23122294/arduino-mega-receiving-correct-data-through-serial-0-but-not-serial-1-3)
 
  
          

    I solved the problem enabling the pullup resistor of the Rx1 pin:
     
      Serial1.begin(9600);
     
      pinMode(19, INPUT);  
      digitalWrite(19, HIGH);
      
    Therefore the 3V is "overriden" by arduino's 5V for logical HIGH and zero is pulled down by bluetooth's TX for logical LOW.
     

 

