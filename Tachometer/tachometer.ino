int interruptPin = 3;
long lastUpdateRpm = 0;
volatile long accumulator = 0;  // sum of last 8 revolution times，要注意這裡不能unsigned
volatile unsigned long lastPulseTime = 0;
volatile unsigned int revCount = 0;
unsigned int avgRpm = 0;

int fanPulseSensorPin = 8;
int fanPwmPin = 9;
int potPin = A0; // potientiometer
int p = 2; //風扇轉一圈有幾個pulse，TA350DC內部風扇有兩個pulse
int fakeFan_p = 1; //測試轉盤只有一個pulse

void setup() {
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP); //使用內部提升電阻
  attachInterrupt(digitalPinToInterrupt(interruptPin), tach_interrupt, FALLING);

  pinMode(fanPulseSensorPin, INPUT_PULLUP); //使用內部提升電阻
  pinMode(fanPwmPin, OUTPUT);
}

void loop() {

  int val = analogRead(potPin) / 4; // 1023 -> 255
  analogWrite(fanPwmPin, val);

  unsigned long pulseDuration = pulseIn(fanPulseSensorPin, LOW);
  double timeForOneRev = pulseDuration * p;
  double frequency = 1000000 / timeForOneRev / p;
  double rpm = 60 * frequency;
  
  if (millis() - lastUpdateRpm > 1000)
  {
    lastUpdateRpm = millis();
    avgRpm = 0;
    
    if (revCount > 0)
    {          
      unsigned long avgPulseDuration = (accumulator>>3);
      double avgTimeForOneRev = avgPulseDuration * fakeFan_p;
      double avgFrequency = 1000000 / avgTimeForOneRev / fakeFan_p;
            
      avgRpm = 60 * avgFrequency;
    }

    Serial.print("Tachometer RPM (Hz) = ");
    Serial.println(avgRpm);
 
    Serial.print("Fan RPM (Hz)        = ");
    Serial.println(rpm);
    Serial.println();
    Serial.println();

    revCount = 0;
  }
}

void tach_interrupt()
{
  unsigned long usNow = micros();
  unsigned long pulseDuration = usNow - lastPulseTime;
  lastPulseTime = usNow;  // reset the clock
  
  // Accumulate the last 8 interrupt intervals
  accumulator -= (accumulator >> 3);
  accumulator += pulseDuration;
  revCount++;
}


