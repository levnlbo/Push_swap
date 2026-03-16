/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:33:33 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 17:33:34 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_int(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		write_int(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

static void	wstr(const char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

static void	print_strategy_line(int strategy, double disorder)
{
	if (strategy == STRAT_SIMPLE
		|| (strategy == STRAT_ADAPTIVE && disorder < 0.2))
		wstr("[bench] strategy:  Simple / O(n^2)\n", 2);
	else if (strategy == STRAT_MEDIUM
		|| (strategy == STRAT_ADAPTIVE && disorder < 0.5))
		wstr("[bench] strategy:  Medium / O(n*sqrt(n))\n", 2);
	else
		wstr("[bench] strategy:  Complex / O(n log n)\n", 2);
}

static void	print_op_counts(t_ops *ops)
{
	wstr("[bench] sa: ", 2);
	write_int(ops->sa, 2);
	wstr("  sb: ", 2);
	write_int(ops->sb, 2);
	wstr("  ss: ", 2);
	write_int(ops->ss, 2);
	wstr("  pa: ", 2);
	write_int(ops->pa, 2);
	wstr("  pb: ", 2);
	write_int(ops->pb, 2);
	wstr("\n[bench] ra: ", 2);
	write_int(ops->ra, 2);
	wstr("  rb: ", 2);
	write_int(ops->rb, 2);
	wstr("  rr: ", 2);
	write_int(ops->rr, 2);
	wstr("  rra: ", 2);
	write_int(ops->rra, 2);
	wstr("  rrb: ", 2);
	write_int(ops->rrb, 2);
	wstr("  rrr: ", 2);
	write_int(ops->rrr, 2);
	wstr("\n", 2);
}

void	print_bench(t_ctx *ctx, double disorder, int strategy)
{
	int	total;
	int	dp;
	int	dd;

	dp = (int)(disorder * 100);
	dd = (int)(disorder * 10000) % 100;
	total = ctx->ops.sa + ctx->ops.sb + ctx->ops.ss + ctx->ops.pa
		+ ctx->ops.pb + ctx->ops.ra + ctx->ops.rb + ctx->ops.rr
		+ ctx->ops.rra + ctx->ops.rrb + ctx->ops.rrr;
	wstr("[bench] disorder:  ", 2);
	write_int(dp, 2);
	wstr(".", 2);
	if (dd < 10)
		wstr("0", 2);
	write_int(dd, 2);
	wstr("%\n", 2);
	print_strategy_line(strategy, disorder);
	wstr("[bench] total_ops: ", 2);
	write_int(total, 2);
	wstr("\n", 2);
	print_op_counts(&ctx->ops);
}
