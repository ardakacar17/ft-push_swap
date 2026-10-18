/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:28:14 by zguney            #+#    #+#             */
/*   Updated: 2026/10/17 19:05:12 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot_a_to(t_ps *ps, int pos)//sırası pos olan elemanı tepeye getirmek. Elemanı tepeye getirmek için ya yukarı döndürürsün (ra, pos kadar) ya da aşağı döndürürsün (rra, size - pos kadar). Hangisi kısaysa onu seçmek hamle sayısını yarıya indirir.
{
	int	size;

	size = stack_size(ps->a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			do_op(ps, RA);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			do_op(ps, RRA);
			pos--;
		}
	}
}

void	rot_b_to(t_ps *ps, int pos)
{
	int	size;

	size = stack_size(ps->b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			do_op(ps, RB);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			do_op(ps, RRB);
			pos--;
		}
	}
}