/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:54:50 by zguney            #+#    #+#             */
/*   Updated: 2026/11/19 14:32:07 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_simple(t_ps *ps)
{
	int	k;

	k = 0;
	while (k < ps->size && !is_sorted(ps->a))
	{
		rot_a_to(ps, find_pos(ps->a, k));
		do_op(ps, PB);
		k++;
	}
	while (ps->b)
		do_op(ps, PA);
}
