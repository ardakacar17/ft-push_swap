/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:38:28 by akacar            #+#    #+#             */
/*   Updated: 2026/10/02 13:42:01 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (*a && (*a)->next)
	{
		first = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
	if (*b && (*b)->next)
	{
		first = *b;
		*b = (*b)->next;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
	ft_printf("rr\n");
}
