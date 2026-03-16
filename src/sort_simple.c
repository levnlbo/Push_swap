/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:21 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:34:22 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	rotate_min_to_top(t_ctx *ctx)
{
	int	min;
	int	size;

	min = find_min_index(ctx->a);
	size = stack_size(ctx->a);
	if (get_position(ctx->a, min) <= size / 2)
		while (ctx->a->index != min)
			ra(ctx);
	else
		while (ctx->a->index != min)
			rra(ctx);
}

void	sort_simple(t_ctx *ctx)
{
	int	size;

	if (is_sorted(ctx->a))
		return ;
	size = stack_size(ctx->a);
	while (size > 1)
	{
		rotate_min_to_top(ctx);
		pb(ctx);
		size--;
	}
	while (ctx->b)
		pa(ctx);
}
