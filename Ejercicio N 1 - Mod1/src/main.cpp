#include <Arduino.h>

#define LED D3
#define BTN D1
#define BTN1 D2


int contador = 0;


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BTN1, INPUT_PULLUP);
}

void loop() {

  if(digitalRead(BTN) == LOW && contador <255){
    contador++;
    analogWrite(LED, contador);
    Serial.println(contador);
  }
  else if(digitalRead(BTN1) == LOW && contador > 0){
    contador--;
    analogWrite(LED, contador);
    Serial.println(contador);
  }

}