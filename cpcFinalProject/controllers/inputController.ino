#include <WiFi.h>
#include <HTTPClient.h>

#define POTENTIOMETER_PIN 34   

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const String api_url = "https://caiograsso.pythonanywhere.com/atualizar_dados/";

const String numero_serial = "001";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");
}

void loop() {
  if ((WiFi.status() == WL_CONNECTED)) { 
    HTTPClient http;
    String url = api_url + "?numero_serial=" + numero_serial;

    int potValueInstrument = analogRead(POTENTIOMETER_PIN); 
    float instrument_db = convertToDb(potValueInstrument);  

    url += "&instrumento_db=" + String(instrument_db);

    http.begin(url.c_str());
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.println("Erro na requisição HTTP");
    }
    http.end();
  }
}

  delay(100); 

float convertToDb(int value) {
  return (value / 4096.0) * 80.0 - 40.0; // Exemplo de conversão, ajuste conforme necessário
}
