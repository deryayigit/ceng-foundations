# Differential Equations

A differential equation is an equation involving an unknown function and its derivatives.

Understanding differential equations is essential for analyzing many types of problems such as fluid motion, electric current in circuits, heat transfer in solid objects, detection of seismic waves, population growth or decline, and many similar natural phenomena.

Differential equations represent physical processes and are therefore considered mathematical models. The main purpose of solving differential equations is to gain insight into these models. Understanding a complex natural process often requires reducing it to its simplest form. Hence, to comprehend the equations that describe these models and their solutions, one must first be familiar with simpler cases.

An ordinary differential equation (ODE) involves a function with only one independent variable. If the unknown function depends on two or more independent variables, the equation is called a partial differential equation (PDE). The order of a differential equation is the order of the highest derivative appearing in the equation.

---

# Notation

The expressions `y'`, `y''`, `y'''`, `y^(4)`, …, `y^(n)` represent the first, second, third, fourth, …, nth derivatives of `y` with respect to the independent variable. Thus, `y''` means `d²y/dx²` when the independent variable is `x`, but `d²y/dp²` when the variable is `p`. Parentheses in `y^(n)` distinguish it from the nth power `y^n`. If the independent variable is time `t`, primes are replaced by dots. Thus, `ẏ`, `ÿ`, and `y⃛` represent `dy/dt`, `d²y/dt²`, and `d³y/dt³`.

---

# History of Differential Equations

The study of differential equations began in the seventeenth century with Isaac Newton and Gottfried Wilhelm Leibniz. Newton classified first-order equations and developed series solution methods, while Leibniz introduced derivative and integral notation and the method of separation of variables. The Bernoulli family expanded the field through new methods and applications to fluid mechanics. Leonhard Euler made fundamental contributions such as integrating factors, general solutions for linear equations, and numerical methods. Joseph-Louis Lagrange improved the theoretical basis with the variation of parameters method and the structure of higher-order solutions. Pierre-Simon Laplace introduced equations central to mathematical physics and the Laplace transform. In the nineteenth century existence and uniqueness theorems were established, and in the twentieth century numerical analysis and computers increased the ability to study nonlinear systems. Today geometric and topological methods provide deeper insight into the qualitative behavior of solutions.

In short, differential equations grew from Newton and Leibniz, developed by Euler, Bernoulli, Lagrange, and Laplace, formalized in the nineteenth and twentieth centuries, and expanded greatly in the modern era with computational tools.

---

# Diferansiyel Denklemlerde Temel Kavramlar

## 1. Mertebe (Order)

Bir diferansiyel denklemdeki en yüksek türevin derecesi mertebedir.

Örnekler:

\( y'' + 3y' - 2y = 0 \) → 2. mertebe  
\( y^{(4)} - x y' = \sin x \) → 4. mertebe  
\( (dy/dx)^3 + y = 0 \) → 1. mertebe

---

## 2. Derece (Degree)

Denklem polinom biçimindeyse, en yüksek türevin kuvveti derecedir.  
Türevin içinde kök, log veya trigonometrik ifade varsa derece tanımsızdır.

Örnekler:

\( (y'')^2 + y = x \) → 2. derece  
\( y' + xy = 0 \) → 1. derece  
\( dy/dx + \sqrt{y''} = 0 \) → derece tanımsız

---

## 3. Lineer Diferansiyel Denklem

Genel form:

\[
a_n(x) y^{(n)} + a_{n-1}(x) y^{(n-1)} + \dots + a_1(x) y' + a_0(x) y = g(x)
\]

Lineerlik koşulları: y ve türevleri birinci kuvvette olmalı, çarpım şeklinde olmamalı ve türevler logaritma, kök veya trigonometrik fonksiyon içinde bulunmamalıdır.

Lineer örnek: \( y'' + 3y' + 2y = e^x \)  
Lineer olmayan örnek: \( (y')^2 + y = 0 \)

---

## 4. Lineer – Homojen / Homojen Olmayan

\[
a_n y^{(n)} + \dots + a_0 y = g(x)
\]

Homojen denklemde \( g(x) = 0 \).  
Homojen olmayan denklemde \( g(x) \neq 0 \).

---

## 5. Ayrılabilir Denklem (Separable)

\[
\frac{dy}{dx} = f(x) g(y)
\]

Ayrılabilir biçime dönüştürülebilir:

\[
\frac{1}{g(y)} dy = f(x) dx
\]

---

## 6. Exact (Tam) Denklem

Form:

\[
M(x,y) + N(x,y) y' = 0
\]

Exactlık şartı:

\[
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
\]

Bu sağlandığında bir potansiyel fonksiyon \( \Phi(x,y) \) vardır.

---

## 7. Integrating Factor

1. mertebe lineer denklem:

\[
y' + P(x) y = Q(x)
\]

Integrating factor:

\[
\mu(x) = e^{\int P(x) dx}
\]

---

## 8. Homojen ODE (ODE anlamında homogeneous)

\[
\frac{dy}{dx} = F\left( \frac{y}{x} \right)
\]

Dönüşüm:  
\( y = ux \) ve \( y' = u + x u' \).  
Bu dönüşüm sonrası denklem ayrılabilir hale gelir.

---

## 9. Bernoulli Denklemi

\[
y' + P(x) y = Q(x) y^n
\]

Dönüşüm:  
\( v = y^{1-n} \)  
Denklem lineer biçim alır.

---

## 10. Clairaut Denklemi

\[
y = x y' + f(y')
\]

Genel çözüm doğru ailesi, özel çözüm zarf eğrisidir.

---

## 11. Riccati Denklemi

\[
y' = a(x) y^2 + b(x) y + c(x)
\]

---

## 12. ODE – PDE

ODE tek bağımsız değişkene bağlıdır.  
PDE birden fazla bağımsız değişkene bağlıdır.

---

## 13. Başlangıç ve Sınır Şartları

Initial Value Problem (IVP):  
\( y(x_0) = y_0,\; y'(x_0) = y_1 \)

Boundary Value Problem (BVP):  
\( y(a) = A,\; y(b) = B \)

---

## 14. Genel ve Özel Çözüm

Genel çözüm sabit içerir.  
Özel çözüm başlangıç koşulları verildiğinde sabitler belirlenerek elde edilir.

---

## 15. Mertebe Düşürme – Substitution Teknikleri

Kullanılan dönüşümler:  
\( v = y' \), \( y = ux \), \( v = y/x \)

---

## 16. İkinci Mertebe Lineer Denklem

\[
a_2(x) y'' + a_1(x) y' + a_0(x) y = g(x)
\]

---

## 17. İkinci Mertebe Lineer Homojen Denklem

\[
a_2(x) y'' + a_1(x) y' + a_0(x) y = 0
\]

Genel çözüm:  
\( y = C_1 y_1(x) + C_2 y_2(x) \)

---

## 18. İkinci Mertebe Sabit Katsayılı Lineer Homojen Denklem

\[
ay'' + by' + cy = 0
\]

Karakteristik denklem:  
\( ar^2 + br + c = 0 \)

Gerçek ve farklı kökler:  
\( y = C_1 e^{r_1 x} + C_2 e^{r_2 x} \)

Çakışık kök:  
\( y = (C_1 + C_2 x) e^{rx} \)

Karmaşık kökler:  
\( y = e^{\alpha x} \left( C_1 \cos(\beta x) + C_2 \sin(\beta x) \right) \)
