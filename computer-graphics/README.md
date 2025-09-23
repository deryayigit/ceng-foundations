# 🎨 Bilgisayar Grafikleri  

Bu depo, **bilgisayar grafikleri** konusundaki temel kavramları, ışık modellerini, kesişim testlerini ve donanım destekli uygulamaları içermektedir.  

---

<img width="718" height="449" alt="image" src="https://github.com/user-attachments/assets/c9e69a44-05f3-4a07-9967-a5174c0f2c26" />


## 💡 Işık ve Aydınlatma  

- **Işık Kaynağının Konumu**  
- **Diffuze Bileşen**: Işık kaynağının vuruş açısına göre farklı tonlarda parlama olmasıdır.  
- **Specular Bileşen**: Işık kaynağının cisim üzerindeki parlama etkisidir.  
- **Ambient Bileşen**: Ortam ışığı sayesinde gölgede kalan bölgelerin de aydınlanmasıdır.  

> **Not:** Bakış noktası genellikle *(0,0,0)* alınır.  

---

## 📐 Temel Matematik  

- **Skaler Çarpım (Dot Product)**  
- **Vektörel Çarpım (Cross Product)**  

---

## 🔦 Ray Tracing  

- Görüntü düzlemindeki piksel koordinatlarının hesaplanması:  

\[
GD(X,Y,Z) = \Big(16 \cdot \frac{x}{799} - 8,\ 4.5 - \frac{y \cdot 9}{449},\ 10\Big)
\]  

- **Işın-Üçgen Kesişim Testi**  
- **Işın-Küre Kesişim Testi**  

---

## 🖌️ Boyama Modelleri  

- **Phong Boyama Modeli**  
  - Diffuse Renk Bileşeni  
  - Specular Renk Bileşeni  
  - Ambient Renk Bileşeni  

---

## ⚙️ Donanım ve DirectX  

- **DirectX**: Hızlı donanım uygulamaları yazabilmek için geliştirilmiş donanım destekli yazılım kütüphanelerindendir.  
- **Primitive Topology** (Nokta, çizgi, üçgen tanımları)  
- **Object Space** (Nesnenin kendi koordinat sistemi)  

---

## 🧩 Örnek Uygulamalar  

- Üçgen Çizimi  
- Küp Çizimi  

---

## 📷 Kaynaklar  

- Foley, van Dam, Feiner, Hughes – *Computer Graphics: Principles and Practice*  
- OpenGL & DirectX resmi dökümantasyonları  
- Ders notları  
