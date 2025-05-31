#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// ThingSpeak settings
String apiKey = "YOUR_THINGSPEAK_API_KEY";
const char* server = "http://api.thingspeak.com/update";

// DHT setup
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// MQ135 analog pin
#define MQ135_PIN 34

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi.");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int airQuality = analogRead(MQ135_PIN);

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT11");
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = server;
    url += "?api_key=" + apiKey;
    url += "&field1=" + String(temp);
    url += "&field2=" + String(hum);
    url += "&field3=" + String(airQuality);

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.print("Data sent to ThingSpeak. Code: ");
      Serial.println(httpCode);
    } else {
      Serial.println("Error sending data");
    }

    http.end();
  } else {
    Serial.println("WiFi not connected");
  }

  delay(20000); // ThingSpeak allows 1 update every 15s minimum
}

