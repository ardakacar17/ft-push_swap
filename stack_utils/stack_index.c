/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:14:46 by akacar            #+#    #+#             */
/*   Updated: 2026/10/14 00:00:38 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*cur;
	int		i;

	cur = a;
	while (cur)
	{
		i = 0;
		tmp = a;
		while (tmp)
		{
			if (tmp->value < cur->value)
				i++;
			tmp = tmp->next;
		}
		cur->index = i;
		cur = cur->next;
	}
}
