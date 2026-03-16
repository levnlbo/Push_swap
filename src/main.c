/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levon <levon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:33:38 by levon             #+#    #+#             */
/*   Updated: 2026/03/11 19:05:02 by levon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_ctx *ctx, double disorder)
{
	if (ctx->strategy == STRAT_SIMPLE)
		sort_simple(ctx);
	else if (ctx->strategy == STRAT_MEDIUM)
		sort_medium(ctx);
	else if (ctx->strategy == STRAT_COMPLEX)
		sort_complex(ctx);
	else
		sort_adaptive(ctx);
	(void)disorder;
}

static void	sort_by_size(t_ctx *ctx, double disorder)
{
	int	size;

	size = stack_size(ctx->a);
	if (size == 2)
		sort_two(ctx);
	else if (size <= 5)
		sort_small(ctx);
	else
		run_strategy(ctx, disorder);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	int		arg_start;
	double	disorder;

	if (argc < 2)
		return (0);
	ctx_init(&ctx);
	arg_start = parse_flags(argc, argv, &ctx.bench, &ctx.strategy);
	if (arg_start >= argc)
		return (0);
	ctx.a = parse_args(argc - arg_start + 1, argv + arg_start - 1);
	if (!ctx.a)
		error_exit(&ctx);
	assign_index(ctx.a, stack_size(ctx.a));
	disorder = compute_disorder(ctx.a);
	if (!is_sorted(ctx.a))
		sort_by_size(&ctx, disorder);
	if (ctx.bench)
		print_bench(&ctx, disorder, ctx.strategy);
	free_stack(&ctx.a);
	free_stack(&ctx.b);
	return (0);
}
