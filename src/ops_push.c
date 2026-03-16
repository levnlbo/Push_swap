/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:45 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:34:49 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ctx *ctx)
{
	push_front(&ctx->a, pop_front(&ctx->b));
	ctx->ops.pa++;
	write(1, "pa\n", 3);
}

void	pb(t_ctx *ctx)
{
	push_front(&ctx->b, pop_front(&ctx->a));
	ctx->ops.pb++;
	write(1, "pb\n", 3);
}
