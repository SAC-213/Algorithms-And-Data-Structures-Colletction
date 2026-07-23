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
    long long **A = malloc(sizeof(long long) * (n + 1));
    long long **B = malloc(sizeof(long long) * (n + 1));
    long long **C = malloc(sizeof(long long) * (n + 1));
    for (int l = 0; l < n + 1; l++)
    {
        A[l] = malloc(sizeof(long long) * (n + 1));
    }
    for (int l = 0; l < n + 1; l++)
    {
        B[l] = malloc(sizeof(long long) * (n + 1));
    }
    for (int l = 0; l < n + 1; l++)
    {
        C[l] = malloc(sizeof(long long) * (n + 1));
    }
    long long i;
    long long j;
    long long k;

    asig++;
    for (i = 1; i <= n; i++)
    {
        asig++;
        for (j = 1; j <= n; j++)
        {
            asig++;
            C[i][j] = 0;
            asig++;
            for (k = 1; k <= n; k++)
            {
                asig++;
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
                arit += 3;
                asig++;
                cond++;
            }
            arit++;
            asig++;
            cond++;
        }
        arit++;
        asig++;
        cond++;
    }
    for (int l = 0; l < n + 1; l++)
    {
        free(A[l]);
        free(B[l]);
        free(C[l]);
    }
    free(A);
    free(B);
    free(C);
}

long long funcion(long long n)
{
    long long p = 0;
    if (n<0)
        return 1;
    p = (4 * n) + (5 * n * n) + (6 * n * n * n) + 1;
    return p;
}