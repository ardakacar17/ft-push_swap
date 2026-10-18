/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:56:53 by zguney            #+#    #+#             */
/*   Updated: 2026/10/17 17:56:58 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_adaptive(t_ps *ps)
{
	if (ps->disorder < 0.2)
		sort_simple(ps);
	else if (ps->disorder < 0.5)
		sort_medium(ps);
	else
		sort_complex(ps);
}

void	run_strategy(t_ps *ps)
{
	if (ps->cfg.strategy == SIMPLE)
		sort_simple(ps);
	else if (ps->cfg.strategy == MEDIUM)
		sort_medium(ps);
	else if (ps->cfg.strategy == COMPLEX)
		sort_complex(ps);
	else
		sort_adaptive(ps);
}