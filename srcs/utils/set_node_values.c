#include "push_swap.h"

t_push_swap	*get_smallest(t_push_swap *stack)
{
	t_push_swap *res;

	res = stack;
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

void	reset_targets(t_push_swap *b)
{
	while (b)
	{
		b->target = NULL;
		b = b->next;
	}
}

void	set_target(t_push_swap *a, t_push_swap *b)
{
	t_push_swap *prospect;
	t_push_swap *smallest;
	
	prospect = a;
	smallest = get_smallest(a);
	reset_targets(b);
	while (b)
	{
		while (prospect)
		{
			if (!b->target && b->value < prospect->value)
				b->target = prospect;
			else if (b->target)
			{
				if (b->target->value > prospect->value && prospect->value > b->value)
					b->target = prospect;
			}
			prospect = prospect->next;
		}
		if (!b->target)
			b->target = smallest;
		prospect = a;
		b = b->next;
	}
}

void	cost_aux(t_push_swap *b, size_t len_a, size_t len_b)
{
	size_t	nums_above[2];
	size_t	nums_below[2];

	while (b)
	{
		if (b->above_median && b->target->above_median)
		{
			nums_above[0] = b->target->position;
			nums_above[1] = b->position;
			if (nums_above[0] && nums_above[1])
			{
				if (nums_above[0] <= nums_above[1])
					b->cost_to_move -= nums_above[0];
				else
					b->cost_to_move -= nums_above[1];
			}
		}
		else if (!b->above_median && !b->target->above_median)
		{
			nums_below[0] = len_a - (b->target->position + 1);
			nums_below[1] = len_b - (b->position + 1);
			if (nums_below[0] >= nums_above[1])
				b->cost_to_move -= nums_below[0];
			else
				b->cost_to_move -= nums_below[1];
		}
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
		if (b->target->above_median == true)
			b->cost_to_move += b->target->position;
		else
			b->cost_to_move += len_a - b->target->position;
		b = b->next;
	}
	cost_aux(b, len_a, len_b);
}

void	set_cheapest(t_push_swap *b) 
{	
	t_push_swap *current_cheapest;
	
	if (b == NULL)
		return ;
	current_cheapest = b;
	current_cheapest->cheapest = true;
	b = b->next;
	while (b)
	{
		if (current_cheapest->cost_to_move > b->cost_to_move)
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