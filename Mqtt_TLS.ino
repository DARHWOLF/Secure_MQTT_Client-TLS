#include <WiFiClientSecure.h>
#include <PubSubClient.h>


const char* ssid = "*******";
const char* password = "****";
const char* mqtt_server = "192.168.242.58";


const char* root_ca = \
"-----BEGIN CERTIFICATE REQUEST-----\n"
"MIIC/zCCAecCAQAwgYgxCzAJBgNVBAYTAklOMQ8wDQYDVQQIDAZLZXJhbGExDzAN\n"\
"BgNVBAcMBktvbGxhbTEMMAoGA1UECgwDV05BMQwwCgYDVQQLDANXTkExFzAVBgNV\n"\
"BAMMDjE5Mi4xNjguMjQyLjU4MSIwIAYJKoZIhvcNAQkBFhNub3R0YXJ1bjdAZ21h\n"\
"aWwuY29tMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA5Q1fB81UovN/\n"\
"yG0g0hMsH4CVlh+K9GHwNprB/b47emnvBRbzLiY2QXzUYIP+B6OeoPVHPrEIvAfJ\n"\
"3dCXsLbOpk8hbdYO0xzQRsXtywvfZb6aIcXdYao+EAQLgoa7y6d+xuT1Zr8Pqovw\n"\
"vk3wybExmNMqrtTXLrhBUh/xqcNYcZO8qJQhXd9DxPHomWwz6Yo4kN95xyaY3dMPt\n"\
"vZBw6sa+phoejcekqMdv+7qfZEhncJH9FD2h0F/VNHUeYsriR7fYUDpCVJO2V2ktM\n"\
"cFC1Lq0qS7ik91FPumafBGte2hUUm0F4oLJU0aNl+WyUNdw/pLnPxPq24gczcEkY\n"\
"rwjZ9WHxNQIDAQABoDEwFQYJKoZIhvcNAQkCMQgMBmFtcml0YTAYBgkqhkiG9w0B\n"\
"vCQcxCwwJcGFyYXl1bGxhMA0GCSqGSIb3DQEBCwUAA4IBAQDY8A9XHYzE14TmXtvj\n"\
"tGiZmSp5xLkKRl2dxrpoRhgKkme97NXlloq/7LK5lYBZQHGZMwHqDblZN0MeamJv\n"\
"kBOQ4CLfdLJJkdUiIDPArTdmjqn5sD7kfN6cWrpMO9IHDKGk3NDHs3U9sxZwyJPh\n"\
"voMw953m48P7SOuQzAOvJDQXRFpsncyik/rCFOS1l9opRHHoQt3FMMmfuJeQxg7z\n"\
"VzAFU2G3nto6nA2fh1odX1DA8dt/Q+hXCM+FpR/FePcnA15Ai/aplHcTCnQ/S70e\n"\
"vNQ0s6fDHUaJDN7vWqpzWOC8NJS5QjzJlP6KUUzAmJFyiUkqt0ElZkbmn3JfVYpNx\n"\
"kftb\n"\
"-----END CERTIFICATE REQUEST-----\n";


WiFiClientSecure espClient;
PubSubClient client(espClient);


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("Message arrived on topic: " + String(topic));


  // Handle the received message here
}


void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}


void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.publish("outTopic", "hello world");
      client.subscribe("inTopic");
    } else {
      delay(5000);
    }
  }
}


void setup() {
  setup_wifi();
  espClient.setCACert(root_ca);
  client.setServer(mqtt_server, 8883);
  client.setCallback(callback);
}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

