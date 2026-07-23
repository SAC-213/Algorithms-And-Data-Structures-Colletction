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
    int anterior = 1;
    asig++;
    int actual = 1;
    asig++;
    int aux = 0;
    while (n > 2)
    {
        aux = anterior + actual;
        asig++;
        arit += 2;
        anterior = aux;
        asig++;
        n = n - 1;
        asig++;
        arit++;
        cond++;
    }
}

long long funcion(long long n)
{
    long long p = 0;
    if (n<2)
    {
        return 0;
    }
    
    p = (7 * (n-2)) + 2;
    return p;
}