#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long algoritmos(long long n);
double funcion(long long n);

int main(int argc, char const *argv[])
{
    long long n = atoll(argv[1]);
    printf("inf,inf,%.2f\n");
    return 0;
}

long long algoritmos(long long n)
{
    long long p = 0;
    long long i = n;
    while (i >= 0)
    {
        for (long long j = n; i < j; j /= 2)
        {
            printf("Algoritmos");
            p++;
        }
    }

    return p;
}