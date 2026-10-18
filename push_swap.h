/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 18:54:34 by akacar            #+#    #+#             */
/*   Updated: 2026/10/18 12:05:45 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef struct s_ps
{
	t_stack		*a;
	t_stack		*b;
	int			size;
	t_config	cfg;
	long		counts[OP_COUNT];
	double disorder;
}	t_ps;

t_stack		*new_node(int value);
void		stack_add_back(t_stack **stack, t_stack *new);
int			is_valid_int(char *str);
void		stack_free(t_stack **stack);
t_stack		*parse_args(int argc, char **argv, t_config *cfg);
int			swap(t_stack **s);
int			push(t_stack **src, t_stack **dst);
int			rotate(t_stack **s);
int			rev_rotate(t_stack **s);
const char	*op_name(t_op op);
void		do_op(t_ps *ps, t_op op);
int			is_sorted(t_stack *a);
int			stack_size(t_stack *s);
double		compute_disorder(t_stack *a);
void		assign_index(t_stack *a);
int			find_pos(t_stack *s, int index);
void		rot_a_to(t_ps *ps, int pos);
void		rot_b_to(t_ps *ps, int pos);
void		sort_simple(t_ps *ps);
void		sort_medium(t_ps *ps);
void		sort_complex(t_ps *ps);
void		run_strategy(t_ps *ps);


#endif
