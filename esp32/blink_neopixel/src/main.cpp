#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include <WiFi.h>
#include "AsyncUDP.h"

const char * ssid = "JF";
const char * password = "";
const uint16_t port = 8001; 

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

int numLeds = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
AsyncUDP udp;
Adafruit_NeoPixel pixel(7, 8);

void send_text(String text){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 10);
  display.println(text);
  display.display();
}

void diaply_IP_port(IPAddress addr, uint16_t port){
    String address = String(addr[0]) + "." + String(addr[1]) + "." + String(addr[2]) + "." + String(addr[3]) + ":" + String(port);
    send_text(address);
}

struct __attribute__((packed)) neopixel{
    char check;
    char num_led;
    struct {
      char r;
      char g;
      char b;
    } leds[7];
    char end;
} UdpData;

void setup() {
  Wire.begin(4, 5);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  send_text("Init WiFi");
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    int status = WiFi.status();
    send_text(String(status));
    delay(500);
    Serial.print(".");
  }
  pixel.begin();
   WiFi.setSleep(false);
   if(udp.listen(port)){
      udp.onPacket([](AsyncUDPPacket packet){
          Serial.printf("Odebrano %d bajtów", packet.length());
          memcpy(&UdpData, packet.data(), sizeof(UdpData));
          pixel.clear();
          numLeds = UdpData.num_led;
          for (int i = 0; i < numLeds; i++) {
            Serial.println(String("LED ") + i + " R:" + (int)UdpData.leds[i].r + " G:" + (int)UdpData.leds[i].g + " B:" + (int)UdpData.leds[i].b);
            pixel.setPixelColor(i, 
              (int)UdpData.leds[i].r, 
              (int)UdpData.leds[i].g, 
              (int)UdpData.leds[i].b);
          }
          pixel.show();
      });
   diaply_IP_port(WiFi.localIP(), port);
   Serial.println(WiFi.macAddress());
  }
}

void loop() {

}
