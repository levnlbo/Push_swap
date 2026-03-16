/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:35:14 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:35:15 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(t_stack *a, int b_index)
{
	t_stack	*tmp;
	int		best;
	int		found;

	best = find_max_index(a) + 1;
	found = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < best)
		{
			best = tmp->index;
			found = 1;
		}
		tmp = tmp->next;
	}
	if (!found)
		return (find_min_index(a));
	return (best);
}

int	cost_to_top(t_stack *stack, int index)
{
	int	size;
	int	pos;

	size = stack_size(stack);
	pos = get_position(stack, index);
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

static void	do_rotations(t_ctx *ctx, int ca, int cb, int dir)
{
	if (dir == 1)
		while (ca-- > 0 && cb-- > 0)
			rr(ctx);
	else
		while (ca-- > 0 && cb-- > 0)
			rrr(ctx);
}

static void	rotate_a_to(t_ctx *ctx, int ai, int sa, int pa)
{
	while (ctx->a->index != ai)
	{
		if (sa <= pa / 2)
			ra(ctx);
		else
			rra(ctx);
	}
}

void	bring_to_top(t_ctx *ctx, int ai, int bi)
{
	int	sa;
	int	sb;
	int	pa;
	int	pb;

	sa = get_position(ctx->a, ai);
	sb = get_position(ctx->b, bi);
	pa = stack_size(ctx->a);
	pb = stack_size(ctx->b);
	if (sa <= pa / 2 && sb <= pb / 2)
		do_rotations(ctx, sa, sb, 1);
	else if (sa > pa / 2 && sb > pb / 2)
		do_rotations(ctx, pa - sa, pb - sb, -1);
	rotate_a_to(ctx, ai, sa, pa);
	while (ctx->b->index != bi)
	{
		if (sb <= pb / 2)
			rb(ctx);
		else
			rrb(ctx);
	}
}
