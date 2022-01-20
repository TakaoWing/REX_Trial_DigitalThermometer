/*デジタル温度計を作ろう！3
   内容
   LCDに温度と湿度を表示
*/

// 温度湿度センサの設定
#include "DHT.h"
#define DATA_PIN 2 // DHT11のデータPinを2に設定
DHT dht(DATA_PIN, DHT11); // 今回使用するセンサをDHT11に設定

// LCDの設定
#include "LiquidCrystal.h"
#define RS_PIN 4
#define E_PIN 6
#define D4_PIN 10
#define D5_PIN 11
#define D6_PIN 12
#define D7_PIN 13
LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
  dht.begin(); // dhtセンサの測定を開始する
  lcd.begin( 16, 2 ); // LCDのサイズを入れる．今回のLCDは横に16文字と縦に2列のため
}

void loop() {
  delay(3000); // 3秒待つ 

  float humid = dht.readHumidity(); // 湿度を取得
  float temp = dht.readTemperature(); // 温度を取得

  // どちらかが取得できない場合
  if (isnan(humid) || isnan(temp)) {
    Serial.println("ERROR");
    return; // 最初からやり直し
  }

  lcd.clear(); // 画面をクリアにする←この処理がないと文字が重なってしまう
  lcd.setCursor(0, 0);// 1行目にカーソルを合わせる
  lcd.print("Temp :");
  lcd.print(temp);
  lcd.print("C"); // °Cは表示できなかっため，Cのみ
  lcd.setCursor(0, 1); // 2行目にカーソルを合わせる
  lcd.print("Humid:");
  lcd.print(humid);
  lcd.print("%");
}
