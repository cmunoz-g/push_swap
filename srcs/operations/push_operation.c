#include "push_swap.h"

void	push(t_push_swap **source_stack, t_push_swap **dest_stack)
{
	t_push_swap	*node_to_move;
	t_push_swap *aux;

	if (source_stack && *source_stack)
	{
		node_to_move = *source_stack;
		*source_stack = (*source_stack)->next;
		if (*source_stack)
			(*source_stack)->prev = NULL;
		aux = *dest_stack;
		*dest_stack = node_to_move;
		node_to_move->prev = NULL;
		node_to_move->next = aux;
		if (aux)
			aux->prev = node_to_move;
	}
}

void	pa(t_push_swap **a, t_push_swap **b)
{
	push(b,a);
	write(1, "pa\n", 3);
}

void	pb(t_push_swap **a, t_push_swap **b)
{
	push(a,b);
	write(1, "pb\n", 3);
}