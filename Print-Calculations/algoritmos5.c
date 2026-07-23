#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long algoritmos(long long n);
double funcion(long long n);

int main(int argc, char const *argv[])
{
    long long n = atoll(argv[1]);
    printf("%lld,%lld,%.2f\n", n, algoritmos(n), funcion(n));
    return 0;
}

long long algoritmos(long long n)
{
    long long p = 0;
    for (long long i = 1; i < 4 * n; i *= 2)
    {
        for (long long j = i; j < 5 * n; j += 3)
        {
            printf("Algoritmos");
            p++;
        }
    }

    return p;
}

double funcion(long long n)
{
    double p = 0;
    double i = floor(log2((4.0 * n) - 1));

    for (long long k = 0; k <= i; k++)
    {
        p += floor((5.0 * n - pow(2, k) - 1) / 3.0) + 1;
    }

    return p;
}