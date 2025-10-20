#include <M5Stack.h>

float accX = 0.0;
float accY = 0.0;
float accZ = 0.0;
int count = 0;
const float THRESHOLD_VALUE = 0.5; 
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
  else if (count == 3) {
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.fillCircle(100, 50, 30, BLACK);
    M5.Lcd.fillCircle(160, 120, 30, BLACK);
    M5.Lcd.fillCircle(220, 190, 30, BLACK);
  }
  else if (count == 4) {
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.fillCircle(100, 50, 30, BLACK);
    M5.Lcd.fillCircle(220, 50, 30, BLACK);
    M5.Lcd.fillCircle(100, 190, 30, BLACK);
    M5.Lcd.fillCircle(220, 190, 30, BLACK);
  }
  else if (count == 5) {
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.fillCircle(100, 50, 30, BLACK);
    M5.Lcd.fillCircle(100, 190, 30, BLACK);
    M5.Lcd.fillCircle(160, 120, 30, BLACK);
    M5.Lcd.fillCircle(220, 50, 30, BLACK);
    M5.Lcd.fillCircle(220, 190, 30, BLACK);
  }
  else if (count == 6) {
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.fillCircle(100, 50, 30, BLACK);
    M5.Lcd.fillCircle(220, 50, 30, BLACK);
    M5.Lcd.fillCircle(100, 120, 30, BLACK);
    M5.Lcd.fillCircle(220, 120, 30, BLACK);
    M5.Lcd.fillCircle(100, 190, 30, BLACK);
    M5.Lcd.fillCircle(220, 190, 30, BLACK);
  }
  else {
    M5.Lcd.fillScreen(WHITE);
  }
}

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("Dice Start");
  // IMUセンサーの初期化 (GrayはMPU6886など)
  M5.IMU.Init(); 
}

void loop() {
  // 1. 加速度データの読み取り
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  
  if (accX > THRESHOLD_VALUE && !isCounting) {
    count++;
    diceResult(count);
    isCounting = true;
  }else if (abs(accX) < 0.1) { 
    isCounting = false;
  }
  delay(100);
}
