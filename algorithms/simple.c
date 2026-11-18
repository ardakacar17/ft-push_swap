/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:54:50 by zguney            #+#    #+#             */
/*   Updated: 2026/11/18 20:00:00 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** sort_two: 2 elemanlı a'yı en fazla 1 hamlede sıralar.
*/
static void	sort_two(t_ps *ps)
{
	if (ps->a->value > ps->a->next->value)
		do_op(ps, SA);
}

/*
** sort_three: 3 elemanlı a'yı en fazla 2 hamlede sıralar.
** stack a = [top, mid, bot] (top = head/peek, bot = tail)
** Hedef: küçükten büyüğe tepede küçük.
**
** 6 permütasyon analizi (index'e göre 0=küçük, 2=büyük):
**   [0,1,2] → zaten sıralı
**   [0,2,1] → rra sa
**   [1,0,2] → sa
**   [1,2,0] → ra ra
**   [2,0,1] → ra
**   [2,1,0] → sa rra
*/
void	sort_three(t_ps *ps)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(ps->a))
		return ;
	top = ps->a->value;
	mid = ps->a->next->value;
	bot = ps->a->next->next->value;
	if (top > mid && top > bot && mid < bot)
	{
		/* [2,0,1]: max tepede, alt ikisi doğru sırada → ra */
		do_op(ps, RA);
	}
	else if (top > mid && top > bot && mid > bot)
	{
		/* [2,1,0]: tamamen ters → sa rra */
		do_op(ps, SA);
		do_op(ps, RRA);
	}
	else if (top < mid && top < bot && mid > bot)
	{
		/* [0,2,1]: min tepede, alt ikisi ters → rra sa */
		do_op(ps, RRA);
		do_op(ps, SA);
	}
	else if (top > mid && top < bot)
	{
		/* [1,0,2]: sadece top ve mid yer değiştirmeli → sa */
		do_op(ps, SA);
	}
	else
	{
		/* [1,2,0]: min altta → ra ra */
		do_op(ps, RA);
		do_op(ps, RA);
	}
}

/*
** sort_five: 5 elemanlı a'yı en fazla 12 hamlede sıralar.
**
** Strateji: en küçük 2 elemanı (index 0 ve 1) b'ye at.
**   - idx0'ı önce push et (b=[idx0]), sonra idx1'i push (b=[idx1, idx0]).
**     (b tepesinde idx1, altta idx0)
**   - Kalan 3 elemanı (idx2, idx3, idx4) sort_three ile sırala.
**     Sonuç: a=[idx2, idx3, idx4] (küçükten büyüğe, tepede küçük)
**   - pa → idx1 a tepesine gelir → a=[idx1, idx2, idx3, idx4] ✓
**   - pa → idx0 a tepesine gelir → a=[idx0, idx1, idx2, idx3, idx4] ✓
**
** Hamle sayısı (en kötü durum):
**   rot_a_to(idx0): max 2 hamle
**   pb: 1
**   rot_a_to(idx1): max 2 hamle
**   pb: 1
**   sort_three: max 2 hamle
**   pa: 1
**   pa: 1
**   Toplam: max 10 hamle ≤ 12 ✓
*/
static void	sort_five(t_ps *ps)
{
	rot_a_to(ps, find_pos(ps->a, 0));
	do_op(ps, PB);
	rot_a_to(ps, find_pos(ps->a, 1));
	do_op(ps, PB);
	sort_three(ps);
	do_op(ps, PA);
	do_op(ps, PA);
}

/*
** sort_simple: genel seçim sıralaması.
** 2, 3, 5 elemanlı diziler için optimize özel fonksiyon çağrılır.
*/
void	sort_simple(t_ps *ps)
{
	int	k;

	if (ps->size <= 1)
		return ;
	if (ps->size == 2)
		return (sort_two(ps));
	if (ps->size == 3)
		return (sort_three(ps));
	if (ps->size == 5)
		return (sort_five(ps));
	k = 0;
	while (k < ps->size && !is_sorted(ps->a))
	{
		rot_a_to(ps, find_pos(ps->a, k));
		do_op(ps, PB);
		k++;
	}
	while (ps->b)
		do_op(ps, PA);
}