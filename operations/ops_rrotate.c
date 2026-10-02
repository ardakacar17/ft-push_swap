/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:39:08 by akacar            #+#    #+#             */
/*   Updated: 2026/10/02 13:42:07 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*a || !(*a)->next)
		return ;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*b || !(*b)->next)
		return ;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*a && (*a)->next)
	{
		second_last = *a;
		while (second_last->next->next)
			second_last = second_last->next;
		last = second_last->next;
		second_last->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (*b && (*b)->next)
	{
		second_last = *b;
		while (second_last->next->next)
			second_last = second_last->next;
		last = second_last->next;
		second_last->next = NULL;
		last->next = *b;
		*b = last;
	}
	ft_printf("rrr\n");
}
