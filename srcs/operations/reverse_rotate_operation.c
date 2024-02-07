#include "push_swap.h"

void	reverse_rotate(t_push_swap **stack)
{
	t_push_swap *last_node;
	t_push_swap *new_last;

	if (stack && *stack)
	{
		last_node = find_last_node(*stack);
		new_last = last_node->prev;
		if (new_last)
			new_last->next = NULL;
		last_node->next = *stack;
		last_node->prev = NULL;
		(*stack)->prev = last_node;
		*stack = last_node;
	}
}

void	rra(t_push_swap **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_push_swap **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_push_swap **a, t_push_swap **b)
{	
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

// dejo esto comentado porque lo tengo en la ft de move nodes, pero puede que lo necesite luego

// void	rrr_both(t_push_swap **a, t_push_swap **b)
// {
// 	while ((*a)->cheapest == false && (*b)->cheapest == false)
// 		rrr(a, b);
// 	//set_current_pos(a);
// 	//set_current_pos(b);
// 	// estas dos lineas, creo que no son necesarias pero las voy a dejar de momento
// }
