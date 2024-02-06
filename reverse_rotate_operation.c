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