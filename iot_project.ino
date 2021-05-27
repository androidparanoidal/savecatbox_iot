#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "";        
const char* password = "";
String servername = "http://"; 

int inputPin = 33; 
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(inputPin, INPUT);
  
  Serial.begin(115200);
  delay(5000); 
  
  // Подключаемся к сети WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(3000);
    Serial.println("Соединяемся с Wi-Fi.....");
  }
  Serial.println(WiFi.localIP());
  Serial.println("Соединение с Wi-Fi установлено");

}

void loop(){
  int val = digitalRead(inputPin);
  if (val == HIGH) {
    Serial.println("Движение!!!");
    digitalWrite(led, HIGH);    
    } else {
    Serial.println("Нет движения...");
    digitalWrite(led, LOW);
    }
    
  if (val == HIGH) {
    if ((WiFi.status() == WL_CONNECTED)) {
      HTTPClient http;

      String serverpath = servername;
      http.begin(serverpath.c_str());
      int httpCode = http.GET();
    
      if (httpCode > 0) {
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      } else {
        Serial.println("Ошибка HTTP-запроса");
        Serial.println(httpCode);
      }
      http.end();
    }  
  }  
  
delay(3000);
}
