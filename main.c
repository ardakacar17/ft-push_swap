/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 11:48:00 by akacar            #+#    #+#             */
/*   Updated: 2026/10/18 12:07:17 by zguney           ###   ########.fr       */
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
		ps.disorder = compute_disorder(ps.a);
		assign_index(ps.a);
		run_strategy(&ps);
	}
	stack_free(&ps.a);
	stack_free(&ps.b);
	return (0);
}
