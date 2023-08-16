#pragma once
#include <Arduino.h>

int partition(int array[], int low, int high);
bool isSorted(int array[], size_t size);
void bubble_sort(int *array, size_t size);
void myBubbleSort(int myArray[], int length);
void myInsertionSort(int array[], int size);
void quickSort(int array[], int low, int high);
void swap(int *a, int *b);
