/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:36:44 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:36:45 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				val;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;

typedef struct s_ctx
{
	t_stack	*a;
	t_stack	*b;
	t_ops	ops;
	int		bench;
	int		strategy;
}	t_ctx;

/* strategy constants */
# define STRAT_ADAPTIVE 0
# define STRAT_SIMPLE   1
# define STRAT_MEDIUM   2
# define STRAT_COMPLEX  3

/* stack_utils.c */
t_stack	*new_node(int val);
void	push_front(t_stack **stack, t_stack *node);
t_stack	*pop_front(t_stack **stack);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);

/* ops_swap.c */
void	sa(t_ctx *ctx);
void	sb(t_ctx *ctx);
void	ss(t_ctx *ctx);

/* ops_push.c */
void	pa(t_ctx *ctx);
void	pb(t_ctx *ctx);

/* ops_rotate.c */
void	ra(t_ctx *ctx);
void	rb(t_ctx *ctx);
void	rr(t_ctx *ctx);
void	rra(t_ctx *ctx);
void	rrb(t_ctx *ctx);

/* ops_rrotate.c */
void	rrr(t_ctx *ctx);

/* parse.c */
t_stack	*parse_args(int ac, char **av);
void	assign_index(t_stack *stack, int size);
int		parse_flags(int ac, char **av, int *bench, int *strat);

/* sort_utils.c */
int		is_sorted(t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
int		get_position(t_stack *stack, int index);
double	compute_disorder(t_stack *stack);

/* sort_small.c */
void	sort_two(t_ctx *ctx);
void	sort_three(t_ctx *ctx);
void	sort_small(t_ctx *ctx);

/* sort_simple.c - O(n^2) selection sort */
int		ft_isqrt(int n);
void	sort_simple(t_ctx *ctx);

/* sort_medium.c - O(n*sqrt(n)) chunk sort */
void	sort_medium(t_ctx *ctx);

/* sort_complex.c - O(n log n) greedy cost helpers */
int		find_target(t_stack *a, int b_index);
int		cost_to_top(t_stack *stack, int index);
void	bring_to_top(t_ctx *ctx, int ai, int bi);

/* sort_complex2.c */
void	sort_complex(t_ctx *ctx);

/* sort_adaptive.c */
void	sort_adaptive(t_ctx *ctx);

/* bench.c */
void	print_bench(t_ctx *ctx, double disorder, int strategy);

/* error.c */
void	error_exit(t_ctx *ctx);
void	ctx_init(t_ctx *ctx);
int		ft_strcmp(const char *a, const char *b);

char	**ft_split(char *argv);
int		ft_atoi_safe(const char *s, long *result);
int		has_duplicate(t_stack *stack, int val);
void	push_back(t_stack **stack, t_stack *node);

#endif
