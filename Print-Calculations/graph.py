import numpy as np
import matplotlib.pyplot as plt

def f1(n):
    return np.log2(n - 1)

def f2(n):
    k = np.floor(np.log2(n) - 2)
    p = k * np.ceil(n / 2.0)
    return p

def f3(n):
    n = n.astype(np.float64)
    p = (((n * n) + n) / 2.0) * np.ceil((5 * n) / 2.0)
    return p

def f4_vectorizada(n_arr):
    results = []
    for n_val in n_arr:
        p = 0
        limit = int(np.floor(np.log2((4.0 * n_val) - 1)))
        k = np.arange(limit + 1)
        term = np.floor((5.0 * n_val - 2**k - 1) / 3.0) + 1
        results.append(np.sum(term))
    return np.array(results)

n_range = np.linspace(2, 500000, 1000)

y1 = f1(n_range)
y2 = f2(n_range)
y3 = f3(n_range)
y4 = f4_vectorizada(n_range)

plt.figure(figsize=(12, 7))

plt.plot(n_range, y1, label='f1')
plt.plot(n_range, y2, label='f2')
plt.plot(n_range, y3, label='f3')
plt.plot(n_range, y4, label='f5')

plt.title('Comparación de Funciones (n hasta 500,000)')
plt.xlabel('Valor de n')
plt.ylabel('Impresiones')
plt.yscale('log')
plt.grid(True, which="both", ls="-", alpha=0.3)
plt.legend()

plt.show()