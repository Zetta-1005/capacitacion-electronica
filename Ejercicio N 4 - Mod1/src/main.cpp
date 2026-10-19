#include <Arduino.h>
#define BIN D1
int tiempo = 0;

void setup() {
 Serial.begin(9600);
 pinMode(BIN, INPUT_PULLUP);
 Serial.println("PROGRAMA INICIADO");
}

void loop() {
  if( digitalRead(BIN) == LOW){

    tiempo = 0;

    while (digitalRead(BIN) == LOW) {
      delay(10);
      tiempo += 10;
    }
     Serial.println(tiempo);
  }
}