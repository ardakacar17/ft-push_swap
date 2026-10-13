/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:48:00 by akacar            #+#    #+#             */
/*   Updated: 2026/10/13 19:55:07 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ft_bzero(&ps, sizeof(t_ps));
	ps.a = parse_args(argc, argv, &ps.cfg);
	ps.size = stack_size(ps.a);
	if (is_sorted(ps.a))
	{
		stack_free(&ps.a);
		stack_free(&ps.b);
		return (0);
	}
	stack_free(&ps.a);
	stack_free(&ps.b);
	return (0);
}
