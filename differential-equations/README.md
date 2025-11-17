# Differential Equations

A differential equation is an equation involving an unknown function and its derivatives.

Understanding differential equations is essential for analyzing and interpreting many types of problems such as fluid motion, electric current in circuits, heat transfer in solid objects, detection of seismic waves, population growth or decline, and many similar phenomena.

Differential equations represent physical models and are referred to as mathematical models. The main purpose of solving differential equations is to gain insight into the mathematical model that expresses a physical process. Understanding a complex and natural process often involves reducing it to its simplest form. Hence, to comprehend the equations that describe these models and their solutions, we must first be familiar with their simpler versions.

An ordinary differential equation (ODE) is one in which the unknown function depends on only one independent variable. If the unknown function depends on two or more independent variables, the differential equation is called a partial differential equation (PDE).

The order of a differential equation is the order of the highest derivative appearing in the equation.

---

# Notation

The expressions `y'`, `y''`, `y'''`, `y^(4)`, …, `y^(n)` are often used to represent, respectively, 
the first, second, third, fourth, …, nth derivatives of `y` with respect to the independent variable 
under consideration. 

Thus, `y''` represents `d^2y/dx^2` if the independent variable is `x`, but `d^2y/dp^2` if the independent 
variable is `p`. 

Parentheses in `y^(n)` are used to distinguish it from the nth power `y^n`.  

If the independent variable is time, usually denoted by `t`, primes are often replaced by dots.  
Thus, `ẏ`, `ÿ`, and `y⃛` represent `dy/dt`, `d^2y/dt^2`, and `d^3y/dt^3`, respectively.

---

# History of Differential Equations

The study of differential equations began in the seventeenth century with Isaac Newton and Gottfried Wilhelm Leibniz. Newton classified first-order equations and developed series methods for solutions, while Leibniz introduced the derivative and integral notation and the method of separation of variables.

The Bernoulli family expanded the field: Jakob and Johann contributed new methods and solved important problems such as the brachistochrone, while Daniel Bernoulli applied partial differential equations to fluid mechanics.

Leonhard Euler made fundamental contributions, including integrating factors, general solutions for linear equations with constant coefficients, and numerical methods. Joseph-Louis Lagrange advanced the theory with the variation of parameters method and showed how higher-order solutions are combinations of independent solutions. Pierre-Simon Laplace introduced equations central to mathematical physics and the Laplace transform.

In the nineteenth century, existence and uniqueness theorems were established, and partial differential equations became central to physics. In the twentieth century, numerical methods gained importance, and with the rise of computers, nonlinear systems could be studied more effectively. Modern approaches also include geometric and topological perspectives to understand the qualitative behavior of solutions.

## In Short

Differential equations began with Newton and Leibniz, were developed by the Bernoulli family, Euler, Lagrange, and Laplace, enriched in the nineteenth and twentieth centuries with theoretical and numerical methods, and in the modern era have reached far wider applications thanks to computers.

# Diferansiyel Denklemlerde Temel Kavramlar

## 1. Mertebe (Order)

Bir diferansiyel denklemdeki **en yüksek türevin derecesi** mertebedir.

**Örnekler:**

* ( y'' + 3y' - 2y = 0 ) → **2. mertebe**
* ( y^{(4)} - x y' = \sin x ) → **4. mertebe**
* ( (dy/dx)^3 + y = 0 ) → **1. mertebe**

---

## 2. Derece (Degree)

Denklem **polinom biçimindeyse**, en yüksek türevin **kuvveti** derecedir.

**Önemli:**

* Türevin içinde kök, log, trigonometrik fonksiyon varsa **derece tanımsızdır**.

**Örnekler:**

* ( (y'')^2 + y = x ) → **2. derece**
* ( y' + xy = 0 ) → **1. derece**
* ( dy/dx + \sqrt{y''} = 0 ) → **derece tanımsız**

---

## 3. Lineer Diferansiyel Denklem

Genel form:

[
a_n(x) y^{(n)} + a_{n-1}(x) y^{(n-1)} + \dots + a_1(x) y' + a_0(x) y = g(x)
]

### Lineerlik koşulları:

* y ve türevleri **birinci kuvvette** bulunmalı
* y ve türevlerin çarpımı olmamalı (örn. ( y y' ) yasak)
* Türevler log, sin, kare kök içinde olmamalı (örn. ( (y')^2 ), ( \sin(y) ) yasak)

**Lineer örnek:** ( y'' + 3y' + 2y = e^x )

**Lineer olmayan örnek:** ( (y')^2 + y = 0 )

---

## 4. Lineer – Homojen / Homojen Olmayan

Lineer denklem:

[
a_n y^{(n)} + \dots + a_0 y = g(x)
]

### Homojen:

[ g(x) = 0 ]

Örnek: ( y'' - 5y' + 6y = 0 )

### Homojen olmayan:

[ g(x) \neq 0 ]

Örnek: ( y'' - 5y' + 6y = e^{2x} )

---

## 5. Ayrılabilir Denklem (Separable)

[
\frac{dy}{dx} = f(x) g(y)
]

x terimleri bir tarafa, y terimleri bir tarafa alınır:

[
\frac{1}{g(y)} dy = f(x) dx
]

Örnek: ( dy/dx = xy^2 )

---

## 6. Exact (Tam) Denklem

Form:
[
M(x,y) + N(x,y) y' = 0
]

Exactlık şartı:
[
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
]

Bu sağlanıyorsa denklem **tam**dır ve bir potansiyel fonksiyon ( \Phi(x,y) ) bulunur.

---

## 7. Integrating Factor (İntegrasyon Faktörü)

1. mertebe lineer denklem:
   [
   y' + P(x) y = Q(x)
   ]

Integrating factor:
[
\mu(x) = e^{\int P(x) dx}
]

---

## 8. Homojen ODE (Homogeneous in ODE Sense)

[
\frac{dy}{dx} = F\left( \frac{y}{x} \right)
]

Dönüşüm:
[
y = ux, \quad y' = u + x u'
]

Denklem ayrılabilir hale dönüşür.

---

## 9. Bernoulli Denklemi

[
y' + P(x) y = Q(x) y^n
]

Dönüşüm:
[
v = y^{1-n}
]

Denklem lineer hale gelir.

---

## 10. Clairaut Denklemi

[
y = x y' + f(y')
]

Genel çözüm → doğru ailesi
Özel çözüm → zarf eğrisi

---

## 11. Riccati Denklemi

[
y' = a(x) y^2 + b(x) y + c(x)
]

---

## 12. ODE – PDE

### ODE (Ordinary Differential Equation):

Tek bağımsız değişkene bağlı.

### PDE (Partial Differential Equation):

Birden çok bağımsız değişkene bağlı.

---

## 13. Başlangıç ve Sınır Şartları

### Initial Value Problem (IVP):

[ y(x_0) = y_0, \quad y'(x_0) = y_1 ]

### Boundary Value Problem (BVP):

[ y(a) = A, \quad y(b) = B ]

---

## 14. Genel ve Özel Çözüm

**Genel çözüm:** Sabit içerir (C, C₁, C₂ …)

**Özel çözüm:** Başlangıç koşulları verilerek sabitler belirlenir.

---

## 15. Mertebe Düşürme – Substitution Teknikleri

* ( v = y' )
* ( y = ux )
* ( v = y/x )

---

## 16. 2. Mertebe Lineer Denklem

[
a_2(x) y'' + a_1(x) y' + a_0(x) y = g(x)
]

---

## 17. 2. Mertebe Lineer Homojen Denklem

[
a_2(x) y'' + a_1(x) y' + a_0(x) y = 0
]

Genel çözüm:
[
y = C_1 y_1(x) + C_2 y_2(x)
]

---

## 18. 2. Mertebe Sabit Katsayılı Lineer Homojen Denklem

[
ay'' + by' + cy = 0
]

Karakteristik denklem:
[
ar^2 + br + c = 0
]

### Kök tiplerine göre çözümler:

* **Gerçek ve farklı kökler:** ( y = C_1 e^{r_1 x} + C_2 e^{r_2 x} )
* **Çakışık kök:** ( y = (C_1 + C_2 x)e^{r x} )
* **Karmaşık kökler:** ( y = e^{\alpha x}(C_1 \cos \beta x + C_2 \sin \beta x) )

