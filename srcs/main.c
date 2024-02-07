// 1 - gestionar estructura de datos linked list
// 2 - gestionar comandos posibles (ra, rb, rra, etc)
// 3 - implementar algoritmos
// 4 - bonus

#include <push_swap.h>

// ideas: puedo utilizar sa, ss, sb de alguna forma? quiza anadiendo mas condiciones, comprobar una vez funcione la ft
// revisar comentarios del video e investigar para ver si se pude optimizar mas aun;

int	main(int argc, char *argv[])
{
	t_push_swap	*a;
	t_push_swap *b;
	size_t		len_a;
	bool		flag;

	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		flag = true;
	}
	else if (argc == 1) // not sure si necesito esto
		return (0);
	flag = false;
	check_args(a, argv, flag);
	stack_init(&a, argv, flag);
	len_a = stack_len(a);
	if (!is_sorted(a))
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
