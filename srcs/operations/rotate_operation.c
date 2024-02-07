#include "push_swap.h"

void	rotate(t_push_swap **stack)
{
	t_push_swap *last;
	t_push_swap *second;

	if (stack && *stack)
	{
		last = find_last_node(*stack);
		second = (*stack)->next;
		last->next = (*stack);
		(*stack)->prev = last;
		(*stack)->next = NULL;
		*stack = second;
		second->prev = NULL;
	}
}

void	ra(t_push_swap **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_push_swap **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_push_swap **a, t_push_swap **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}