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

void	free_table(char	**table)
{
	size_t	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free (table);
}

void	error(t_push_swap *stack, char **table, bool flag)
{
	free_stack(stack);
	if (flag)
		free_table(table);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}