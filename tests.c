#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef struct	s_push_swap
{
	int	value;
	struct s_push_swap *next;
	struct s_push_swap *prev;
}				t_push_swap;


t_push_swap	*find_last_node(t_push_swap *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

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

void	stack_add_back(t_push_swap **stack, int nbr)
{
	t_push_swap *new_node;
	t_push_swap *last_node;

	new_node = (t_push_swap *)malloc(sizeof(t_push_swap));
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
	
	while (*argv)
	{
		nbr = ft_atol(*argv);
		stack_add_back(stack, (int)nbr);
		argv++;
	}
}

int	find_biggest(t_push_swap *stack)
{
	int	res;
	
	res = stack->value;
	while (stack)
	{
		if (res < stack->value)
			res = stack->value;
		stack = stack->next;
	}
	printf("the biggest is:%d\n",res);
	return (res);
}

void	sort_small(t_push_swap **stack)
{
	int	biggest;

	biggest = find_biggest(*stack);
	if ((*stack)->value == biggest)
		ra(stack);
	else if ((*stack)->next->value == biggest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

int main()
{
	char *argv[] = {"1", "44", "7", NULL};
	t_push_swap *a;

	a = NULL;
	stack_init(&a,argv);
	
	sort_small(&a);
	while (a)
	{
		printf("%d\n",a->value);
		a = a->next;
	}
	return (0);
}