/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <levon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:35:07 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 18:28:03 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_safe(const char *s, long *result)
{
	int		sign;
	long	n;

	sign = 1;
	n = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s++ - '0');
		if (n * sign > 2147483647 || n * sign < -2147483648)
			return (0);
	}
	if (*s)
		return (0);
	*result = n * sign;
	return (1);
}

static int	has_duplicate(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->val == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*node;
	long	val;
	int		i;

	stack = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		if (!ft_atoi_safe(argv[i], &val) || has_duplicate(stack, (int)val))
			return (free_stack(&stack), NULL);
		node = new_node((int)val);
		if (!node)
			return (free_stack(&stack), NULL);
		push_front(&stack, node);
		i--;
	}
	return (stack);
}

void	assign_index(t_stack *stack, int size)
{
	t_stack	*tmp;
	t_stack	*min;
	int		i;

	i = 0;
	while (i < size)
	{
		tmp = stack;
		min = NULL;
		while (tmp)
		{
			if (tmp->index == 0 && (!min || tmp->val < min->val))
				min = tmp;
			tmp = tmp->next;
		}
		if (min)
			min->index = i + 1;
		i++;
	}
}

int	parse_flags(int argc, char **argv, int *bench, int *strat)
{
	int	i;

	i = 1;
	*bench = 0;
	*strat = STRAT_ADAPTIVE;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--bench"))
			*bench = 1;
		else if (!ft_strcmp(argv[i], "--simple"))
			*strat = STRAT_SIMPLE;
		else if (!ft_strcmp(argv[i], "--medium"))
			*strat = STRAT_MEDIUM;
		else if (!ft_strcmp(argv[i], "--complex"))
			*strat = STRAT_COMPLEX;
		else if (!ft_strcmp(argv[i], "--adaptive"))
			*strat = STRAT_ADAPTIVE;
		else
			return (i);
		i++;
	}
	return (i);
}
