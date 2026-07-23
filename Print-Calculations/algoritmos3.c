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
    for (long long i = 0; i < n * 5; i += 2)
    {
        for (long long j = 0; j < 2 * n; j++)
        {
            for (long long k = j; k < n; k++)
            {
                printf("Algoritmos");
                p++;
            }
        }
    }
    return p;
}

double funcion(long long n)
{
    double p = 0;

    p = (((double)n * n) + n) / 2.0 * ceil(((5 * n) / 2.0));
    return p;
}