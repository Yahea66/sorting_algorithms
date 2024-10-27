#include <stddef.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list to be sorted 
 *
 * Return: Void 
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp, *insert_pt;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        insert_pt = temp->prev;
        
        while (insert_pt != NULL && temp->n < insert_pt->n)
        {
            insert_pt = insert_pt->prev;
        }
        
        if (insert_pt != temp->prev)
        {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            
            if (insert_pt == NULL)
            {
                temp->prev = NULL;
                temp->next = *list;
                (*list)->prev = temp;
                *list = temp;
            }
            else
            {
                temp->next = insert_pt->next;
                temp->prev = insert_pt;
                if (temp->next) temp->next->prev = temp;
                insert_pt->next = temp;
            }
            print_list(*list);
        }
    }
}
