import sympy as sp

x, y = sp.symbols('x y')

class SeparableODESolver:
    def __init__(self, A_y, B_x):
        self.x = x
        self.y = y
        self.Ay = A_y
        self.Bx = B_x

    def solve_general(self):
        """
        ∫A(y).dy = ∫B(x).dx + C
        """
        left_integral = sp.integrate(self.Ay, self.y)
        right_integral = sp.integrate(self.Bx, self.x)

        C = sp.symbols('C')
        return sp.Eq(left_integral, right_integral + C)


print("Separable ODE Solver")

Ay_input = input("Enter A(y): ")
Bx_input = input("Enter B(x): ")

# Convert input strings to SymPy expressions
Ay = sp.sympify(Ay_input)
Bx = sp.sympify(Bx_input)

solver = SeparableODESolver(Ay, Bx)
solution = solver.solve_general()

initial_condition = input("Do you have any initial condition? (Y/N): ").upper()

if initial_condition == "Y":
    x0 = float(input("Enter x0: "))
    y0 = float(input("Enter y0: "))

    C = sp.symbols('C')

    # Substitute x0 and y0 into the general solution
    equation_for_C = solution.subs({x: x0, y: y0})

    # Solve for C
    C_value = sp.solve(equation_for_C, C)[0]

    # Replace C in the general solution
    solution = solution.subs(C, C_value)


print("\n Solution:")
sp.pprint(solution)
