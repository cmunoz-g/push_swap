#include "push_swap.h"

long	ft_atol(char *str, t_push_swap **stack)
{
	long	res;
	int		neg;

	res = 0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (!(*str))
		error(stack);
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * neg);
}

size_t	stack_len(t_push_swap *stack)
{
	size_t	i;
	
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_push_swap	*find_last_node(t_push_swap *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_push_swap **stack, int nbr)
{
	t_push_swap *new_node;
	t_push_swap *last_node;

	new_node = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!new_node)
		error(stack);
	new_node->value = nbr;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (stack && *stack)
	{
		last_node = find_last_node(*stack);	
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	else
		*stack = new_node;
}

void	stack_init(t_push_swap **stack, char **argv)
{
	long	nbr;
	size_t	i;
	
	i = 1;
	while (argv[i])
	{
		nbr = ft_atol(argv[i], stack);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error(stack);
		if (check_repeat(*stack, (int)nbr))
			error(stack);
		stack_add_back(stack, (int)nbr);
		i++;
	}
}