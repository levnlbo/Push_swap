/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:35:01 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:35:02 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	push_front(stack, last);
}

void	rra(t_ctx *ctx)
{
	rev_rotate(&ctx->a);
	ctx->ops.rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_ctx *ctx)
{
	rev_rotate(&ctx->b);
	ctx->ops.rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_ctx *ctx)
{
	rev_rotate(&ctx->a);
	rev_rotate(&ctx->b);
	ctx->ops.rrr++;
	write(1, "rrr\n", 4);
}
