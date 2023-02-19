#include "shell.h"

/**
 * add_nodeint - add a node at the beginning of a linked list
 * @head: the pointer to the first node
 * @str: the string of the node to add
 * Return: a pointer to the new node
 */
void *add_nodeint(history_t **head, char *str)
{
	history_t *new = malloc(sizeof(history_t));
	history_t *copy = *head;

	if (!new)
	{
		free_listint(*head);
	}

	new->str = _strdup(str);
	if (new->str == NULL)
	{
		free_listint(*head);
	}

	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	copy = *head;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new;
	return (new);
}
/**
 * free_listint - a function that frees a linked list
 * @head: the pointer of the list
 * Return: the number of elements in the list
 */

void free_listint(history_t *head)
{
	history_t *del;

	if (!head)
		return;
	while (head)
	{
		del = head->next;
		free(head->str);

		free(head);
		head = del;
	}
	free(del);
}
/**
 * new_history - a function that prints the list of a single linked list
 * @vars: structure with variables
 * Return: void
 */
void new_history(vars_t *vars)
{
	history_t *temp = vars->history;
	history_t *temp2 = vars->history;
	int a = 0, b = 1;
	unsigned int counter = 0;
	char *count;

	if (vars->array_tokens[1] != NULL)
	{
		error_message(vars, ": Command not found: ");
		print_message(vars->array_tokens[1]);
		print_message("\n");
		return;
	}
	else
	{
		while (temp)
		{
			temp = temp->next;
			a++;
		}
		while (b < a)
		{
			counter++;
			count = int_converter(counter);
			print_message(count);
			print_message(" ");
			_puts3(temp2->str);
			temp2 = temp2->next;
			b++;
			free(count);
		}
		temp2 = temp2->next;
		vars->invert = temp2;
		free_listint(temp);
		free_listint(temp2);
		return;
	}
}
