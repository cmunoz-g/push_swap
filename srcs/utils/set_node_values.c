#include "push_swap.h"

t_push_swap	*get_smallest(t_push_swap *stack)
{
	t_push_swap *res;

	res = stack
	while (stack)
	{
		if (stack->value < res->value)
			res = stack;
		stack = stack->next;
	}
	return (res);
}

void	set_current_pos(t_push_swap *stack)
{
	size_t	median;
	size_t	pos;

	median = stack_len(stack) / 2;
	pos = 0;
	while (stack)
	{
		stack->position = pos;
		if (pos <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		pos++;
		stack = stack->next;
	}
}

void	set_target(t_push_swap *a, t_push_swap *b)
{
	t_push_swap *prospect;
	t_push_swap *smallest;
	
	prospect = a;
	smallest = get_smallest(a);
	while (b)
	{
		while (prospect)
		{
			if (!b->target_node && b->value < prospect->value)
				b->target_node = prospect;
			else if (b->target_node)
			{
				if (b->target_value < prospect->value && prospect->value < b->target_node->value)
					b->target_node = prospect;
			}
			prospect = prospect->next;
		}
		if (!b->target_node)
			b->target_node = smallest;
		prospect = a;
		b = b->next;
	}
}

void	set_cost(t_push_swap *a, t_push_swap *b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->cost_to_move = b->position;
		if (b->above_median == false)
			b->cost_to_move = len_b - b->position;
		if (b->target_node->above_median == true)
			b->cost_to_move += b->target_node->position;
		else
			b->cost_to_move += len_a - b->target_node->position;
		b = b->next;
	}
}

void	set_cheapest(t_push_swap *b)
{	
	t_push_swap *current_cheapest;
	
	current_cheapest = b;
	current_cheapest->cheapest = true;
	b = b->next;
	while (b)
	{
		if (current_cheapest->cost_to_move < b->cost_to_move)
		{
			current_cheapest->cheapest = false;
			b->cheapest = true;
			current_cheapest = b;
		}
		else
			b->cheapest = false;
		b = b->next;
	}
}

void	set_node_values(t_push_swap *a, t_push_swap *b)
{
	set_current_pos(a);
	set_current_pos(b);
	set_target(a, b);
	set_cost(a, b);
	set_cheapest(b);
}