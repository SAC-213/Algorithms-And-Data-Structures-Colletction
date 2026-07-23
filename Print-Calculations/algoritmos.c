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
    for (long long i = 10; i < n * 5; i *= 2)
    {
        printf("Algoritmos");
        p++;
    }
    return p;
}

double funcion(long long n)
{
    double p = 0;
    p = log2(n - 1);
    return p;
}