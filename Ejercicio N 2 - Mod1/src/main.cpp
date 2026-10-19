#include <Arduino.h>

#define LED D3
#define BIN A0
int contador = 0;
int lectura = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  Serial.println(analogRead(A0));
  delay(300);

  lectura = analogRead(A0);

  if (lectura > 100 && lectura < 1024)
  {
    contador += 10;
    analogWrite(LED, contador);
  }
  else if (lectura > 0 && lectura < 90)
  {
    contador -= 10;
    analogWrite(LED, contador);
  }
}