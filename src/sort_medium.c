/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <levon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:35:19 by levon             #+#    #+#             */
/*   Updated: 2026/03/27 17:44:13 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_one(t_ctx *ctx, int lo, int hi)
{
	int	mid;
	int	pos;

	mid = (lo + hi) / 2;
	pos = get_position(ctx->a, lo);
	if (ctx->a->index < lo || ctx->a->index > hi)
	{
		if (pos <= stack_size(ctx->a) / 2)
			ra(ctx);
		else
			rra(ctx);
	}
	else
	{
		pb(ctx);
		if (ctx->b->index > mid)
			rb(ctx);
	}
}

static void	push_all_chunks(t_ctx *ctx, int n)
{
	int	chunk;
	int	lo;
	int	hi;
	int	i;

	chunk = ft_isqrt(n) * 1.4;
	if (chunk < 1)
		chunk = 1;

	lo = 1;
	while (lo <= n)
	{
		hi = lo + chunk - 1;
		if (hi > n)
			hi = n;

		i = hi - lo + 1;
		while (i--)
			push_one(ctx, lo, hi);

		lo = hi + 1;
	}
}

static void	pull_back(t_ctx *ctx)
{
	int	max;
	int	pos;
	int	size;

	while (ctx->b)
	{
		max = find_max_index(ctx->b);
		pos = get_position(ctx->b, max);
		size = stack_size(ctx->b);

		if (pos <= size / 2)
			while (ctx->b->index != max)
				rb(ctx);
		else
			while (ctx->b->index != max)
				rrb(ctx);

		pa(ctx);
	}
}

static void	rotate_min_top(t_ctx *ctx)
{
	int	min;
	int	pos;
	int	size;

	min = find_min_index(ctx->a);
	pos = get_position(ctx->a, min);
	size = stack_size(ctx->a);

	if (pos <= size / 2)
		while (ctx->a->index != min)
			ra(ctx);
	else
		while (ctx->a->index != min)
			rra(ctx);
}

void	sort_medium(t_ctx *ctx)
{
	if (is_sorted(ctx->a))
		return ;
	push_all_chunks(ctx, stack_size(ctx->a));
	pull_back(ctx);
	rotate_min_top(ctx);
}
