
#define BLYNK_PRINT Serial

//#include <SPI.h>
//#include <Ethernet.h>
//#include <BlynkSimpleEthernet.h>

#include <ESP8266WiFi.h> // file untuk wifi 
#include <BlynkSimpleEsp8266.h> // file untuk blynk
#include <Servo.h>

char auth[] = "Nxu2KnuyajwInWDNarIzoDrAPwbrvdFk";
char ssid[] = "A50s";
char pass[] = "kirana321";

Servo gerak_servo;

BLYNK_WRITE(V1)
{
  gerak_servo.write(param.asInt());
  // Fungsi blynk untuk mengatur nilai servo dengan pin virtual V1 yang ada pada aplikasi blynk
}

void setup()
{
  // Debug console
  Serial.begin(9600); // memulai serial monitor dengan baudrate 9600

  Blynk.begin(auth, ssid, pass); // menjalankan blynk sesuai token, wifi, dan passwordnya

  gerak_servo.attach(2); // setting pin gpio 2 ke servo, D4 = 2
}

void loop()
{
  Blynk.run(); // memulai blynk
}
