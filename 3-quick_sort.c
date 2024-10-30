#include <stddef.h> 
#include <stdio.h> 
#include "sort.h"

/**
 * lomuto_partition - Partition array using the Lomuto scheme
 * @array: The array to sort
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The total size of the array
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, tmp;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            if (i != j)
            {
                print_array(array, size);
            }
        }
    }
    tmp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = tmp;
    if (i + 1 != high)
    {
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quick_sort_rec - Recursively apply quicksort
 * @array: The array to sort
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: The total size of the array
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);
        quick_sort_rec(array, low, pi - 1, size);
        quick_sort_rec(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Entry to the quicksort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_rec(array, 0, size - 1, size);
}
