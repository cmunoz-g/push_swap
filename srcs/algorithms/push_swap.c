#include "push_swap.h"

void	get_cheapest(t_push_swap *stack)
{
	while (stack->cheapest == false)
		stack = stack->next;
	return (stack);
}

void	end_rotation(t_push_swap **stack, char which_stack, t_push_swap *target)
{
	if (which_stack == 'a')
	{
		if (target->median == true)
			while (*stack != target)
				ra(stack);
		else 
			while (*stack != target)
				rra(stack);
	}
	else
	{
		if (target->median == true)
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

	cheap = get_cheapest(b);
	if (cheap->median == true && cheap->target_node->median == true)
		while ((*a)->cheapest == false && (*b)->cheapest == false)
			rrr(a, b);
	else if (cheap->median == false && cheap->target_node->median == false)
		while ((*a)->cheapest == false && (*b)->cheapest == false)
			rr(a, b);
	end_rotation(a, 'a', cheap->target_node);
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
	while (*b)
	{
		set_node_values(*a, *b);
		move_nodes(a, b);
	}
	set_current_pos(a);
	smallest = get_smallest(a);
	while (*a != smallest)
	{
		if (smallest->median = true)
			ra(a);
		else
			rra(a);
	}
}