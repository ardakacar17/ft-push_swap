/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 01:00:36 by akacar            #+#    #+#             */
/*   Updated: 2026/09/30 00:29:53 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_duplicate(t_stack *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	handle_arg(t_stack **a, char *str)
{
	int		value;
	t_stack	*new;

	if (!is_valid_int(str))
	{
		stack_free(a);
		write(2, "Error\n", 6);
		exit(1);
	}
	value = ft_atoi(str);
	if (is_duplicate(*a, value))
	{
		stack_free(a);
		write(2, "Error\n", 6);
		exit(1);
	}
	new = new_node(value);
	if (!new)
	{
		stack_free(a);
		exit(1);
	}
	stack_add_back(a, new);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 0;
	while (i < argc)
	{
		handle_arg(&a, argv[i]);
		i++;
	}
	return (a);
}
