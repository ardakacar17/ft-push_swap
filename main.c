/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:48:00 by akacar            #+#    #+#             */
/*   Updated: 2026/10/18 20:27:46 by zguney           ###   ########.fr       */
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
	if (!ps.a)
		return (0);
	ps.size = stack_size(ps.a);
	ps.disorder = compute_disorder(ps.a);
	if (!is_sorted(ps.a))
	{
		assign_index(ps.a);
		run_strategy(&ps);
	}
	print_bench(&ps);
	stack_free(&ps.a);
	stack_free(&ps.b);
	return (0);
}
