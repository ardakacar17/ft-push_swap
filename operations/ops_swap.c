/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 00:50:38 by akacar            #+#    #+#             */
/*   Updated: 2026/10/02 13:42:09 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	int	tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = tmp;
	}
	if (*b && (*b)->next)
	{
		tmp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = tmp;
	}
	ft_printf("ss\n");
}
