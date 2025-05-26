
from sympy import *
from IPython.display import display, Latex

def error_prop_corr(f, x,  V):
    """
    f: function f = f(x[0], x[1], ...)
    x: list of variables
    V: covariance matrix (python 2d list)
    """
    sum = S(0) # empty sympy expression
    for i in range(len(x)):
        for j in range(len(x)):
            sum += diff(f, x[i]) * diff(f, x[j]) * V[i][j]
    return sqrt(simplify(sum))

x, y, sigma_x, sigma_y, n = symbols('x, y, sigma_x, sigma_y, n', positive=True)
rho = Symbol("rho", real=True)

# covariance matrix
C = [[sigma_x**2, rho * sigma_x * sigma_y], [rho * sigma_x * sigma_y, sigma_y**2]]

z = x + y
vars = [x, y]
sigma_z = error_prop_corr(z, vars, C)
print(sigma_z)