#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

bool is_prime(unsigned long long n) {
    if (n < 2) {
        return false;
    } else {
        unsigned long long max = sqrt(n) + 1;
        unsigned long long i;
        for (i = 2; i < max; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main(void) {
    unsigned long long start = 2;
    unsigned long long end = LLONG_MAX;
    unsigned long long i;

    #pragma omp parallel for schedule(static)
    for (i = start; i < end; i++) {
        if (is_prime(i)) {
            #pragma omp critical
            {
                printf("%llu\n", i);
            }
        }
    }
    return 0;
}
