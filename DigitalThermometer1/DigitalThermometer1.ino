/*デジタル温度計を作ろう！
   内容
   温度と湿度をシリアルモニタに表示する
*/
#include "DHT.h"
#define DATA_PIN 2 // DHT11のデータPinを2に設定

DHT dht(DATA_PIN, DHT11); // 今回使用するセンサをDHT11に設定
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
    Serial.println("Failed...");
    return; // 最初からやり直し
  }

  char humidFloatString[10];
  char tempFloatString[10];

  dtostrf(humid, 4, 2, humidFloatString);
  dtostrf(temp, 4, 2, tempFloatString);


  char bufHumid[20];
  char bufTemp[20];

  sprintf(bufHumid, "Humidity: %s", humidFloatString);
  sprintf(bufTemp, "Temperature: %s", tempFloatString);

  Serial.println(bufHumid);
  Serial.println(bufTemp);

}
