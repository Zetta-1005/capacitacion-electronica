#include <Arduino.h>
#define LED D3
#define Bin_Subir D1
#define Bin_Bajar D2
int brillo = 0;

void setup() {
  Serial.begin(9600);
 pinMode(LED, OUTPUT);
 pinMode(Bin_Subir, INPUT_PULLUP);
 pinMode(Bin_Bajar, INPUT_PULLUP);
}

void loop() {
  if ( digitalRead(Bin_Subir) == LOW && brillo < 255){
    Serial.println("Boton subir presionado");
    brillo++;
    analogWrite(LED, brillo);
    Serial.println(brillo);
  }
  if ( digitalRead(Bin_Subir) == LOW && brillo < 255){
    Serial.println("Boton bajar presionado");
    brillo--;
    analogWrite(LED, brillo);
    Serial.println(brillo);
  }
}