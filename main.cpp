#include <M5Stack.h>

// 現在のサイコロの目を保持する変数（初期値は1）
int currentDiceValue = 0;

int pattern_1_6[4] = {1, 2, 6, 5};
int pattern_2_5[4] = {2, 5, 3, 4};
int pattern_3_4[4] = {3, 1, 4, 6};

/**
 * @brief 画面中央に現在のサイコロの目を大きな数字で表示する関数
 */
void displayDiceValue() {
  
  // 画面中央に数字を描画 (drawCentreStringを使用)
  // X座標: 画面幅の半分, Y座標: 画面高さの半分から少し上に調整
  // M5.Lcd.drawCentreString(
  //   String(pattern_1_6[currentDiceValue]), 
  //   M5.Lcd.width() / 2, 
  //   M5.Lcd.height() / 2 - 20, 
  //   7 // フォント番号 (setTextSizeの値と一致させる)
  // );

}

/**
 * @brief サイコロの目を変更する関数
 * @param changeType -1:左回転(デクリメント), 1:右回転(インクリメント), 2:前後回転(特定の加算)
 */
void changeDiceValue(int changeType) {
  M5.Lcd.fillScreen(BLACK); 

  if (changeType == -1) {
    // // Aボタン（左回転）: 目を1つ減らす（1 -> 6, 2 -> 1, ...）
    // currentDiceValue--;
    // if (currentDiceValue < 1) {
    //   currentDiceValue = 4;
    // }
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.fillCircle(100, 50, 30, BLACK);
    M5.Lcd.fillCircle(100, 190, 30, BLACK);    
    M5.Lcd.fillCircle(160, 120, 30, BLACK);
    M5.Lcd.fillCircle(220, 50, 30, BLACK);
    M5.Lcd.fillCircle(220, 190, 30, BLACK);
  } else if (changeType == 1) {
    // // Cボタン（右回転）: 目を1つ増やす（1 -> 2, 6 -> 1, ...）
    // currentDiceValue++;
    // if (currentDiceValue > 4) {
    //   currentDiceValue = 1;
    // }
    M5.Lcd.fillScreen(WHITE);
    M5.Lcd.fillCircle(100, 50, 30, BLACK);
    M5.Lcd.fillCircle(220, 50, 30, BLACK);
    M5.Lcd.fillCircle(100, 120, 30, BLACK);
    M5.Lcd.fillCircle(220, 120, 30, BLACK);
    M5.Lcd.fillCircle(100, 190, 30, BLACK);
    M5.Lcd.fillCircle(220, 190, 30, BLACK);

  } else if (changeType == 2) {
    // Bボタン（前後回転）: 現在の目に応じて、向かい合う目に切り替える
    // (1と6, 2と5, 3と4 は向かい合う) -> 7から現在の目を引くと向かい合う目になる
  }
}


void setup() {
  // M5Stackの初期化
  M5.begin();
  
  // 画面の向きを設定（Coreであれば1が一般的）
  M5.Lcd.setRotation(1); 
  
  // 最初の目（1）を表示
  M5.Lcd.fillScreen(BLACK);


}

void loop() {
  // 常にボタンの状態を更新
  M5.update();

  // 1. Aボタン（左回転）の処理: 例として「目を1つ減らす」動作を割り当て
  if (M5.BtnA.wasPressed()) {
    // ユーザーの仕様例: 左回転で (3 -> 6), (6 -> 3) などの具体的な遷移ルールがあればそれに従う
    // 今回はシンプルなサイコロの目（1つ減らす）として実装
    changeDiceValue(-1); 
  }

  // 2. Cボタン（右回転）の処理: 例として「目を1つ増やす」動作を割り当て
  if (M5.BtnC.wasPressed()) {
    // ユーザーの仕様例: 右回転で (1 -> 3), (3 -> 6) などの具体的な遷移ルールがあればそれに従う
    // 今回はシンプルなサイコロの目（1つ増やす）として実装
    changeDiceValue(1); 
  }
  
  // 3. Bボタン（前後回転）の処理: 例として「向かい合う目」に切り替える動作を割り当て
  if (M5.BtnB.wasPressed()) {
    // ユーザーの仕様: 前後に回転させると2になる（例: 1->2, 3->2, 6->2?）
    // 複雑になるため、一般的なサイコロの「前後回転＝向かい合う目に切り替える」ロジックを採用
    // もし、どの目からでも「2」に切り替えたい場合は、'currentDiceValue = 2;' に変更してください
    changeDiceValue(2); 
  }
  
  // 無駄な繰り返しを避けるための短い待ち時間
  delay(10);
}
