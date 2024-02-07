#include "push_swap.h"

int	check_repeat(t_push_swap *stack, int nbr)
{
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	check_args(t_push_swap *a, char	**table, bool flag)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (table[i])
	{
		if (table[i][j] == '-')
			j++;
		while (table[i][j] && (table[i][j] >= 48 && table[i][j] <= 57))
			j++;
		if (table[i][j])
			error(a, table, flag);
		else
		{
			j = 0;
			i++;
		}
	}
}

int	is_sorted(t_push_swap *stack)
{
	int	value;
	
	value = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (value > stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}