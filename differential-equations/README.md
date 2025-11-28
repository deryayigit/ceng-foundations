# Differential Equations

A differential equation is any equation that contains derivatives—either ordinary derivatives or partial derivatives. Differential equations describe how a system changes with respect to a quantity such as time, position, temperature, or pressure, and they express the relationship between a function and its derivatives.

For example, the equation that relates an object's position to its velocity and acceleration is a differential equation.

Differential equations represent physical processes and are therefore considered mathematical models. The main purpose of solving differential equations is to understand the behavior of a physical system through its mathematical model. Understanding complex natural processes often requires reducing them to simpler forms; thus, to comprehend these models and their solutions, one must first become familiar with simpler types of differential equations.

An ordinary differential equation (ODE) is a differential equation in which the unknown function depends on only one independent variable.
A partial differential equation (PDE) is used when the unknown function depends on two or more independent variables.

The order of a differential equation is the order of the highest derivative appearing in the equation. order of a differential equation is the order of the highest derivative appearing in the equation.

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


### In Short

Differential equations began with Newton and Leibniz, were developed by the Bernoulli family, Euler, Lagrange, and Laplace, enriched in the nineteenth and twentieth centuries with theoretical and numerical methods, and in the modern era have reached far wider applications thanks to computers.

---

# 📘 Types of Differential Equations and Equation Solutions  

Bu bölümde diferansiyel denklemlerin türleri ve çözüm yöntemleri özetlenmiştir. Her başlık, ileride eklenecek örnekler ve uygulamalar için temel bir çerçeve sunar.

---

## 1. 🔹 Differential Equations Separable by Variables  
**Ayrılabilir diferansiyel denklemler**,  
\[
\frac{dy}{dx} = f(x)\, g(y)
\]  
şeklinde yazılabilen ve değişkenlerin karşılıklı olarak ayrılabildiği denklemlerdir.  

**Temel çözüm yaklaşımı:**  
- \( y \)-terimli ifadeler sol tarafa,  
- \( x \)-terimli ifadeler sağ tarafa alınır.  
- Her iki taraf ayrı ayrı integre edilir.

---

## 2. 🔹 Homogeneous Differential Equations  
Bir denklem,  
\[
M(x,y)\,dx + N(x,y)\,dy = 0
\]  
şeklinde yazılabilir ve  
\[
M(\lambda x, \lambda y) = \lambda^k M(x,y)
\]  
\[
N(\lambda x, \lambda y) = \lambda^k N(x,y)
\]  
koşulunu sağlıyorsa *homojen* bir diferansiyel denklemdir.  

**Temel çözüm yaklaşımı:**  
- Substitution yapılır:  
\[
y = vx \quad \Rightarrow \quad dy = v\,dx + x\,dv
\]  
- Denklem \( v \) cinsinden ayrılabilir forma dönüştürülür ve çözülür.

---

## 3. 🔹 Substitution Method  
Bazı diferansiyel denklemler belirli bir **dönüşüm/substitution** ile çözülebilir hale gelir.  

Yaygın substitution türleri:  
- \( y = vx \)  (homojen form için)  
- \( v = y/x \)  
- \( v = y^n \)  
- \( u = ax + by \)  
- Lineer olmayan denklemleri lineer ya da ayrılabilir hale getirme amaçlı özel dönüşümler  

**Temel fikir:**  
Denklemi çözülmesi kolay bir forma dönüştürmek.

---

## 4. 🔹 Exact Differential Equations  
Denklem  
\[
M(x,y)\,dx + N(x,y)\,dy = 0
\]  
şeklindeyse ve  
\[
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
\]  
koşulu sağlanıyorsa bu denklem *exact (eksak)* bir diferansiyel denklemdir.  

**Temel çözüm yaklaşımı:**  
1. \( M(x,y) \)’yi \( x \)’e göre integre et → potansiyel fonksiyonun bir kısmı  
2. \( N(x,y) \)’yi \( y \)’ye göre integre ederek eksik terimleri tamamlarsın  
3. Çözüm:  
\[
\Phi(x,y) = C
\]

---

> ✨ *Bu alan ileride örnek çözümler, formüller, C/C++ sembolik çözüm algoritmaları ve test soruları ile genişletilecektir.*



---
## References

[1] C. H. Edwards and D. E. Penney, *Differential Equations and Boundary Value Problems: Computing and Modeling*, 5th ed. Boston, MA: Pearson, 2014.


[2] R. Bronson and G. Costa, *Schaum's Outline of Differential Equations*, 4th ed. New York, NY: McGraw-Hill, 2010. 

[3] https://tutorial.math.lamar.edu/


