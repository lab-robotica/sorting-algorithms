#include <Arduino.h>
#include "sorting.h"

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * @brief Sorts the array with bubble sort
 *
 * @param array
 * @param size
 */
void bubble_sort(int *array, size_t size)
{
    for (size_t step = 0; step < size; step++)
    {
        for (int i = 0; i < size - step - 1; i++)
        {
            // Comprare the numbers and swap them
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void myBubbleSort(int myArray[], int length)
{
    // Reads each number in the array
    for (int index = 0; index < length - 1; ++index)
    {
        // Compares aside numbers
        for (int i = 0; i < length - index - 1; ++i)
        {
            // compare two aside numbers
            // change > to < to sort in descending order
            if (myArray[i] > myArray[i + 1])
            {
                int temp = myArray[i];
                myArray[i] = myArray[i + 1];
                myArray[i + 1] = temp;
            }
        }
    }
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// function to find the partition position
int partition(int array[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

/**
 * @brief Checks if the array is sorted correclty
 *
 * @param array
 * @param size
 */
bool isSorted(int array[], size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Sorts the array in place using insertion sort
 * Reference: https://www.programiz.com/dsa/insertion-sort#:~:text=Insertion%20sort%20is%20a%20sorting,we%20select%20an%20unsorted%20card.
 * @param myArray
 * @param length
 */
void myInsertionSort(int array[], int size)
{

    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
