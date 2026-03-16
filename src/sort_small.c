/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:35:27 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:35:28 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_ctx *ctx)
{
	if (ctx->a->index > ctx->a->next->index)
		sa(ctx);
}

void	sort_three(t_ctx *ctx)
{
	int	top;
	int	mid;
	int	bot;

	top = ctx->a->index;
	mid = ctx->a->next->index;
	bot = ctx->a->next->next->index;
	if (top > mid && mid < bot && top < bot)
		sa(ctx);
	else if (top > mid && mid > bot)
	{
		sa(ctx);
		rra(ctx);
	}
	else if (top > mid && top > bot)
		ra(ctx);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(ctx);
		ra(ctx);
	}
	else if (top < mid && mid > bot)
		rra(ctx);
}

static void	push_mins_to_b(t_ctx *ctx)
{
	int	size;
	int	min;

	size = stack_size(ctx->a);
	while (size > 3)
	{
		min = find_min_index(ctx->a);
		if (get_position(ctx->a, min) <= size / 2)
			while (ctx->a->index != min)
				ra(ctx);
		else
			while (ctx->a->index != min)
				rra(ctx);
		pb(ctx);
		size--;
	}
}

void	sort_small(t_ctx *ctx)
{
	push_mins_to_b(ctx);
	sort_three(ctx);
	while (ctx->b)
		pa(ctx);
}
