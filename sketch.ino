#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

int light1 = 2;
int light2 = 4;
int fan = 5;

void setup() {
  Serial.begin(115200);

  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(fan, OUTPUT);

  dht.begin();

  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
}

void loop() {
  float temp = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.println(temp);

  if (temp > 30) {
    digitalWrite(fan, HIGH);
  } else {
    digitalWrite(fan, LOW);
  }

  delay(2000);
}
