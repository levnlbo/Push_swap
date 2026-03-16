/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:34 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:34:35 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ctx_init(t_ctx *ctx)
{
	ctx->a = NULL;
	ctx->b = NULL;
	ctx->bench = 0;
	ctx->strategy = STRAT_ADAPTIVE;
	ctx->ops.sa = 0;
	ctx->ops.sb = 0;
	ctx->ops.ss = 0;
	ctx->ops.pa = 0;
	ctx->ops.pb = 0;
	ctx->ops.ra = 0;
	ctx->ops.rb = 0;
	ctx->ops.rr = 0;
	ctx->ops.rra = 0;
	ctx->ops.rrb = 0;
	ctx->ops.rrr = 0;
}

void	error_exit(t_ctx *ctx)
{
	free_stack(&ctx->a);
	free_stack(&ctx->b);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}
