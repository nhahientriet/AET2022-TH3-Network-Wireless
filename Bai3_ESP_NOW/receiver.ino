#include <esp_now.h>
#include <WiFi.h>

typedef struct {
  int value;
} Message;

Message msg;

void OnDataRecv(const esp_now_recv_info *info,
                const uint8_t *incomingData,
                int len) {

  memcpy(&msg, incomingData, sizeof(msg));

  Serial.print("Received: ");
  Serial.println(msg.value);
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  esp_now_init();

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
}
