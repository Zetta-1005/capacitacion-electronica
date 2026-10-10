#include <Arduino.h>
#define BIN D4
#define Led1 D1
#define Led2 D2
#define Led3 D3
#define Pote A0
int Boton = 0;
int lectura = 0; 
int brillo = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BIN, INPUT_PULLUP);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
}

void loop() {
  Serial.println(digitalRead(BIN));
  delay(500);
  lectura = analogRead(Pote);
  brillo = map(lectura, 0, 1024, 0, 255);

  if (digitalRead(BIN) == LOW){
    Boton = Boton + 1;

    while (digitalRead(BIN)== LOW){
     delay(1);
   }
  }
  if(Boton > 3){
   Boton = 1;
  }

  if(Boton == 1){
      analogWrite(Led1, brillo);
    }
  else if(Boton == 2){
      analogWrite(Led2, brillo);
    }
  else if(Boton == 3){
    analogWrite(Led3, brillo);
    }
    
}