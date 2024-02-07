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

t_push_swap	*find_last_node(t_push_swap *stack);
t_push_swap	*get_smallest(t_push_swap *stack);

void	push_swap(t_push_swap **a, t_push_swap **b);
void	move_nodes(t_push_swap **a, t_push_swap **b);
void	end_rotation(t_push_swap **stack, char which_stack, t_push_swap *target);
void	get_cheapest(t_push_swap *stack);
void	sort_small(t_push_swap **stack);
void	push(t_push_swap **source_stack, t_push_swap **dest_stack);
void	pa(t_push_swap **a, t_push_swap **b);
void	pb(t_push_swap **a, t_push_swap **b);
void	reverse_rotate(t_push_swap **stack);
void	rra(t_push_swap **a);
void	rrb(t_push_swap **b);
void	rrr(t_push_swap **a, t_push_swap **b);
void	rotate(t_push_swap **stack);
void	ra(t_push_swap **a);
void	rb(t_push_swap **b);
void	rr(t_push_swap **a, t_push_swap **b);
void	swap(t_push_swap **stack);
void	sa(t_push_swap **a);
void	sb(t_push_swap **b);
void	ss(t_push_swap **a, t_push_swap **b);
void	check_args(t_push_swap *a, char	**table, bool flag);
void	error(t_push_swap *stack, char **table, bool flag);
void	free_table(char	**table);
void	free_stack(t_push_swap **stack);
void	strfill(char **tab, char const *s, char c);
void	stack_add_back(t_push_swap **stack, int nbr, bool flag, char **argv);
void	stack_init(t_push_swap **stack, char **argv, bool flag);
void	set_current_pos(t_push_swap *stack);
void	set_target(t_push_swap *a, t_push_swap *b);
void	set_cost(t_push_swap *a, t_push_swap *b);
void	set_cheapest(t_push_swap *b);
void	set_node_values(t_push_swap *a, t_push_swap *b);

char	**ft_split(char const *s, char c);

int		main(int argc, char *argv[]);
int		check_repeat(t_push_swap *stack, int nbr);
int		find_biggest(t_push_swap *stack);
int		is_sorted(t_push_swap *stack)
int		strmem(char **tab, char const *s, char c, size_t words);

size_t	auxstrmem(char const *s, char c, size_t *j);
size_t	countwords(char const *s, char c);
size_t	stack_len(t_push_swap *stack);

long	ft_atol(char *str);

#endif