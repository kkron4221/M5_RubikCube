#include <M5Stack.h>

float accX = 0.0;
float accY = 0.0;
float accZ = 0.0;
int count = 0;
// 右傾きを検出するためのしきい値 (例: 0.5G)
const float THRESHOLD_VALUE = 0.5; 
// 連続インクリメントを防ぐためのフラグ
bool isCounting = false; 

void diceResult(int count) {
  if (count == 1) {
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.fillCircle(160, 120, 30, RED);
  }
  else if (count == 2) {
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.fillCircle(100, 50, 30, BLACK);
    M5.Lcd.fillCircle(220, 190, 30, BLACK);
  }
}

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("IMU Test");
  // IMUセンサーの初期化 (GrayはMPU6886など)
  M5.IMU.Init(); 
}

void loop() {
  // 1. 加速度データの読み取り
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  
  // 2. 「傾き」の判断
  // X軸の加速度がしきい値を超え、かつ、まだカウント処理中でないか
  if (accX > THRESHOLD_VALUE && !isCounting) {
    
    // 3. インクリメント処理
    count++;

    diceResult(count);
    
    // 連続カウント防止のためフラグをON
    isCounting = true; 
    
  } else if (abs(accX) < 0.1) { 
    // M5Stackがほぼ水平（加速度が小さい）に戻ったら、
    // 次の傾きを検出できるようにフラグをOFF
    isCounting = false;
  }
  
  delay(100); // 100msごとにチェック
}
