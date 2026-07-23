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
    int *s = malloc(sizeof(long long) * (n));
    int *s2 = malloc(sizeof(long long) * (n));
    int i = 0;
    int j = 0;
    int k = 0;

    asig += 2;
    for (i = n - 1, j = 0; i >= 0; i--, j++)
    {
        asig++;
        s2[j] = s[i];
        arit += 2;
        cond++;
    }
    asig++;
    for (k = 0; k < n; k++)
    {
        s[k] = s2[k];
        arit++;
        asig++;
        cond++;
    }
    free(s);
    free(s2);
}

long long funcion(long long n)
{
    long long p = 0;
    p = (7 * n) + 3;
    return p;
}