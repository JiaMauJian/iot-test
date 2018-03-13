# 用外部訊號去控制按鈕

* 有次為了要控制鐵捲門遙控器的按鈕，大家想到的方式是用relay去模擬人去按它，後來失效，relay和線路都沒問題，但是relay導通的時候，就是無法觸發按鈕。(後來就放棄用relay，直接改用控制鐵捲門電箱內的控制板(完))

* 某次看到這個影片[Electronic Basics #11: Sending SMS with Arduino](https://www.youtube.com/watch?v=gVGD-f8SQSI)，看到作者從Arudino?接了一條到SMS模組的按鈕上，用Arduino去控制這顆按鈕，痾~還有這一招

* 實驗一，簡單接一個按鈕線路，然後用touchPin去模擬按鈕按下亮LED
```
const int buttonPin = 2;
const int ledPin = 13;
const int touchPin = 3;

int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, OUTPUT);
  digitalWrite(touchPin, HIGH); // 輸出高電位
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
```
* 實驗二，用touchPin模擬按鈕有Blink效果，要增加一個Timer的Libary(使用現成Timer Library很簡單，我已經把timer register OCR1A的設定忘光光了)[Arduino一個好用的計時器程式庫](http://yehnan.blogspot.tw/2012/03/arduino.html)，為什麼要用timer，如果loop裡面用delay跑blink，會影響到按鈕狀態的讀取
```
const int buttonPin = 2;
const int ledPin = 13;
const int touchPin = 3;

int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, OUTPUT);
  digitalWrite(touchPin, HIGH); // 輸出高電位
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
```

實驗三，用touchPin模擬按下板上上的RESET鍵，看照片
```
  ...
  pinMode(touchPin, OUTPUT);
  digitalWrite(touchPin, LOW); // 輸出低電位
  ...
```
