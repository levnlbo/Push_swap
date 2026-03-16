/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:27 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:34:28 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	find_max_index(t_stack *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

double	compute_disorder(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	double	m;
	double	t;

	m = 0;
	t = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			t++;
			if (i->index > j->index)
				m++;
			j = j->next;
		}
		i = i->next;
	}
	if (t == 0)
		return (0);
	return (m / t);
}
