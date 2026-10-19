#include <Arduino.h>
#define Led1 D1
#define Led2 D2
#define Led3 D3
#define Bin1 D6
#define Bin2 D7
int brillo = 0;
int LedSelec = 1;
int DeltaMax = 100;
int DeltaMin = 100;
int DeltaS = 1;
int led1 = 1;
int led2 = 2;
int led3 = 3;
int tiempo = 2000;
int reinicio = 4;
int delayBin = 300;
bool contador = false;
bool cambioHecho = false;
unsigned long tiempoInicio = 0;


void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Bin1, INPUT_PULLUP);
  pinMode(Bin2, INPUT_PULLUP);
}

void loop() {

  Serial.print("Bin1: ");
  Serial.print(digitalRead(Bin1));

  Serial.print("   Bin2: ");
  Serial.println(digitalRead(Bin2));

  delay(delayBin);


  if(digitalRead(Bin1) == LOW && digitalRead(Bin2) == HIGH){
    brillo = brillo + DeltaMax;
  }

  if(digitalRead(Bin2) == LOW && digitalRead(Bin1) == HIGH){
    brillo = brillo - DeltaMin;
  }

  if(digitalRead(Bin1) == LOW && digitalRead(Bin2) == LOW){
    if(contador == false){
      tiempoInicio = millis();
      contador = true;
    }
    if(millis() - tiempoInicio >= tiempo && cambioHecho == false){
      LedSelec = LedSelec + DeltaS;
      Serial.println(LedSelec);
      cambioHecho = true;
    }
  }
  else {
    contador = false;
    cambioHecho = false;
 }


  if(LedSelec == led1){
      analogWrite(Led1, brillo);   
  }

  else if(LedSelec == led2){
      analogWrite(Led2, brillo);
  }

  else if(LedSelec == led3){
      analogWrite(Led3, brillo);
 }

  else if (LedSelec == reinicio) {
    LedSelec = led1;
  }

}