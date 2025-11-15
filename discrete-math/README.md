# Sayfa 1

## ⭐ Grafın Temel Özellikleri

- Grafın tüm düğümleri birbiri ile ilişkili ise buna **tam graf** denir.
- Grafın dereceler toplamı çift ise çizilebilir.
- Grafın kenar sayısı, düğüm dereceleri toplamının yarısıdır:

e=21​∑si

∑s
i = Düğüm derecelerinin toplamıdır
---

## ⭐ Ağaç (Tree) Özelliği

Ağaç için:

\[
d = k + 1
\]

- 1 düğüm → 0 kenar  
- 2 düğüm → 1 kenar  

---

## ⭐ Grafların İfade Ediliş Biçimleri

- İlişki matrisi  
- Komşuluk matrisi  
- Liste yapısı  
- Macar kuramı ile sıkıştırılmış model graf

---

## ⭐ Euler Teoremi

Maksimum bölge sayısının belirlenmesi için:

\[
b = e - v + 2
\]

- Euler → kenar  
- Hamilton → düğüm  

---

## ⭐ Hamilton Doğru Sayısı

n düğümden oluşan tam graflarda:

\[
(n-1)!
\]

---

## ⭐ Self-Binary Fonksiyon Sayısı

\[
2^{2^n}
\]

---

## ⭐ Açılım Algoritmaları

1. Kruskal  
2. Prim  
3. Boruvka (Sollin)  
4. Tersine silme  

---

## ⭐ Ek Not

- Döngü içermeyen graflara **ağaç** denir.
- Eğer grafın tüm düğümleri grafin peşinde ifade edilebiliyorsa buna **açılım ağacı** denir.

# Sayfa 2

## ⭐ Açılım Ağaçlarının Sayısının Hesaplanması

Açılım ağaçlarının toplam sayısı farklı mantıklarla değerlendirilebilir.

---

## ⭐ P, PN, NPN Sınıfları

\[
P = n!
\]

\[
PN = 2^n \cdot n!
\]

\[
NPN = n^2
\]

---

## ⭐ Hamilton Doğru Sayısı

n düğüm → 

\[
(n-1)!
\]

---

## ⭐ Boolean Denklem Notları

\[
\bar{x_1} \lor x_2 = \bar{x_1} \lor x_2
\]

\[
\bar{x_1} \lor \bar{x_2} = \bar{x_1} \lor x_2
\]

\[
\bar{x_2} \lor x_1 = x_1 \rightarrow x_2
\]

\[
\bar{a} = a \rightarrow 0
\]

---

## ⭐ n Değişkenli Fonksiyonların Özellikleri

- n değişkenli fonksiyonların **\(2^n\)** durumu vardır.
- Böyle fonksiyonların toplam sayısı:

\[
2^{2^n}
\]

- \(2^n \cdot n!\) → bir fonksiyon üzerinde yapılabilecek işlem sayısı
- \(n!/i\) → yer değiştirme analizidir.

---

## ⭐ Ek Mantık Notu

\[
Q_1 = \left( \frac{1!}{2} \right) 2^{n-1}
\]

---

## ⭐ Graf Türleri

- Yönlü  
- Yönsüz  
- Karışık (mixed)

---

## ⭐ Ek Özellikler

- Düğüm dereceleri toplamı **tek ise graf çizilemez.**
- n düğümlü bir graf için derece **(n-1)**'den büyük olamaz.

# Sayfa 3

## ⭐ Grafın Kenar – Düğüm İlişkileri

\[
d = \text{düğüm sayısı}
\]

\[
e = \text{kenar sayısı}
\]

Ağaç için:

\[
d = e + 1
\]

Genel olarak:

\[
e = \frac{1}{2}\sum s_i
\]

---

## ⭐ Düzlemsel (Planar) Graf

Kenarlar birbirini kesmiyorsa grafa **düzlemsel graf** denir.

---

## ⭐ Graf Bir Matristir

\[
G = \{ (v_i, v_j), (E,P) \}
\]

---

## ⭐ Tam Graf Özelliği

Grafın tüm düğümleri birbiri ile ilişkili ise buna **tam graf** denir.

Tam graf için karşılaştırma sayısı:

\[
\frac{n(n-1)}{2}
\]

---

## ⭐ Etiketli Grafların Sayısı

\[
G = 2^{\binom{n}{2}}
\]

---

# Euler – Hamilton Notları

## ⭐ Euler

- Her kenardan bir kez geçilir → **Euler yolu**
- Euler döngüsü için tüm düğümlerin dereceleri **çift** olmalıdır.
- Eğer yalnızca 2 tek dereceli düğüm varsa → Euler yolu vardır.
- 2’den fazla tek dereceli düğüm varsa → Euler döngüsü **yoktur**.

---

## ⭐ Hamilton

Her düğümden bir kere geçilir → Hamilton yolu/döngüsü.

# Sayfa 4

## Ri + Rj → İki doğrunun toplamı

---

## ⭐ Grafın n adet düğümü ve S adet kenarına göre toplam doğrultu:

\[
\sigma(G_n) = n - m + 1
\]

---

## ⭐ Taban doğruların (basit doğruların) elde edilme şekli

**İzlen sayısı:**

\[
x = 2^{\sigma(G)} - 1
\]

---

## ⭐ Toplam doğru sayısı

\[
C(G) = \sigma(G) + x
\]

---

Doğru sayısı = doğruluk tablosu satır sayısı.

Grafın açılım operatörü doğrultuların merkezine göre belirlenir.

---

# Minimum açılım algoritmalarının belirlenmesi

- Kruskal  
- Prim  
- Boruvka  
- Tersine çıkarma

---

## Kruskal Örneği

(Şekildeki grafa göre örnek işlem)

Seçilen kenarlar:

1. BC  
2. EF  
3. AD  
4. ~~CD~~ (alınmıyor)  
5. DF  
6. AF  

→ **15 değerli bir ağaç oluştu.**

---

### Kruskal karmaşıklığı:

\[
O(k \log k)
\]


