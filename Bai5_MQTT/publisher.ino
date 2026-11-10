#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "TenWifi";
const char* password = "MatKhauWifi";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED);

  client.setServer("broker.hivemq.com", 1883);

  while (!client.connected()) {
    client.connect("ESP32Pub");
  }
}

void loop() {
  client.publish("aet2022/test","Hello MQTT");
  delay(2000);
}
