/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 01:00:36 by akacar            #+#    #+#             */
/*   Updated: 2026/11/01 02:08:32 by akacar           ###   ########.fr       */
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

static int	handle_arg(t_stack **a, char *str)
{
	int		value;
	t_stack	*new;

	if (!is_valid_int(str))
		return (0);
	value = ft_atoi(str);
	if (is_duplicate(*a, value))
		return (0);
	new = new_node(value);
	if (!new)
		return (0);
	stack_add_back(a, new);
	return (1);
}

static void	handle_words(t_stack **a, char *arg)
{
	char	**words;
	int		ok;
	int		i;

	words = ft_split(arg, ' ');
	ok = (words && words[0]);
	i = 0;
	while (ok && words[i])
	{
		ok = handle_arg(a, words[i]);
		i++;
	}
	free_split(words);
	if (!ok)
	{
		stack_free(a);
		write(2, "Error\n", 6);
		exit(1);
	}
}

static int	set_flag(char *str, t_config *cfg)
{
	if (!ft_strncmp(str, "--simple", 9))
		cfg->strategy = SIMPLE;
	else if (!ft_strncmp(str, "--medium", 9))
		cfg->strategy = MEDIUM;
	else if (!ft_strncmp(str, "--complex", 10))
		cfg->strategy = COMPLEX;
	else if (!ft_strncmp(str, "--adaptive", 11))
		cfg->strategy = ADAPTIVE;
	else if (!ft_strncmp(str, "--bench", 8))
		cfg->bench = 1;
	else
		return (0);
	return (1);
}

t_stack	*parse_args(int argc, char **argv, t_config *cfg)
{
	t_stack	*a;
	int		i;

	a = NULL;
	cfg->strategy = ADAPTIVE;
	cfg->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (!set_flag(argv[i], cfg))
			handle_words(&a, argv[i]);
		i++;
	}
	return (a);
}
