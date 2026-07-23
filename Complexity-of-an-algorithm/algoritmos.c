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
    long long *A = malloc(sizeof(long long) * (n + 2));
    long temp;
    asig++;
    for (long long i = 1; i < n; i++)
    {
        asig++;
        for (long long j = n; j > 1; j /= 2)
        {
            temp = A[j];
            A[j] = A[j + 1];
            A[j + 1] = temp;
            asig += 3;
            arit += 3;
            cond++;
        }
        arit++;
        cond++;
    }
    free(A);
}

long long funcion(long long n)
{
    if (n <= 1)
        return 1;
    long long p = 1 + (3 * (n - 1)) + ((7 * (n - 1)) * (long long)floor(log2(n)));
    return p;
}