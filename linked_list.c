#include "push_swap.h"

long	ft_atol(char *str)
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

void	stack_add_back(t_push_swap **stack, int nbr, bool flag)
{
	t_push_swap *new_node;
	t_push_swap *last_node;

	new_node = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!new_node)
		error(stack,) // ?? pensar como gestionar esto
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

void	stack_init(t_push_swap **stack, char **argv, bool flag)
{
	long	nbr;
	
	while (*argv)
	{
		if (check_args(*argv))
			error(stack, argv, flag);
		nbr = ft_atol(*argv);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error(stack, argv, flag);
		if (check_repeat(*stack, (int)nbr))
			error(stack, argv, flag);
		stack_add_back(stack, (int)nbr, flag)
		argv++;
	}
	if (flag)
		free_table(argv);
}