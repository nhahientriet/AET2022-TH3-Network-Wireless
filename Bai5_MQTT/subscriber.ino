#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "TenWifi";
const char* password = "MatKhauWifi";

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {

  Serial.print("Message: ");

  for (int i = 0; i < length; i++)
    Serial.print((char)payload[i]);

  Serial.println();
}

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED);

  client.setServer("broker.hivemq.com", 1883);

  client.setCallback(callback);

  while (!client.connected()) {
    client.connect("ESP32Sub");
  }

  client.subscribe("aet2022/test");
}

void loop() {
  client.loop();
}
