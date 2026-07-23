import numpy as np
import matplotlib.pyplot as plt

def f1(n):
    p = (7 * n) + 4
    return p

n_range = np.linspace(2, 500000, 1000)

y1 = f1(n_range)

plt.figure(figsize=(12, 7))

plt.plot(n_range, y1, label='T(n)')

plt.title(' Comprobación (n hasta 500,000)')
plt.xlabel('Valor de n')
plt.ylabel('Tiempo')
plt.yscale('log')
plt.grid(True, which="both", ls="-", alpha=0.3)
plt.legend()

plt.show()