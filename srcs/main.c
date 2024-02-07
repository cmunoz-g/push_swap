// 1 - gestionar estructura de datos linked list
// 2 - gestionar comandos posibles (ra, rb, rra, etc)
// 3 - implementar algoritmos
// 4 - bonus

#include "push_swap.h"

// ideas: puedo utilizar sa, ss, sb de alguna forma? quiza anadiendo mas condiciones, comprobar una vez funcione la ft. por ejemplo si el target esta en la 2 pos?
// revisar comentarios del video e investigar para ver si se pude optimizar mas aun;


// ./push_swap 3 2 1 4 5 -4 -2 10 6 9 esto bien
// ./push_swap 3 2 1 4 5 -4 -2 10 6 esto no :( (CASO 1)
// ./push_swap 3 2 1 4 5 -4 -2 10 6 9 8 esto no crashea pero no lo ordena

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
	if (is_sorted(a, argv, flag))
	{
		if (len_a == 2)
			sa(&a);
		else if (len_a == 3)
			sort_small(&a);
		else
			push_swap(&a, &b);
	}
	printf("\n");
	while (a)
	{
		printf("%d\n",a->value);
		a = a->next;
	}
	free_stack(&a);
	return (0);
}
