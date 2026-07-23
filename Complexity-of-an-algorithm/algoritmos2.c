#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long asig = 0, arit = 0, cond = 0;

void algoritmos(long long n);
long long funcion(long long n);

int main(int argc, char const *argv[])
{
    long long n = atoll(argv[1]);
    algoritmos(n);
    printf("%lld,%lld,%lld,%lld,%lld,%lld\n", n, asig, arit, cond, asig + arit + cond, funcion(n));
    return 0;
}

void algoritmos(long long n)
{
    long long *A = malloc(sizeof(long long) * (n + 1));
    long long polinomio = 0;
    asig++;
    long long z = 0;

    asig++;
    for (int i = 0; i <= n; i++)
    {
        polinomio = polinomio * z + A[n - i];
        asig += 2;
        arit += 4;
        cond++;
    }
    free(A);
}

long long funcion(long long n)
{
    long long p = 0;
    p = (7 * (n + 1)) + 2;
    return p;
}