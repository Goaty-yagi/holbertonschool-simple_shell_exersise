#include "main.h"

/**
 * print_list - calls print_list
 * @h: node header
 *
 * Return: sum of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count;

	count = 0;

	while (h != NULL)
	{
		count = count + 1;
		if (h->str)
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		else
		{
			printf("[0] (nil)\n");
		}
		h = h->next;
	}
	return (count);
}
