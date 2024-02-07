#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct	s_push_swap
{
	int		value;
	int		position;
	int		cost_to_move;
	bool	above_median;
	bool	cheapest;
	struct	s_push_swap *target;
	struct 	s_push_swap *next;
	struct 	s_push_swap *prev;
}				t_push_swap;

#endif