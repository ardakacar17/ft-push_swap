/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 12:31:31 by zguney            #+#    #+#             */
/*   Updated: 2026/11/19 12:32:19 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_ps *ps)
{
	int	x;
	int	y;
	int	z;
 
	x = ps->a->index;
	y = ps->a->next->index;
	z = ps->a->next->next->index;
	if (x > y && y > z)
	{
		do_op(ps, SA);
		do_op(ps, RRA);
	}
	else if (x > y && x > z)
		do_op(ps, RA);
	else if (x > y)
		do_op(ps, SA);
	else if (y > z && x < z)
	{
		do_op(ps, RRA);
		do_op(ps, SA);
	}
	else if (y > z)
		do_op(ps, RRA);
}

static void	sort_four_five(t_ps *ps)
{
	int	k;
	int	pushed;

	k = 0;
	pushed = ps->size - 3;
	while (k < pushed)
	{
		rot_a_to(ps, find_pos(ps->a, k));
		do_op(ps, PB);
		k++;
	}
	sort_three(ps);
	while (k > 0)
	{
		do_op(ps, PA);
		k--;
	}
}

void	sort_small(t_ps *ps)
{
	if (ps->size == 2)
		do_op(ps, SA);
	else if (ps->size == 3)
		sort_three(ps);
	else
		sort_four_five(ps);
}
