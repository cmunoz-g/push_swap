// 1 - gestionar estructura de datos linked list
// 2 - gestionar comandos posibles (ra, rb, rra, etc)
// 3 - implementar algoritmos
// 4 - bonus

#include "push_swap.h"

// ideas: puedo utilizar sa, ss, sb de alguna forma? quiza anadiendo mas condiciones, comprobar una vez funcione la ft. por ejemplo si el target esta en la 2 pos?
// revisar comentarios del video e investigar para ver si se pude optimizar mas aun;

// queda esto: pasar tests y demas, arreglar el parseo de si lo paso en un solo str todo, comprobar formas de hacerlo algo mas eficiente, quitar la mierda, organizar los archivos para que quede todo limpio 
// y menos de 5 ft por archivo, pensar en casos edge, bonus. ir pasando tests en cada punto comprobar que no me lo estoy cargando

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
	// // revisar bien si el prev se guarda correctamente, cuando llamo rra en el push_swap parece que el prev esta mal guardado?????????
	// while (a) 
	// {
	// 	printf("valor:%d   ",a->value);
	// 	if (a->prev)
	// 		printf("   valor del prev:%d   ",a->prev->value);
	// 	else
	// 		printf("   no prev             ");
	// 	if (a->next)
	// 		printf("   valor del next:%d   ",a->next->value);
	// 	else
	// 		printf("   no NEXT             ");
	// 	printf("\n");
	// 	a = a->next;
	// }
	// exit(0);
	len_a = stack_len(a);
	if (is_sorted(a, argv, flag) == 1)
	{
		if (len_a == 2)
			sa(&a);
		else if (len_a == 3)
			sort_small(&a);
		else
			push_swap(&a, &b);
	}
	// printf("\n");
	// while (a)
	// {
	// 	printf("%d\n",a->value);
	// 	a = a->next;
	// }
	free_stack(&a);
	return (0);
}
