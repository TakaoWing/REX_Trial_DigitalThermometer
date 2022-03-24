/*デジタル温度計を作ろう！
   内容
   温度と湿度をシリアルモニタに表示する
*/

// 温度湿度センサの設定
#include "DHT.h"
const int dataPin = 2; // DHT11のデータPinを2に設定
DHT dht(dataPin, DHT11); // 今回使用するセンサをDHT11に設定

void setup() {
  Serial.begin(9600);
  dht.begin(); // dhtセンサの測定を開始する
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

  Serial.print("温度：");
  Serial.print(temp);
  Serial.print("[°C]");

  Serial.print(" 湿度：");
  Serial.print(humid);
  Serial.println("[%]");
}
