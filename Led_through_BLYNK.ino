#define BLYNK_TEMPLATE_ID "TMPL3BXKyqp57"
#define BLYNK_TEMPLATE_NAME "Led1"
#define BLYNK_AUTH_TOKEN "Gk0yuRVep7FxZeTQNhpJ70lxGTI0j1mL"
#define BLYNK_PRINT Serial
#include<WiFi.h>
#include<BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Madhu's phone";
char pass[] = "12345678";

BLYNK_WRITE(V0){
  int pinvalue=param.asInt();
  digitalWrite(13,pinvalue);
}
void setup() {
 Serial.begin(9600);
 pinMode(13,OUTPUT);
 WiFi.begin(ssid,pass);
 while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.println("Not connected");
 }
 Serial.println("Connected");
 Blynk.begin(auth,ssid,pass);

}

void loop() {
  Blynk.run();
}