/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:55:42 by zguney            #+#    #+#             */
/*   Updated: 2026/10/18 14:31:15 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_bits(int max)//En büyük index’i yazmak için kaç bit gerektiğini hesaplar.)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)//max >>bits, max'i bits basamak sağa kaydırır
		bits++;
	return (bits);
}

static void	radix_pass(t_ps *ps, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(ps->a);
	while (i < size)
	{
		if (((ps->a->index >> bit) & 1) == 1)//Şu an a'nın tepesindeki sayının, şu an baktığım basamağı 1 mi?
		// yani önce >> ile bakmak istediğin basamağı en sağa getiriyorsun, sonra & 1 ile sadece onu alıyorsun.
			do_op(ps, RA);// a nın sonuna gönder(a 1 olanların yığını)
		else
			do_op(ps, PB);//değilse o olanlar yığını olan b ye gider
		i++;
	}
	while (ps->b)
		do_op(ps, PA);
}

void	sort_complex(t_ps *ps)//Bit sayısı hesaplanır, sonra bit 0'dan bits−1'e kadar her bit için bir tur yapılır.
{
	int	bits;
	int	bit;

	bits = count_bits(ps->size - 1);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(ps, bit);
		bit++;
	}
}

//seçilen algoritma:radix sort. 
//Radix sort sayıları karşılaştırmadan, bit bit sıralar. En az anlamlı bitten (LSD) başlayıp en anlamlıya doğru gider.