#include "push_swap.h"

void	move_nodes(t_push_swap **a, t_push_swap **b)
{

}


void	push_swap(t_push_swap **a, t_push_swap **b)
{
	size_t	len_a;

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

}