/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:56:08 by zguney            #+#    #+#             */
/*   Updated: 2026/10/18 13:04:56 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	chunk_size(int size)//Pencerenin genişliği.
{
	int	root;//root kareköke yukarı yuvarlanmış değer.

	root = 1;
	while (root * root < size)
		root++;
	return (root * 3 / 2);//Çarpan başlangıç tahmini, ölçerek ayarlayabiliriz
}
//pencere küçükse b çok düzenli olur ve ikinci aşama ucuzlar, 
//ama a’da uygun elemanı bulmak için daha çok ra gerekir.
//Pencere büyükse ra azalır ama b dağınıklaşır.

static void	push_to_b(t_ps *ps, int chunk)//buradaki amacım ilerde hamle sayısını azaltmak için önce kabaca düzenlemek
{
	int	pushed;//şimdiye kadar b’ye atılan eleman sayısı

	pushed = 0;
	while (ps->a)
	{//(indexleri assign_index fonksiyonuyla zaten küçükten büyüğe sabit atamıştık)
		if (ps->a->index <= pushed)//eleman küçük. b nin sonuna at
		{
			do_op(ps, PB);
			do_op(ps, RB);
			pushed++;
		}
		else if (ps->a->index <= pushed + chunk)//orta büyüklükte bir sayı. b nin üstüne at.
		{
			do_op(ps, PB);
			pushed++;
		}
		else//sayı çok büyük a nın dibine at. sonra tekrar önümüze gelecek
			do_op(ps, RA);
	}
}
//push_back_to_a fonksiyonu push_to_b olmasa da sıralayabilir (while (ps->a) ->do_op(ps, PB);). ama daha az hamleyle yapsın diye önce push_to_b de kabaca sıralama yapıyoruz
static void	push_back_to_a(t_ps *ps)
{
	int	target;//en büyük index

	target = ps->size - 1;
	while (ps->b)
	{
		rot_b_to(ps, find_pos(ps->b, target));//find_pos ile hedefin b’deki yerini buluyoruz, rot_b_to kısa yoldan tepeye getiriyor
		do_op(ps, PA);//bulup b nin tepesine attığım düğümü en üstten alıp a ya atıyorum.
		target--;
	}//En büyük en önce girip altta kaldığı için, sonunda a artan sırada oluyor.
	//Hedef ya tepeye yakın ya da dibe yakın bulunduğu için rot_b_to az hamle harcıyor.
}

void	sort_medium(t_ps *ps)
{
	push_to_b(ps, chunk_size(ps->size));
	push_back_to_a(ps);
}

//seçtiğimiz algoritma Chunk-based sorting (README’de ismini “range-based chunk (sliding window)” diye yazmak en doğrusu olur.)
// Klasik chunk yönteminde index’ler k parçaya bölünür (mesela 100 eleman için 0–19, 20–39, ...).
// Önce birinci parçanın hepsi b’ye atılır, sonra ikincisi, böyle devam eder.
//Bizim yazdığımız ise aynı fikrin kayan pencere (range-based) hali: 
//parça sınırları sabit değil, pencere her pb’den sonra bir adım ilerliyor.