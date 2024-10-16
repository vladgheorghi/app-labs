#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100

int main() {

    int a[SIZE], i;
    long sum = 0;
    
    for (i = 0; i < SIZE; i++) {
        a[i] = i;
    }

    #pragma omp parallel for reduction(+:sum) private(i) shared(a)
    for (i = 0; i < SIZE; i++) {
        sum += a[i];
    }

    #pragma omp parallel
    {
        printf("Hello world from thread number %d\n", omp_get_thread_num());
    }

    printf("Total sum = %ld\n", sum);

    return 0;
}