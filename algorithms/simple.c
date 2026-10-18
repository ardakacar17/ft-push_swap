/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:54:50 by zguney            #+#    #+#             */
/*   Updated: 2026/10/17 18:22:02 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_simple(t_ps *ps)
{
	int	k;

	k = 0;
	while (k < ps->size && !is_sorted(ps->a))//daha atılacak eleman var ve a hala sıralı değil.
	{
		rot_a_to(ps, find_pos(ps->a, k));//find_pos ile k index’li elemanın yeri bulunur.rot_a_to onu tepeye getirir
		do_op(ps, PB);
		k++;
	}
	while (ps->b)
		do_op(ps, PA);
}

//Fikir şu (selection sort uyarlaması): en küçük elemanı bul, b’ye at. 
//Sonra ikinci en küçüğü bul, b’ye at. Böyle devam et.
// b’ye küçükten büyüğe attığın için b’nin tepesinde en büyük kalır.
// Sonunda hepsini pa ile geri alınca her biri a’nın tepesine geldiği için a artan sırada dizilir.


//selection sort (subjectte örnek olarak veriliyor bu algoritma) Normal dizilerde şöyle çalışır: 
//dizideki en küçüğü bul, başa koy; 
//kalanlardan en küçüğü bul, ikinci sıraya koy; 
//böyle devam et. 
//Biz bunu iki stack’e uyarladık: “başa koy” yerine “b’ye at” diyoruz, 
//çünkü stack’te elemanları rastgele yerlere koyamıyorsun, sadece tepeye ekleyebiliyorsun.
//Subject’in listesinden başka seçenekler de var:
//Insertion sort uyarlaması: Elemanları b’ye atıp, her birini b’de doğru yere yerleştirerek ilerlersin, sonra hepsini geri alırsın.
//Bubble sort uyarlaması: sa ve ra ile ardışık çiftleri karşılaştırıp yer değiştirerek ilerlersin. Basit ama genelde en çok hamle harcayan yöntem.