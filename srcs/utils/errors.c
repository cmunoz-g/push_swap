#include "push_swap.h"

void	free_stack(t_push_swap **stack)
{
	t_push_swap	*node;
	t_push_swap	*next;

	if (stack && *stack)
	{
		node = *stack;
		while (node)
		{
			next = node->next;
			free(node);
			node = next;
		}
		*stack = NULL;
	}
}

void	error(t_push_swap **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}