/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_dispatch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:10:00 by akacar            #+#    #+#             */
/*   Updated: 2026/10/13 19:20:41 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

const char	*op_name(t_op op)
{
	static const char	*names[OP_COUNT] = {
		"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"
	};

	return (names[op]);
}

static int	apply_op(t_ps *ps, t_op op)
{
	int	moved;

	moved = 0;
	if (op == SA || op == SS)
		moved += swap(&ps->a);
	if (op == SB || op == SS)
		moved += swap(&ps->b);
	if (op == PA)
		moved += push(&ps->b, &ps->a);
	if (op == PB)
		moved += push(&ps->a, &ps->b);
	if (op == RA || op == RR)
		moved += rotate(&ps->a);
	if (op == RB || op == RR)
		moved += rotate(&ps->b);
	if (op == RRA || op == RRR)
		moved += rev_rotate(&ps->a);
	if (op == RRB || op == RRR)
		moved += rev_rotate(&ps->b);
	return (moved);
}

void	do_op(t_ps *ps, t_op op)
{
	const char	*name;

	if (!apply_op(ps, op))
		return ;
	ps->counts[op]++;
	name = op_name(op);
	ft_printf("%s\n", name);
}
