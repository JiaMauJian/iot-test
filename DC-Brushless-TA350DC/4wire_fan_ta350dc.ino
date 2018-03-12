// ref: http://fritzing.org/projects/connect-control-and-read-an-4-wire-fan
// Testing board = Meag 2560

int fanPulseSensorPin = 8;
int fanPwmPin = 9;
int potPin = A0; // potientiometer
int p = 2; //風扇轉一圈有幾個pulse

void setup() {
  Serial.begin(9600);
  pinMode(fanPulseSensorPin, INPUT_PULLUP);
  pinMode(fanPwmPin, OUTPUT);
}

void loop() {
  int val = analogRead(potPin) / 4; // 1023 -> 255
  analogWrite(fanPwmPin, val);

  unsigned long pulseDuration = pulseIn(fanPulseSensorPin, LOW);
  Serial.print("Pulse duration in microsec = "); // 每一個pulse花多少時間
  Serial.println(pulseDuration);

  double timeForOneRev = pulseDuration * p;
  Serial.print("Time for one revolution    = "); // 每一轉要花多少時間
  Serial.println(timeForOneRev);

  double frequency = 1000000 / timeForOneRev / p; // 1 sec = 1000000 microsec 頻率等於每秒幾次
  Serial.print("Frequency in Hz            = ");
  Serial.println(frequency);

  double rpm = 60 * frequency;
  Serial.print("RPM                        = ");
  Serial.println(rpm, 0);
  Serial.println();
  Serial.println();
  
  delay(2000);
}
