// Code:

#include <WiFiNINA.h>
#include "DHT.h"

// WiFi credentials
char ssid[] = "Alfred Nobel";
char pass[] = "CUPunjab";

// ThingSpeak settings
char server[] = "api.thingspeak.com";
String apiKey = "IIJBLMM0LPFAY5B1";

// DHT sensor setup
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;


// --- Initializing the Board ---
void setup() {
  Serial.begin(9600);
  dht.begin();

  // Connect to the WiFi network
  Serial.print("Connecting to WiFi");
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected to WiFi!");
}


// --- Main Program Loop ---
void loop() {
  // Read temperature and humidity from the sensor
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();

  // Handle sensor reading failures
  if (isnan(temp) || isnan(humid)) {
    Serial.println("❌ Failed to read from DHT sensor");
    delay(10000);
    return;
  }

  // Print readings to the Serial Monitor
  Serial.print("🌡 Temp: ");
  Serial.print(temp);
  Serial.print(" °C | 💧 Humidity: ");
  Serial.print(humid);
  Serial.println(" %");

  // Connect to ThingSpeak server and send data
  if (client.connect(server, 80)) {
    String postData = "api_key=" + apiKey + "&field1=" + String(temp) + "&field2=" + String(humid);

    client.println("POST /update HTTP/1.1");
    client.println("Host: api.thingspeak.com");
    client.println("Connection: close");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(postData.length());
    client.println();
    client.println(postData);

    Serial.println("✅ Data sent to ThingSpeak!");

    // Read server response (optional for debugging)
    while (client.connected()) {
      if (client.available()) {
        String line = client.readStringUntil('\n');
        Serial.println("Response: " + line);
      }
    }
    client.stop();
  } else {
    Serial.println("❌ Failed to connect to ThingSpeak.");
  }

  // Wait 30 seconds before sending again
  delay(30000);
}
