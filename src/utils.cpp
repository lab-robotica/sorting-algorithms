#include <Arduino.h>
#include "utils.h"

int findSizeOfArray(int numOfBytes, int myVector[])
{
    int sizeOfVector = numOfBytes / sizeof(myVector[0]);
    return sizeOfVector;
}

void displayArrays(int arrayData[], int sizeOfData)
{
    Serial.print("[");
    for (int i = 0; i < sizeOfData; i++)
    {
        if (i < sizeOfData - 1)
        {
            Serial.print(arrayData[i]);
            Serial.print(", ");
        }
        else
        {
            Serial.print(arrayData[i]);
        }
    }
    Serial.println("]");
}

void populateArrayWithRandomData(int arrayData[], int sizeOfData, int minValue = 0, int maxValue = 120)
{

    for (int i = 0; i < sizeOfData; i++)
    {
        arrayData[i] = random(minValue, maxValue);
    }
}