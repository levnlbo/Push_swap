/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <levon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:04 by levon             #+#    #+#             */
/*   Updated: 2026/03/13 15:14:49 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** disorder < 0.2  -> O(n^2)
** disorder < 0.5  -> O(n*sqrt(n))
** disorder >= 0.5 -> O(n log n)
*/

void	sort_adaptive(t_ctx *ctx)
{
	double	disorder;
	int		size;

	if (is_sorted(ctx->a))
		return ;
	size = stack_size(ctx->a);
	disorder = compute_disorder(ctx->a);
	if (size <= 2)
		sort_two(ctx);
	else if (size <= 5)
		sort_small(ctx);
	else if (disorder < 0.2)
		sort_simple(ctx);
	else if (disorder < 0.5)
		sort_medium(ctx);
	else
		sort_complex(ctx);
}
