/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:42:27 by zguney            #+#    #+#             */
/*   Updated: 2026/10/18 20:25:01 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//bench modu, program bittikten sonra stderr’e (hata çıktısı kanalı) “ne yaptım” raporu yazdırıyor.
static char	*strategy_name(t_strategy s)
{
	if (s == SIMPLE)
		return ("Simple");
	if (s == MEDIUM)
		return ("Medium");
	if (s == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*complexity_name(t_strategy s)
{
	if (s == SIMPLE)
		return ("O(n²)");
	if (s == MEDIUM)
		return ("O(n√n)");
	return ("O(n log n)");
}

static void	print_disorder(double disorder)//disorder 0 ile 1 arasında küsuratlı bir sayı (mesela 0.4987). Biz bunu 49.87% olarak yazdırmak istiyoruz
{
	long	pct;//“percent”(yüzde) kısaltması. Yüzdeyi 100 ile çarpılmış tamsayı olarak tutacağız.

	pct = (long)(disorder * 10000 + 0.5);//Yüzde için 100 ile çarparız (0.49876 → 49.87), iki ondalık basamak istediğimiz için bir 100 ile daha çarparız. 100 × 100 = 10000.
	//+ 0.5: yuvarlama için.disorder = 0.49876 olsun. Çarpınca 4987.6 çıkar. Bir sonraki adımda küsurat atılacağı için, 0.5 eklemezsek 4987 olur (yani 49.87),
    // halbuki yuvarlayınca 49.88 olmalıdır. 0.5 ekleyince 4988.1 olur, küsurat atılınca 4988 çıkar.
    //(long): küsuratlı sayıyı long a çevirdik yani kalan küsüratrları attık
    ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(pct / 100), 2);//yüzdenin tam kısmını yazıyoruz.
	ft_putchar_fd('.', 2);
	if (pct % 100 < 10)//Diyelim pct = 405 (yani 4.05%). 405 % 100 = 5. Direkt 5 basarsak ekranda 4.5% görünür
		ft_putchar_fd('0', 2);
	ft_putnbr_fd((int)(pct % 100), 2);//Ondalık kısmı basar. Ekranda 49.88
	ft_putstr_fd("%\n", 2);
}

static void	print_counts(t_ps *ps)
{
	long	total;
	int		i;

	total = 0;
	i = 0;
	while (i < OP_COUNT)//i 0'dan OP_COUNT’a (11) kadar gidiyor ve her operasyonun sayacını total’a ekliyor. Yani sa + sb + ss + ... + rrr.
	{//yani toplam kaç operasyon yaptım?=
		total += ps->counts[i];
		i++;
	}
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd((int)total, 2);
	ft_putchar_fd('\n', 2);
	i = 0;
	while (i < OP_COUNT)//her bir operasyonun adı ve kullanım sayısını yazıyorum
	{
		ft_putstr_fd("[bench] ", 2);
		ft_putstr_fd((char *)op_name(i), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd((int)ps->counts[i], 2);//Her operasyonu do_op fonksiyonu sayıyodu ya zatenn
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void	print_bench(t_ps *ps)
{
	if (!ps->cfg.bench)//--bench verilmediyse hiçbir şey yapma.
		return ;
	print_disorder(ps->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(ps->cfg.strategy), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(complexity_name(resolve_strategy(ps)), 2);
	ft_putchar_fd('\n', 2);
	print_counts(ps);
}