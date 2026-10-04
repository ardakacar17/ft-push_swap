/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 01:00:36 by akacar            #+#    #+#             */
/*   Updated: 2026/10/03 22:30:41 by akacar           ###   ########.fr       */
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

static int	is_known_flag(char *str)
{
	if (!ft_strncmp(str, "--simple", 9))
		return (1);
	if (!ft_strncmp(str, "--medium", 9))
		return (1);
	if (!ft_strncmp(str, "--complex", 10))
		return (1);
	if (!ft_strncmp(str, "--adaptive", 11))
		return (1);
	if (!ft_strncmp(str, "--bench", 8))
		return (1);
	return (0);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (is_known_flag(argv[i]))
		{
			i++;
			continue ;
		}
		handle_arg(&a, argv[i]);
		i++;
	}
	return (a);
}
