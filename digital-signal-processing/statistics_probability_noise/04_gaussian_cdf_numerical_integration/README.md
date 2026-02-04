# Gaussian Dağılımı için CDF Hesaplama

## Objective and Assignment Description

CDF of a Gaussian Distribution using Trapezoidal Integration from PDF for a Single Value  
(Gauss CDF Trapezoidal Hesaplama)

Bu proje, bir Gaussian (Normal) dağılımının Kümülatif Dağılım Fonksiyonu (CDF) değerinin,
Olasılık Yoğunluk Fonksiyonu (PDF) üzerinden trapez yöntemi kullanılarak sayısal olarak
nasıl hesaplanabileceğini göstermektedir.

---

## Overview

Gaussian dağılımı, doğada ve mühendislikte karşılaşılan rastgele değişimlerin büyük bir
kısmını modellemek için kullanılan temel olasılık dağılımlarından biridir. Çok sayıda
küçük ve bağımsız rastgele etkinin toplamı, Merkezi Limit Teoremi gereği Gaussian
dağılımına yaklaşır. Ölçüm hataları, sensör gürültüsü, termal gürültü ve
sayısallaştırma hataları gibi birçok fiziksel süreç bu yapıya sahiptir.

Bu nedenle Gaussian dağılımı, sayısal işaret işleme ve istatistik alanlarında
gerçek dünya sinyallerini başarıyla temsil eden referans bir dağılım olarak
sıklıkla kullanılmaktadır.

---

## Code Implementation

Bilgisayarlar integral işlemlerini analitik olarak çözmez; integral değerlerini
belirli bir hata payı dahilinde sayısal olarak yaklaşıklar. Sayısal integrasyonda
amaç en karmaşık algoritmayı seçmek değil, eldeki problem için uygun ve kontrollü
bir yöntemi tercih etmektir.

Bu projede, Gaussian dağılımının PDF fonksiyonundan CDF elde etmek amacıyla
Trapez Entegrasyon Yöntemi kullanılmıştır. Trapez yöntemi, sürekli bir fonksiyonun
belirli aralıklarla örneklenmesi ve bu örnekler arasındaki alanların trapezler
şeklinde hesaplanarak toplanması esasına dayanır. İterasyon sayısı artırıldıkça,
adım genişliği küçülür ve hesaplanan integral değeri teorik sonuca daha fazla
yaklaşır.

Bu ödev, düşük seviyeli sayısal hesaplamalar üzerinde tam kontrol sağlamak amacıyla
C programlama dili kullanılarak gerçekleştirilmiştir. PDF hesaplama, trapez
entegrasyonu ve CDF hesaplama işlemleri ayrı fonksiyonlar halinde modüler bir
yapıda uygulanmıştır.

---

## Kullanılan Yöntem

### Gaussian PDF

Gaussian dağılımının olasılık yoğunluk fonksiyonu şu şekilde tanımlanır:

$$
PDF(x) = \frac{1}{\sigma \sqrt{2\pi}}
\exp\left(-\frac{(x-\mu)^2}{2\sigma^2}\right)
$$

Bu fonksiyon C dili kullanılarak manuel olarak uygulanmıştır.

### Sayısal İntegral (Trapez Yöntemi)

CDF değeri, PDF fonksiyonunun trapez yöntemi ile sayısal integrali alınarak
hesaplanmaktadır:

$$
\int_{a}^{b} f(x)\,dx \approx
\sum_{i=0}^{N-1}
\frac{f(x_i) + f(x_{i+1})}{2} \cdot \Delta x
$$

İntegral aralığı \(N\) adet alt aralığa bölünmekte ve her adımda trapez alanları
hesaplanarak toplam integrale eklenmektedir.

### Sonlu İntegral Sınırları

Sonsuz integral sınırları yerine aşağıdaki aralık kullanılmıştır:

$$
[\mu - 6\sigma,\; \mu + 6\sigma]
$$

Bu aralık Gaussian dağılımının olasılık kütlesinin neredeyse tamamını kapsar.
Eğer \(X < \mu - 6\sigma\) ise CDF değeri 0,
\(X > \mu + 6\sigma\) ise CDF değeri 1 olarak kabul edilir.

---

## Gözlemler

İterasyon sayısının artırılması, trapez yönteminde kullanılan adım genişliğini
küçülttüğü için CDF hesabının doğruluğunu artırmaktadır. ±6σ sınırlandırması,
sonsuz integralin sayısal olarak uygulanabilir ve yeterince hassas bir yaklaşımını
sunmaktadır. Uygulama boyunca herhangi bir hazır istatistik veya olasılık
kütüphanesi kullanılmamıştır.

---

## Pseudo Kod

Girdi: ortalama, standart_sapma, X  
İsteğe bağlı: iterasyon_sayısı  

alt_sinir = ortalama - 6 × standart_sapma  
ust_sinir = ortalama + 6 × standart_sapma  

Eğer X ≤ alt_sinir → CDF = 0  
Eğer X ≥ ust_sinir → CDF = 1  

adim = (X - alt_sinir) / iterasyon_sayısı  
toplam = 0  

Her adım için:  
- PDF değerlerini hesapla  
- Trapez alanını bul  
- Toplam integrale ekle  

Çıktı: CDF(X)
