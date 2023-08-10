#include <Arduino.h>
#include "sorting.h"

int arr[] = {5, 3, 8, 4, 1, 6, 2, 9, 7};
int sizeOfArray;

void setup()
{
	// Iniciar la comunicación serie a 9600 baudios
	Serial.begin(9600);
	bubble_sort(arr, 10);
  sizeOfArray = findSizeOfArray(sizeof(arr), arr);
  Serial.print("The Array is: ");
  displayArrays(arr, sizeOfArray);
  int largestNumber = findMax(arr);
  Serial.print("The largest value: ");
  Serial.println(largestNumber);
}

void loop()
{
	
}

int findSizeOfArray(int numOfBytes, int myVector[])
{
  int sizeOfVector = numOfBytes/sizeof(arr[0]);
  return sizeOfVector;
}

int findMax(int dataSet[])
{
  static int i = 0;
  static int max = -9999;
  if (i < sizeOfArray)
  {
    if ( max < dataSet[i])
    {
      max = dataSet[i];
    }
    i++;
    findMax(dataSet);
  }
  return max;
}

void displayArrays(int arrayData[], int sizeOfData)
{
  for ( int i = 0 ; i<sizeOfData; i++)
  {
    if (i<sizeOfData-1)
    {
      Serial.print(arrayData[i]);
      Serial.println(", ");
    }else{
      Serial.println(arrayData[i]);
    }
  }
}