* [電腦風扇馬達額外功能](https://www.activa.com.tw/tw_technical-detail-2.php?id=16&type=4)
    - RD 風扇轉子運轉/鎖定訊號 (例: Arduino輸入讀取訊號)
    - FG 風扇轉速訊號器 (例: Arduino輸入讀取訊號)
    - PWM (例: Arduino輸出控制轉速)
    
* [Arduino用PWM控制4線風扇馬達接法](https://electronics.stackexchange.com/questions/153846/arduino-how-to-read-and-control-the-speed-of-a-12v-four-wire-fan) - 從DL360 Server主機上拔下來的風扇馬達，只有成功測試出PWM(藍線)是可以用的，至於O/P(黃線)Open Circuit的縮寫，測不出來，因為網路找不到Spec無法確定是FG, RD或是什麼其他功能，只有測到當高轉速的時候，可以用analogRead讀到一些跳動的數值，在某個轉速下則都是0   
