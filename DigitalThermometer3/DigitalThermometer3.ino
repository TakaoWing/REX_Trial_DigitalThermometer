/*デジタル温度計を作ろう！3
   内容
   LCDに温度と湿度を表示
*/
#include "DHT.h"
#include "LiquidCrystal.h"
#define DATA_PIN 2 // DHT11のデータPinを2に設定
DHT dht(DATA_PIN, DHT11); // 今回使用するセンサをDHT11に設定
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
const int ledPin = 6;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
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

  lcd.clear();
  lcd.setCursor(0, 0);// 1行目にカーソルを合わせる
  lcd.print("Temp :");
  lcd.print(temp);
  lcd.print("C"); // °Cは表示できなかっため，Cのみ
  lcd.setCursor(0, 1); // 2行目にカーソルを合わせる
  lcd.print("Humid:");
  lcd.print(humid);
  lcd.print("%");
}
