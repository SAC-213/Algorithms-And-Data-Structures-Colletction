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

// Caso donde el if no se ejecuta
void algoritmos(long long n)
{
    long long a;
    long long b;
    long long l = (a < b) ? a : b;
    cond++;
    asig++;
    long long r = 1;
    asig++;
    long long i;
    asig++;
    for (i = 2; i <= l; i++)
    {
        cond++;
        cond++;
        cond++;
        arit += 2;
        if (a % i == 0 && b % i == 0)
        {
            printf("entra al if\n");
            r = i;
            asig++;
        }
        arit++;
        asig++;
        cond++;
    }
}

long long funcion(long long n)
{
    long long p = 0;
    p = (8 * (n - 1)) + 4;
    return p;
}