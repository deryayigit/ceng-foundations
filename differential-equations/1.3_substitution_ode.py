import sympy as sp

x = sp.symbols('x')
y = sp.Function('y')(x)

a, b, c = sp.symbols('a b c')
u = sp.symbols('u')

F = sp.Function('F')


# dy/dx = F(ax + by + c)
ode = sp.Derivative(y, x) - F(a*x + b*y + c)


# u = ax + by + c
u_def = a*x + b*y + c


# du/dx = a + b*dy/dx
du_dx = sp.diff(u_def, x)


# dy/dx = (1/b)(du/dx - a)
dy_dx = (du_dx - a) / b


# (1/b)(du/dx - a) = F(u)
substituted_equation = dy_dx - F(u)


# du/dx = a + bF(u)
du_dx_final = a + b*F(u)


# du / (a + bF(u)) = dx
separable_left = 1 / (a + b*F(u))
separable_right = 1


C = sp.symbols('C')

general_solution = sp.Eq(
    sp.integrate(separable_left, u),
    x + C
)


general_solution
