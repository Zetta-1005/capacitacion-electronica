#include <Arduino.h>

#define LED D3
int Lectura = 0;
int tiempo = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  Lectura = analogRead(A0);
  tiempo = map( Lectura, 6 , 1024, 10, 2000);
  
  digitalWrite(LED, HIGH);
  delay(tiempo);

  digitalWrite(LED, LOW);
  delay(tiempo);

  Serial.println(Lectura);
  delay(200);
}
