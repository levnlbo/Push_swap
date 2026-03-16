/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:33:53 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:33:54 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = pop_front(stack);
	second = pop_front(stack);
	push_front(stack, first);
	push_front(stack, second);
}

void	sa(t_ctx *ctx)
{
	do_swap(&ctx->a);
	ctx->ops.sa++;
	write(1, "sa\n", 3);
}

void	sb(t_ctx *ctx)
{
	do_swap(&ctx->b);
	ctx->ops.sb++;
	write(1, "sb\n", 3);
}

void	ss(t_ctx *ctx)
{
	do_swap(&ctx->a);
	do_swap(&ctx->b);
	ctx->ops.ss++;
	write(1, "ss\n", 3);
}
