#include <Arduino.h>

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
