/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:56:53 by zguney            #+#    #+#             */
/*   Updated: 2026/10/18 19:39:10 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_strategy	resolve_strategy(t_ps *ps)
{
	if (ps->cfg.strategy != ADAPTIVE)
		return (ps->cfg.strategy);
	if (ps->disorder < 0.2)
		return (SIMPLE);
	if (ps->disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	run_strategy(t_ps *ps)
{
	t_strategy	s;

	s = resolve_strategy(ps);
	if (s == SIMPLE)
		sort_simple(ps);
	else if (s == MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}
