/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:42:27 by zguney            #+#    #+#             */
/*   Updated: 2026/10/18 20:25:01 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy_name(t_strategy s)
{
	if (s == SIMPLE)
		return ("Simple");
	if (s == MEDIUM)
		return ("Medium");
	if (s == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*complexity_name(t_strategy s)
{
	if (s == SIMPLE)
		return ("O(n²)");
	if (s == MEDIUM)
		return ("O(n√n)");
	return ("O(n log n)");
}

static void	print_disorder(double disorder)
{
	long	pct;

	pct = (long)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(pct / 100), 2);
	ft_putchar_fd('.', 2);
	if (pct % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd((int)(pct % 100), 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_counts(t_ps *ps)
{
	long	total;
	int		i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += ps->counts[i];
		i++;
	}
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd((int)total, 2);
	ft_putchar_fd('\n', 2);
	i = 0;
	while (i < OP_COUNT)
	{
		ft_putstr_fd("[bench] ", 2);
		ft_putstr_fd((char *)op_name(i), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd((int)ps->counts[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void	print_bench(t_ps *ps)
{
	if (!ps->cfg.bench)
		return ;
	print_disorder(ps->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(ps->cfg.strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity_name(resolve_strategy(ps)), 2);
	ft_putchar_fd('\n', 2);
	print_counts(ps);
}
