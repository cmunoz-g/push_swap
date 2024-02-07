#include "push_swap.h"

t_push_swap	*get_cheapest(t_push_swap *stack)
{
	while (stack->cheapest == false)
		stack = stack->next;
	return (stack);
}

void	end_rotation(t_push_swap **stack, char which_stack, t_push_swap *target)
{
	size_t i = 0;

	if (which_stack == 'a')
	{
		if (target->above_median == true) 
			while (*stack != target && i++ != 100 ) // se queda stuckeado en este while con el caso 1
				ra(stack);
		else 
			while (*stack != target)
				rra(stack);
	}
	else
	{
		if (target->above_median == true)
			while (*stack != target)
				rb(stack);
		else 
			while (*stack != target)
				rrb(stack);
	}
}

void	move_nodes(t_push_swap **a, t_push_swap **b)
{
	t_push_swap *cheap;

	cheap = get_cheapest(*b);
	if (cheap->above_median == true && cheap->target->above_median == true)
		while ((*a)->cheapest == false && (*b)->cheapest == false)
			rrr(a, b);
	else if (cheap->above_median == false && cheap->target->above_median == false)
		while ((*a)->cheapest == false && (*b)->cheapest == false)
			rr(a, b);
	set_current_pos(*a);
	set_current_pos(*b);
	end_rotation(a, 'a', cheap->target);
	end_rotation(b, 'b', cheap);
	pa(a, b);
}

void	push_swap(t_push_swap **a, t_push_swap **b)
{
	size_t	len_a;
	t_push_swap *smallest;

	len_a = stack_len(*a);
	while (len_a != 3)
	{
		pb(a, b);
		len_a--;
	}
	sort_small(a);

	//testing
	set_node_values(*a, *b);
	while ((*b)->cheapest == false)
		(*b) = (*b)->next;
	printf("cheapest %d\n",(*b)->value);
	printf("target %d\n",(*b)->target->value);
	//testing. me sale en esta posicion con caso 1 que el 1 es el cheapest

	while (*b)
	{
		set_node_values(*a, *b);
		move_nodes(a, b);
	}
	set_current_pos(*a);
	smallest = get_smallest(*a);
	while (*a != smallest)
	{
		if (smallest->above_median == true)
			ra(a);
		else
			rra(a);
	}
}