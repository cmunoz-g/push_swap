#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_push_swap
{
	int	value;
	struct s_push_swap *next;
	struct s_push_swap *prev;
}				t_push_swap;

#endif