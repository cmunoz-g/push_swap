#include "push_swap.h"

int	find_biggest(t_push_swap *stack)
{
	int	res;
	
	res = stack->value;
	while (stack)
	{
		if (res < stack->value)
			res = stack->value;
		stack = stack->next;
	}
	return (res);
}

void	sort_small(t_push_swap **stack)
{
	int	biggest;

	biggest = find_biggest(*stack);
	if ((*stack)->value == biggest)
		ra(stack);
	else if ((*stack)->next->value == biggest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}