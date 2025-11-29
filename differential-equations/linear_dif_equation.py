import math 

def simpson(f, a, b, n=1000): if n % 2 == 1: n += 1 h = (b - a) / n s = f(a) + f(b) 

for i in range(1, n): 
   x = a + i * h 
   if i % 2 == 0: 
       s += 2 * f(x) 
   else: 
       s += 4 * f(x) 
 
return s * h / 3 
 
def make_function(expr): def func(x): return eval(expr, {"x": x, "math": math, **math.dict}) return func 


def solve_linear_ode(x, x0, y0, p_str, q_str): 

p = make_function(p_str) 
q = make_function(q_str) 
 
integral_p = simpson(p, x0, x) 
mu_x = math.exp(integral_p) 
 
def muq(t): 
   return math.exp(simpson(p, x0, t, 300)) * q(t) 
 
integral_muq = simpson(muq, x0, x) 
 
C = y0 

return (integral_muq + C) / mu_x 


x0 = float(input("Başlangıç noktası x0: ")) y0 = float(input("Başlangıç değeri y(x0): ")) x = float(input("Hesaplanacak x: ")) 

p_str = input("p(x) fonksiyonunu girin (ör: 2/x, sin(x), x*2+1 ): ") q_str = input("q(x) fonksiyonunu girin (ör: sin(x), 3x, exp(x) ): ") 

result = solve_linear_ode(x, x0, y0, p_str, q_str) 

print(f"\n❯ y({x}) = {result}\n") 


--------

'''
Second Method

import sympy as sp

# Değişkeni tanımlıyoruz
x = sp.symbols('x')

# Kullanıcıdan p(x) ve q(x) alınır
p_str = input("p(x) fonksiyonunu girin: ")
q_str = input("q(x) fonksiyonunu girin: ")

# String → SymPy fonksiyonuna çeviriyoruz
p = sp.sympify(p_str)
q = sp.sympify(q_str)

# Integrating factor
mu = sp.exp(sp.integrate(p, x))          # μ(x) = e^(∫p dx)

# Genel çözüm
integral_mu_q = sp.integrate(mu * q, x)  # ∫ μ*q dx
C = sp.symbols('C')                       # integrasyon sabiti

y = (integral_mu_q + C) / mu

print("\nGenel çözüm y(x) = ")
print(sp.simplify(y))
'''
