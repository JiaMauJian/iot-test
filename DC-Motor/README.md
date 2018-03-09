* [線路接法 1_8_4 2N3904 transistor DC motor, PWM motor](https://github.com/iirobotti/imatran-voima/wiki/1_8_4-2N3904-transistor-DC-motor,-PWM-motor)

* 為什麼要加transistor? 當開關使用，用Arduino的小電流去驅動馬達的大電流 (The Arduino can only provide 40mA at 5V on its digital pins. Most motors require more current and/or voltage to operate. A transistor can act as a digital switch, enabling the Arduino to control loads with higher electrical requirements.)[TransistorMotorControl](https://www.arduino.cc/en/Tutorial/TransistorMotorControl) 註:從玩具火車上拔下來的馬達用三用電表量大約是190mA

* 為什麼要加diode? 馬達轉動中若忽然停止，電流會倒流(台語)[voltage spike]，造成transistor壞掉，加個diode當保護，影片講得很清楚[Arduino DC Motor Control Tutoria](https://www.youtube.com/watch?v=sOz41WQF7wE)

* 徒手轉動馬達讓LED亮起來 (原來這就是發電機阿)，wiki: 發電機是利用各種動力（如水力、風力）使線圈在磁鐵的兩極間轉動；當線圈轉動時，線圈內的磁場改變，因此產生感應電流，是運用「電磁感應」原理將動力所作的功轉換成電能的裝置

* [2N3904](https://www.youtube.com/watch?v=KR5tdKQ7xHg&t=11s)

* 怎麼計算transistor [Tutorial: How to design a transistor circuit that controls low-power devices](https://www.youtube.com/watch?v=8DMZSxS-xVc)
