/*
Universidad de Monterrey

Advanced Robotics

Alumnos:
    Eduardo Gómez
    Alberto Castro

*/

#include "sorting.h"
#include "utils.h"
#include <Arduino.h>

const int MAX_ARRAY_SIZE = 120;
const int MIN_ARRAY_SIZE = 25;
const int ARRAY_STEP = 5;
const int NUM_ARRAYS = (MAX_ARRAY_SIZE - MIN_ARRAY_SIZE) / ARRAY_STEP + 1;

int ARRAY_SIZES[NUM_ARRAYS] = {};

int arrays[NUM_ARRAYS][MAX_ARRAY_SIZE] = {};

/**
 * @brief Populates the variable with random data
 *
 */
void randomizeArrays()
{
  for (int i = 0; i < NUM_ARRAYS; i++)
  {
    populateArrayWithRandomData(arrays[i], ARRAY_SIZES[i]);
  }
}

void setup()
{

  Serial.begin(9600);
  Serial.println("Initializing arrays");
  // Initialize array sizes variable
  for (int i = 0; i < NUM_ARRAYS; i++)
  {
    ARRAY_SIZES[i] = MIN_ARRAY_SIZE + i * ARRAY_STEP;
  }

  randomizeArrays();
  Serial.println("Done");

  Serial.println("Random array example 1: ");
  displayArrays(arrays[0], ARRAY_SIZES[0]);

  Serial.println("Random sorting with quicksort 1: ");
  myInsertionSort(arrays[0], ARRAY_SIZES[0]);

  Serial.println("Sorted array example 1: ");
  displayArrays(arrays[0], ARRAY_SIZES[0]);
  Serial.print("Is it sorted");
  Serial.println(isSorted(arrays[0], ARRAY_SIZES[0]));
}

void loop() {}
