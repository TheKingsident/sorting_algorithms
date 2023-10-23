#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *previous;
	size_t len;

	if (!list || !*list)
		return;

	len = get_length(list);

	if (len < 2)
		return;

	current = (*list)->next;

	while (current)
	{
		previous = current->prev;

		while (previous && previous->n > current->n)
		{
			previous->next = current->next;

			if (current->next)
				current->next->prev = previous;
			current->prev = previous->prev;
			current->next = previous;

			if (previous->prev)
				previous->prev->next = current;
			else
				*list = current;
			previous->prev = current;
			print_list(*list);
			previous = current->prev;
		}
		current = current->next;
	}
}

/**
 * get_length - Get the length of a doubly linked list
 * @list: Pointer to the head of the list
 * Return: Length of the list
 */
size_t get_length(listint_t **list)
{
	size_t len;
	listint_t *temp;

	len = 0;
	temp = *list;

	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
