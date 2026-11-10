#include <WiFi.h>

const char* ssid = "TenWifi";
const char* password = "MatKhauWifi";

const char* ap_ssid = "ESP32_AP";
const char* ap_password = "12345678";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_AP_STA);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nSTA Connected");
  Serial.println(WiFi.localIP());

  WiFi.softAP(ap_ssid, ap_password);

  Serial.println("AP Started");
  Serial.println(WiFi.softAPIP());
}

void loop() {
}
