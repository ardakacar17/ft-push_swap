/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:56:08 by zguney            #+#    #+#             */
/*   Updated: 2026/10/18 13:04:56 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	chunk_size(int size)
{
	int	root;

	root = 1;
	while (root * root < size)
		root++;
	return (root * 3 / 2);
}

static void	push_to_b(t_ps *ps, int chunk)
{
	int	pushed;

	pushed = 0;
	while (ps->a)
	{
		if (ps->a->index <= pushed)
		{
			do_op(ps, PB);
			do_op(ps, RB);
			pushed++;
		}
		else if (ps->a->index <= pushed + chunk)
		{
			do_op(ps, PB);
			pushed++;
		}
		else
			do_op(ps, RA);
	}
}

static void	push_back_to_a(t_ps *ps)
{
	int	target;

	target = ps->size - 1;
	while (ps->b)
	{
		rot_b_to(ps, find_pos(ps->b, target));
		do_op(ps, PA);
		target--;
	}
}

void	sort_medium(t_ps *ps)
{
	push_to_b(ps, chunk_size(ps->size));
	push_back_to_a(ps);
}
