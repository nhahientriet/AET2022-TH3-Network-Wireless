#include <esp_now.h>
#include <WiFi.h>

uint8_t receiverMac[] = {0x24,0x6F,0x28,0xAA,0xBB,0xCC};

typedef struct {
  int value;
} Message;

Message msg;

esp_now_peer_info_t peerInfo;

void setup() {

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  esp_now_init();

  memcpy(peerInfo.peer_addr, receiverMac, 6);

  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  esp_now_add_peer(&peerInfo);
}

void loop() {

  msg.value = random(0,100);

  esp_now_send(receiverMac,
               (uint8_t *)&msg,
               sizeof(msg));

  Serial.println(msg.value);

  delay(1000);
}
