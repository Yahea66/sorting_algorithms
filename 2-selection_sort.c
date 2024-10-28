#include <stddef.h>
#include "sort.h"

/**
 * find_smallest - finds the index of the smallest value in a subarray. 
 *
 * @array: the searched array.
 * @start_index: index to start searching from.
 * @size: size of the array. 
 *
 * Return: size_t (index of the smallest value found)
 */
size_t find_smallest(int *array, size_t start_index, size_t size)
{   
    size_t i;
    size_t index_of_smallest = start_index;
    for (i = start_index + 1; i < size; i++)
    {
        if (array[i] < array[index_of_smallest])
        {
            index_of_smallest = i;
        }
    }
    return index_of_smallest;
}

/**
 * selection_sort - sorts an array of integers in ascending order using the Selection sort algorithm
 * Expected to print the array after each time two elements are swapped. 
 *
 * @array: the array to be sorted.
 * @size: size of the array. 
 *
 * Return: Void 
 */
void selection_sort(int *array, size_t size)
{
    size_t i, smallest_index;
    int temp;
    for (i = 0; i < size - 1; i++)
    {
        smallest_index = find_smallest(array, i, size);
        if (smallest_index != i)
        {
            temp = array[i];
            array[i] = array[smallest_index];
            array[smallest_index] = temp;
            print_array(array, size);
        }
    }
}
