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

using time_unit_s = unsigned long;
const int MAX_ARRAY_SIZE = 120;
const int MIN_ARRAY_SIZE = 25;
const int ARRAY_STEP = 5;
const int NUM_ARRAYS = (MAX_ARRAY_SIZE - MIN_ARRAY_SIZE) / ARRAY_STEP + 1;

int ARRAY_SIZES[NUM_ARRAYS] = {};

int arrays[NUM_ARRAYS][MAX_ARRAY_SIZE] = {};

enum SortingAlgo
{
  BUBBLE_SORT = 0,
  INSERTION_SORT = 1,
  QUICK_SORT = 2
};

/**
 * @brief Stores the time it takes to sort each array
 *
 */
time_unit_s sortingTimes[NUM_ARRAYS][3] = {};

/**
 * @brief Populates the variable with random data
 *
 */
void randomizeAllArrays()
{
  for (int i = 0; i < NUM_ARRAYS; i++)
  {
    populateArrayWithRandomData(arrays[i], ARRAY_SIZES[i]);
  }
}

void printResults(int size, time_unit_s bubbleSortTime, time_unit_s insertionSortTime, time_unit_s quickSortTime)
{
  Serial.print("Size:");
  Serial.print(size);
  Serial.print(",");
  Serial.print("BubbleSortTime:");
  Serial.print(bubbleSortTime);
  Serial.print(",");
  Serial.print("InsertionSortTime:");
  Serial.print(insertionSortTime);
  Serial.print(",");
  Serial.print("QuickSortTime:");
  Serial.println(quickSortTime);
}

void setup()
{

  Serial.begin(9600);
  // Initialize array sizes variable
  for (int i = 0; i < NUM_ARRAYS; i++)
  {
    ARRAY_SIZES[i] = MIN_ARRAY_SIZE + i * ARRAY_STEP;
  }

  // Make the trials and save the results
  time_unit_s start, end;
  randomizeAllArrays();
  for (int i = 0; i < NUM_ARRAYS; i++)
  {

    start = micros();
    bubble_sort(arrays[i], ARRAY_SIZES[i]);
    end = micros();
    sortingTimes[i][BUBBLE_SORT] = end - start;

    populateArrayWithRandomData(arrays[i], ARRAY_SIZES[i]);

    start = micros();
    myInsertionSort(arrays[i], ARRAY_SIZES[i]);
    end = micros();
    sortingTimes[i][INSERTION_SORT] = end - start;

    populateArrayWithRandomData(arrays[i], ARRAY_SIZES[i]);

    start = micros();
    quickSort(arrays[i], 0, ARRAY_SIZES[i] - 1);
    end = micros();
    sortingTimes[i][QUICK_SORT] = end - start;

    printResults(ARRAY_SIZES[i], sortingTimes[i][BUBBLE_SORT], sortingTimes[i][INSERTION_SORT], sortingTimes[i][QUICK_SORT]);
  }
}

void loop()
{
}
