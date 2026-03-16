/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:15 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:34:16 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_cheapest(t_ctx *ctx)
{
	t_stack	*tmp;
	int		min_cost;
	int		best_bi;
	int		cost;

	tmp = ctx->b;
	min_cost = -1;
	best_bi = -1;
	while (tmp)
	{
		cost = cost_to_top(ctx->a, find_target(ctx->a, tmp->index))
			+ cost_to_top(ctx->b, tmp->index);
		if (min_cost == -1 || cost < min_cost)
		{
			min_cost = cost;
			best_bi = tmp->index;
		}
		tmp = tmp->next;
	}
	bring_to_top(ctx, find_target(ctx->a, best_bi), best_bi);
	pa(ctx);
}

void	sort_complex(t_ctx *ctx)
{
	int	size;

	if (is_sorted(ctx->a))
		return ;
	size = stack_size(ctx->a);
	if (size <= 3)
		return (sort_three(ctx));
	while (size-- > 3)
		pb(ctx);
	sort_three(ctx);
	while (ctx->b)
		push_cheapest(ctx);
	while (ctx->a->index != find_min_index(ctx->a))
	{
		if (get_position(ctx->a, find_min_index(ctx->a))
			<= stack_size(ctx->a) / 2)
			ra(ctx);
		else
			rra(ctx);
	}
}
