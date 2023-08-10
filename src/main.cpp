#include <Arduino.h>
#include "sorting.h"

int arr[10] = {5, 3, 8, 4, 1, 6, 2, 9, 7};

void setup()
{
	// Iniciar la comunicación serie a 9600 baudios
	Serial.begin(9600);
	bubble_sort(arr, 10);
}

void loop()
{
	// Imprimir "Hola mundo" en la consola
	Serial.println("Hola mundo");
	delay(2000); // Esperar un segundo (2000 milisegundos)
}
