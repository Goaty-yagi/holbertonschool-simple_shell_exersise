#include "main.h"

/**
 * add_node_end - calls add_node_end
 * @head: node header pointer pointer
 * @str: char pointer
 *
 * Return: new address
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *p;

	p = *head;
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = strdup(str);
	new->len = strlen(str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = new;
	}
	return (new);
}
