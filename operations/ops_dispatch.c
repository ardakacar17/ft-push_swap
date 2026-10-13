/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_dispatch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:10:00 by akacar            #+#    #+#             */
/*   Updated: 2026/10/11 12:45:49 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

const char	*op_name(t_op op)
{
	static const char	*names[OP_COUNT] =
	{
		"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"
	};
	return (names[op]);
}

void	apply_op(t_ps *ps, t_op op)
{
	if (op == SA || op == SS)
		swap(&ps->a);
	if (op == SB || op == SS)
		swap(&ps->b);
	if (op == PA)
		push(&ps->b, &ps->a);
	if (op == PB)
		push(&ps->a, &ps->b);
	if (op == RA || op == RR)
		rotate(&ps->a);
	if (op == RB || op == RR)
		rotate(&ps->b);
	if (op == RRA || op == RRR)
		rev_rotate(&ps->a);
	if (op == RRB || op == RRR)
		rev_rotate(&ps->b);
}

void	do_op(t_ps *ps, t_op op)
{
	const char	*name;

	apply_op(ps, op);
	ps->counts[op]++;
	name = op_name(op);
	ft_printf("%s\n", name);
}
