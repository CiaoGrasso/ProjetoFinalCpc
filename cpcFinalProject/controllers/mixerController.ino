#include <WiFi.h>
#include <HTTPClient.h>

// Definições dos pinos
#define MUTE_PIN 33            
#define MIXER_POT_PIN 35       
#define LED1_PIN 32            
#define LED2_PIN 14            
#define LED3_PIN 15            
#define LED4_PIN 16            
#define LED5_PIN 17            
#define LED6_PIN 18            

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const String api_url = "https://caiograsso.pythonanywhere.com/atualizar_dados/";

const String numero_serial = "M002";

void setup() {
  Serial.begin(115200);

  pinMode(MUTE_PIN, INPUT_PULLUP); 
  pinMode(LED1_PIN, OUTPUT);       
  pinMode(LED2_PIN, OUTPUT);       
  pinMode(LED3_PIN, OUTPUT);       
  pinMode(LED4_PIN, OUTPUT);      
  pinMode(LED5_PIN, OUTPUT);       
  pinMode(LED6_PIN, OUTPUT);       

  // Conecta-se à rede WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) { 
    HTTPClient http;
    String url = api_url + "?numero_serial=" + numero_serial;

    int potValueMixer = analogRead(MIXER_POT_PIN); 
    int muteState = digitalRead(MUTE_PIN);         

    float mixer_db = convertToDb(potValueMixer);  


    if (muteState == LOW) {
      mixer_db = 0;
    }

    url += "&mixer_db=" + String(mixer_db);
    url += "&mute_state=" + String(muteState);

    http.begin(url.c_str());
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(response);

      setLEDs(mixer_db);
    } else {
      Serial.println("Erro na requisição HTTP");
    }
    http.end();
  }

  delay(100); 
}

float convertToDb(int value) {
  return (value / 4096.0) * 80.0 - 40.0; 
}

void setLEDs(float db) {
  int intensity = map(db, -40, 40, 0, 255); 
  analogWrite(LED1_PIN, intensity);
  analogWrite(LED2_PIN, intensity);
  analogWrite(LED3_PIN, intensity);
  analogWrite(LED4_PIN, intensity);
  analogWrite(LED5_PIN, intensity);
  analogWrite(LED6_PIN, intensity);
}
