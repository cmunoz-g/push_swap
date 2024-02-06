// 1 - gestionar estructura de datos linked list
// 2 - gestionar comandos posibles (ra, rb, rra, etc)
// 3 - implementar algoritmos
// 4 - bonus

int	main(int argc, char *argv[])
{
	t_push_swap	*a;
	t_push_swap *b;
	size_t		len_a;

	a = NULL;
	b = NULL;
	// gestionar argc, si es 2 flag es true
	len_a = stack_len(a);
	if (!is_sorted(a)) // ft para comprobar
	{
		if (len_a == 2)
			sa(&a, false);
		else if (len_a == 3)
			sort_small(&a);
		else
			push_swap(&a);
	}
	free_stack(&a);
	return (0);
}