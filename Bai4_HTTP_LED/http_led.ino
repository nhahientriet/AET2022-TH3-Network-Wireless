#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "TenWifi";
const char* password = "MatKhauWifi";

WebServer server(80);

#define LED 2

void ledOn() {
  digitalWrite(LED, HIGH);
  server.send(200, "text/html", "LED ON");
}

void ledOff() {
  digitalWrite(LED, LOW);
  server.send(200, "text/html", "LED OFF");
}

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println(WiFi.localIP());

  server.on("/on", ledOn);
  server.on("/off", ledOff);

  server.begin();
}

void loop() {
  server.handleClient();
}
