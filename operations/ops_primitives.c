/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_primitives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:10:00 by akacar            #+#    #+#             */
/*   Updated: 2026/10/10 17:06:26 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rev_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*s || !(*s)->next)
		return ;
	second_last = *s;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *s;
	*s = last;
}
