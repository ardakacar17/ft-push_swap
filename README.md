*This project has been created as part of the 42 curriculum by zguney, akacar.*

# push_swap

## Açıklama

push_swap'te iki stack (a ve b) ve 11 operasyon (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
rrr) var. Program, argüman olarak verilen tekrarsız tamsayıları a'ya yükler (ilk argüman
en üstte) ve a'yı küçükten büyüğe sıralayan operasyon listesini stdout'a yazar. Amaç
listeyi mümkün olduğunca kısa tutmak.

Programda dört strateji var:

| Bayrak       | Strateji                           | Karmaşıklık |
|--------------|------------------------------------|-------------|
| `--simple`   | Selection sort uyarlaması          | O(n²)       |
| `--medium`   | Kayan pencereli chunk sıralaması   | O(n√n)      |
| `--complex`  | LSD radix sort                     | O(n log n)  |
| `--adaptive` | Disorder'a göre seçer (varsayılan) | -           |

Karmaşıklığı, klasik dizi algoritması gibi değil, **ürettiğimiz operasyon sayısı** olarak
hesapladık.

## Talimatlar

```
make        # libft, ft_printf ve push_swap'i derler
make clean  # .o dosyalarını siler
make fclean # .o dosyalarını ve binary'leri siler
make re     # fclean + all
```

Kullanım:

```
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <tamsayılar>
```

- Sayılar ayrı ayrı ya da tek tırnaklı string olarak verilebilir (`"3 2 1"`). Bayraklar
  herhangi bir yerde olabilir.
- Argüman yoksa veya girdi zaten sıralıysa hiçbir şey yazmaz.
- Hata durumunda (sayı olmayan argüman, `int` dışı değer, tekrar eden sayı, boş string)
  stderr'e `Error` yazıp 1 koduyla çıkar.
- `--bench` verilirse sıralamadan sonra stderr'e rapor yazar: disorder (iki ondalık),
  strateji ve karmaşıklığı, toplam operasyon sayısı ve her operasyonun sayısı.

### Test komutları

`checker_linux` okulun verdiği programdır, repoda yok.

```
./push_swap 2 1 3 6 5 8
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
./push_swap --simple 5 4 3 2 1
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
./push_swap --adaptive 0 one 2 3          # Error
./push_swap --simple 3 2 3                # Error
```

Benchmark ve performans:

```
./push_swap --bench $ARG > /dev/null                      # sadece rapor
./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG

ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')               # 500 için -n 500
./push_swap $ARG | wc -l                                  # operasyon sayısı
./push_swap $ARG | ./checker_linux $ARG                   # OK / KO

for f in --simple --medium --complex --adaptive; do
  echo "$f: $(./push_swap $f $ARG | wc -l)"
done
```

Bellek: `valgrind --leak-check=full ./push_swap $ARG > /dev/null`

## Nasıl çalışıyor?

- **Veri yapısı:** Stack'ler tek yönlü bağlı liste, baş = tepe. `pa`/`pb` sadece başa
  dokunduğu için O(1). Tüm durum (stack'ler, ayarlar, sayaçlar, disorder) tek bir `t_ps`
  struct'ında; global değişken yok.
- **Index:** Sıralamadan önce her sayıya kendinden küçük kaç sayı olduğunu yazıyoruz
  (0..n-1). Algoritmalar bu sıra numaralarıyla çalışıyor, negatif sayılar sorun olmuyor.
- **Tek geçit:** Algoritmalar stack'lere doğrudan dokunmaz, hep `do_op` çağırır. `do_op`
  operasyonu uygular; gerçekten bir şey değiştiyse sayar ve yazdırır. Yapılamayan bir
  operasyon (örneğin tek elemanlı b'de `rb`) yazılmaz. Çıktı ile bench hep tutarlıdır.
- **Disorder:** Sıralamadan önce, `a[i] > a[j]` olan (i < j) çiftlerin tüm çiftlere
  oranı. Sıralıysa 0, ters sıralıysa 1, rastgelede yaklaşık 0.5. Hesabı O(n²) CPU
  süresidir ama operasyon üretmez, modelde sayılmaz.

## Algoritmalar

**Simple, selection sort, O(n²).** Sırayla en küçük elemanı (index 0, 1, 2...) en kısa
döndürmeyle tepeye getirip b'ye atıyoruz. En küçükler önce gittiği için b'nin tepesinde
en büyük kalır; hepsini `pa` ile geri alınca a artan sırada olur. a'da kalan kısım zaten
sıralıysa döngü erken biter. En fazla n tur, her turda en fazla n/2 döndürme ve bir `pb`,
sonda n tane `pa`: toplam en fazla n(n/2 + 2), yani O(n²). Ek bellek O(1).

**Medium, kayan pencere, O(n√n).** Klasik chunk yönteminde aralıklar sabittir; bizde
pencere her `pb`'den sonra kayar. `pushed` kadar eleman b'ye gittiyse ve pencere
genişliği `w` ise, a'nın tepesindeki eleman için:
index ≤ `pushed` ise `pb` + `rb` (küçük, b'nin dibine); index ≤ `pushed + w` ise `pb`
(pencere içinde, b'nin tepesine); değilse `ra` (şimdilik büyük, a'nın dibine).
Sonra en büyükten başlayarak her elemanı b'nin tepesine getirip `pa` yapıyoruz.
Pencere genişliği `⌈√n⌉ · 3/2`; çarpanı denemeyle seçtik (100 sayıda ortalama hamle:
0.5 için 711, 1.0 için 604, **1.5 için 569**, 2.0 için 597, 2.5 için 624).
w ≈ √n iken ilk aşamada toplam döndürme yaklaşık n²/w, ikinci aşamada her eleman en fazla
yaklaşık w döndürme istediği için toplam n·w; ikisi de n√n. Bu sezgisel bir argüman,
ölçümlerimizle uyumlu ama en kötü durum ispatı değil. Ek bellek O(1).

**Complex, LSD radix sort, O(n log n).** Sıra numaralarını en küçük bitten başlayarak bit
bit sıralıyoruz. Her bit için a'nın tüm elemanlarına bakıp bit 1 ise `ra`, 0 ise `pb`
yapıyoruz, sonra b'yi `pa` ile geri alıyoruz. Sıfırlar b'ye sırayla gidip ters çıkıyor,
`pa` ile tekrar ters döndüğü için göreli sıraları korunuyor; radix'in doğruluğu bu
kararlılığa dayanır. ⌈log₂ n⌉ tur var (100 için 7, 500 için 9), her tur en fazla 2n
hamle: toplam en fazla 2n·⌈log₂ n⌉. Maliyet girdi sırasına bağlı değil. Ek bellek O(1).

**Adaptive.** Disorder'a göre seçer:

| Disorder          | Yöntem  |
|-------------------|---------|
| `< 0.2`           | Simple  |
| `0.2 ≤ d < 0.5`   | Medium  |
| `≥ 0.5`           | Complex |

Aralıklar subject'ten geliyor. Gerekçemiz: düzensizlik azken liste sıralıya yakın olduğu
için simple erken bitiyor ve O(n²) kabul edilebilir; orta düzensizlikte pencere yöntemi
radix'ten ucuz çıkıyor; yüksek düzensizlikte (rastgele girdi dahil) girdi sırasından
bağımsız bir üst sınır veren radix'i kullanıyoruz. Her rejimde seçilen yöntem kendi
karmaşıklık sınırını sağlıyor, ek bellek O(1).

Adaptive modda eleman sayısı 5 ve altındaysa 2, 3 ve 5 elemanlı girdiler için hamle
sayısı sabit ve küçük olan özel bir sıralama çalışıyor (en fazla 10 hamle); bench bunu
Simple olarak raporluyor. Radix küçük girdilerde gereksiz çok hamle yaptığı için ekledik.
Strateji bayrakları (`--simple`, `--medium`, `--complex`) her boyutta kendi algoritmasını
çalıştırır.

## Performans

Rastgele girdilerle, `wc -l` ile sayıp checker ile doğrulayarak ölçtük (yaklaşık):

| Strateji                  | 100 sayı        | 500 sayı         |
|---------------------------|-----------------|------------------|
| `--simple`                | en fazla ~1600  | en fazla ~32700  |
| `--medium`                | ortalama ~570   | ortalama ~5100   |
| `--complex`               | ~1084           | ~6784            |
| `--adaptive` (varsayılan) | ortalama ~830   | ortalama ~5800   |

Rastgele girdinin disorder'ı 0.5 civarında olduğu için adaptive yaklaşık yarı yarıya
medium, yarı yarıya complex seçiyor. Subject yüksek disorder için O(n log n) şart
koştuğu için eşikleri kaydırmadık.

## Katkılar

- **zguney:** simple, medium, complex, strategy, küçük girdi sıralaması, en kısa
  döndürme yardımcıları, index konum bulma, bench modu, `main`.
- **akacar:** argüman okuma ve doğrulama, stack yardımcıları, operasyonlar (primitifler
  ve `do_op`), disorder, header.

Tasarım kararlarını birlikte tartışıp birbirimize anlattık; ikimiz de kodun her kısmını
açıklayabiliriz.

## Kaynaklar

- https://en.wikipedia.org/wiki/Radix_sort
- https://en.wikipedia.org/wiki/Selection_sort
- https://en.wikipedia.org/wiki/Big_O_notation
- https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
- 42 Norm ve push_swap subject'i

### Yapay zekâ kullanımı

Yapay zekâ yardımcı olarak kullanıldı; algoritmaları ve ana kodu biz yazdık:

- yazdığımız kodu gözden geçirmek, norm ve subject uyumunu kontrol etmek, readme taslağı, test senaryoları ve ölçüm komutları hazırlamak 
