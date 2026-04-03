#include "lists.h"
/**
* get_dnodeint_at_index - A function that returns the nth node of a list.
* @index: The index of the node, starting at 0.
* @head: The pointer to the head of the list.
* Return: pointer to the nth node, NULL if the node does not exist.
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *current = head;
unsigned int count = 0;

while (current != NULL)
{
if (count == index)
return (current);
count++;
current = current->next;
}
return (NULL);
}
