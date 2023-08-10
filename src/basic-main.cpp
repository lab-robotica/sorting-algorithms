#include <Arduino.h>

// Definir el pin donde está conectado el LED
#define LED_PIN 13

// La función setup() se ejecuta una vez al iniciar el programa
void setup() {
  // Iniciar la comunicación serie a 9600 baudios
  Serial.begin(9600);
  
  // Configurar el pin del LED como salida
  pinMode(LED_PIN, OUTPUT);
}

// La función loop() se ejecuta continuamente en un bucle
void loop() {
  // Imprimir "Hola mundo" en la consola
  Serial.println("Hola mundo");

  digitalWrite(LED_PIN, HIGH);   // Encender el LED
  delay(1000);                   // Esperar un segundo (1000 milisegundos)
  digitalWrite(LED_PIN, LOW);    // Apagar el LED
  delay(1000);                   // Esperar un segundo (1000 milisegundos)
}