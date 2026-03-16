/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:35:32 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:35:52 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->val = val;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	push_front(t_stack **stack, t_stack *node)
{
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

t_stack	*pop_front(t_stack **stack)
{
	t_stack	*node;

	if (!*stack)
		return (NULL);
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	return (node);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
