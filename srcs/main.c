#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap	*a;
	t_push_swap *b;
	size_t		len_a;

	a = NULL;
	b = NULL;
	if (argc == 1) 
		return (0);
	check_args(a, argv);
	stack_init(&a, argv);
	len_a = stack_len(a);
	if (is_sorted(a) == 1 && len_a)
	{
		if (len_a == 2)
			sa(&a);
		else if (len_a == 3)
			sort_small(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}
