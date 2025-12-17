import sympy as sp

x, y, u = sp.symbols('x y u')

class HomogeneousODESolver:
    def __init__(self, f_xy):
        self.x = x
        self.y = y
        self.u = u
        self.f_xy = f_xy

    def solve_general(self):
        # Substitute y = u*x
        f_sub = self.f_xy.subs(self.y, self.u * self.x)

        # Separable form and integration
        du_integral = sp.integrate(1 / (f_sub - self.u), self.u)
        dx_integral = sp.integrate(1 / self.x, self.x)

        C = sp.symbols('C')

        # Implicit solution in u
        solution_u = sp.Eq(du_integral, dx_integral + C)

        # Replace u = y/x
        solution_y = solution_u.subs(self.u, self.y / self.x)

        return solution_y

print("Homogeneous ODE Solver")

f_input = input("Enter f(x,y): ")
try:
    f_xy = sp.sympify(f_input)
except sp.SympifyError:
    print("Invalid mathematical expression.")
    exit()

solver = HomogeneousODESolver(f_xy)
implicit_solution = solver.solve_general()

print("\nImplicit solution:")
sp.pprint(implicit_solution)

# Try to get explicit solution
print("\nTrying to solve explicitly for y...")

try:
    explicit_solutions = sp.solve(implicit_solution, y)

    if explicit_solutions:
        print("\nExplicit solution(s):")
        for sol in explicit_solutions:
            sp.pprint(sp.Eq(y, sol))
    else:
        print("Could not isolate y explicitly.")

except Exception:
    print("Explicit solution not possible.")

initial_condition = input("\nDo you have an initial condition? (Y/N): ").upper()

if initial_condition == "Y":
    x0 = float(input("Enter x0: "))
    y0 = float(input("Enter y0: "))

    C = sp.symbols('C')

    eq_for_C = implicit_solution.subs({x: x0, y: y0})
    C_value = sp.solve(eq_for_C, C)[0]

    final_solution = implicit_solution.subs(C, C_value)

    print("\nSolution with initial condition:")
    sp.pprint(final_solution)


