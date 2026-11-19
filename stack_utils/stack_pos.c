/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:28:34 by zguney            #+#    #+#             */
/*   Updated: 2026/10/17 19:06:12 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pos(t_stack *s, int index)
{
	int	pos;

	pos = 0;
	while (s)
	{
		if (s->index == index)
			return (pos);
		pos++;
		s = s->next;
	}
	return (-1);
}
