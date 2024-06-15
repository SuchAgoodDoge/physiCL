# Open CL Enhanced Physics Engine

## Verlet Integrator
A damped harmonic system has an equation of motion as such

$$ m \frac{d^2x(t)}{dt^2} + b \frac{dx(t)}{dt} + kx(t) = F(t). $$


I did a project once that showed that a Velet integrator beats the Euler and Euler Cromer integrators as it has both $\mathcal{O}(x^4)$ error and is symplectic.

To derive the Verlet method, we begin with the centred derivative.

$$ \frac{dx}{dt} = \lim_{h \to 0} \frac{x(t+h)-x(t-h)}{2h}. $$

If you taylor expand this about $x(t+h)$ and $x(t-h)$, and add an external force, we get:

$$ x_{i+1} = Ax_i + Bx_{i-1}  +  CF_i $$

$$ v_i = \frac{x_{i+1}-x_{i-1}}{2h} $$

$$ A = 2\frac{(2m-kh^2)}{D}, \quad B = \frac{bh-2m}{D}, \quad C=\frac{2h^2}{D}, \quad D=2m+bh. $$

Verlets method is not self starting, we need more than just $x_0$, $v_0$. To get $x_1$ and $v_1$, we use the Euler-Cromer method as it also has quartic error.

## Euler Cromer
The Euler-Cromer method is a Symplectic Integrator (it is energy preserving). For $b=0$, it works as follows;

$$ x_{i+1} = x_i + hv_{i+1}, $$

$$ v_{i+1} = v_i - \frac{hk}{m} x_i. $$

However, we should add in a damping term and an external Force term, so correct $v_{i+1}$ to

$$ v_{i+1} = v_i - \frac{hk}{m} x_i - \frac{hb}{m}v_i + \frac{hF_i}{m}. $$
