#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
IPAddress ip(192, 168, 11, 4);
IPAddress gateway(192, 168, 11, 1);
IPAddress subnet(255, 255, 255, 0);
ESP8266WebServer server(80);
char * ssid_ap = "ESP8266_SSID";
char * password_ap = "sobir123";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(ssid_ap, password_ap);
  server.on("/dpot", insert);
  server.begin();
  Serial.println("data");
}

void loop() {
  server.handleClient();
}

void insert() {
  String dataKirim;
  String desa;
  desa = server.arg(0);
  dataKirim = "sayang";
  Serial.println(desa);
  server.send(200, "text/html", dataKirim);
  Serial.println("respon");
}
