#include "push_swap.h"

void	swap(t_push_swap **stack)
{
	t_push_swap	*first;
	t_push_swap *second;

	first = *stack;
	second = (*stack)->next;
	if (*stack && (*stack)->next)
	{
		first->next = second->next;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		(*stack) = second;
	}
}

void	sa(t_push_swap **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_push_swap **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_push_swap **a, t_push_swap **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}