/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:33:46 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:33:47 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	top = pop_front(stack);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
}

void	ra(t_ctx *ctx)
{
	rotate(&ctx->a);
	ctx->ops.ra++;
	write(1, "ra\n", 3);
}

void	rb(t_ctx *ctx)
{
	rotate(&ctx->b);
	ctx->ops.rb++;
	write(1, "rb\n", 3);
}

void	rr(t_ctx *ctx)
{
	rotate(&ctx->a);
	rotate(&ctx->b);
	ctx->ops.rr++;
	write(1, "rr\n", 3);
}
