/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:55:42 by zguney            #+#    #+#             */
/*   Updated: 2026/10/18 14:31:15 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_ps *ps, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(ps->a);
	while (i < size)
	{
		if (((ps->a->index >> bit) & 1) == 1)
			do_op(ps, RA);
		else
			do_op(ps, PB);
		i++;
	}
	while (ps->b)
		do_op(ps, PA);
}

void	sort_complex(t_ps *ps)
{
	int	bits;
	int	bit;

	bits = count_bits(ps->size - 1);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(ps, bit);
		bit++;
	}
}
