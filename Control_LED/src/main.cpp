#include <Arduino.h>
#define LED D3
#define Bin_Subir D1
#define Bin_Bajar D2
// Le dimos un valor al brillo del led
int brillo = 0;

//digitalWrite() → salida digital → HIGH o LOW → prendido/apagado
void setup() {
  //PAra ver en la consola
  Serial.begin(9600);
 // Output ( salida )
 pinMode(LED, OUTPUT);
 // Input ( Entrada )
 pinMode(Bin_Subir, INPUT_PULLUP);
 pinMode(Bin_Bajar, INPUT_PULLUP);
 // Se designo las entradas y salidas de los botones y led
}


// analogWrite()  → PWM → distintos valores → distintas intensidades
void loop() {

  //SI la lectura de "Bin_Subir" es igual a "LOW", entrá al "if".
  //pensar en digitalRead() como un sensor/pregunta: “¿cómo está este pin ahora?”
  if ( digitalRead(Bin_Subir) == LOW && brillo < 255){
    Serial.println("Boton subir presionado");
    //Sirve para subir el int brillo de 0 a 1, 2, 3, etc
    brillo++;
    //Le manda el nuevo valor de brillo al led
    analogWrite(LED, brillo);
    Serial.println(brillo);
    // Espera hasta que suelte el botón para no sumar varias vecesEs por si lo dejo apretado que de mientras se relentice la suma o resta dependiendo del boton
    //while (digitalRead(Bin_Subir) == LOW){
     // delayMicroseconds(1);
   // }
    
 
 }
 // Se coloca que sean los dos igual a LOW porque queremos que cuando se apriete el boton este haga lo que se le indique

  if ( digitalRead(Bin_Bajar) == LOW && brillo > 0){
    Serial.println("Boton bajar presionado");
    //Sirve para bajar el int brillo
    brillo--;
    analogWrite(LED, brillo);
    Serial.println(brillo);
    //while (digitalRead(Bin_Bajar) == LOW ) {
    //  delay(1);
    //}
 }

}