#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// Dados do Wifi
#define WIFI_SSID "Esp32_TG"
#define WIFI_PASSWORD "Esp32_TG_Project"

//Telegram Bot Token (Botfather)
#define BOT_TOKEN "7080721921:AAHV-j3ue0-E7r0UxKZ4FLJ_d0PX2rJ4UDg"

//Use Midbot (IDBot) para saber qual o seu ID
#define CHAT_ID "341240590"

unsigned long bot_lasttime;           // last time messages' scan has been done
const unsigned long BOT_MTBS = 1000;  // mean time between scan messages


WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);


// attempt to connect to Wifi network:
void setupWifi() {
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);  // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org");  // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600) {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);

  bot.sendMessage(CHAT_ID, "Bot started up", "");
}



void setup() {
  Serial.begin(9600);
  setupWifi();
  delay(100);

}

void loop() {
  if(Serial.available() ){
    String mensage=Serial.readString();
    Serial.print(Serial.available() );

    bot.sendMessage(CHAT_ID, String(mensage), "");
  }
}
