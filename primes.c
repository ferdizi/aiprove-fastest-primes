// fastest-primes: count primes <= N (1 <= N <= 5,000,000).
// Optimized odd-only Sieve of Eratosthenes, byte array, -O3.
// Reads N on stdin, prints the count on stdout.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    long n;
    if (scanf("%ld", &n) != 1) return 1;
    if (n < 2) { printf("0\n"); return 0; }
    // is_comp[i] = whether (2*i+1) is composite. i in [0, (n+1)/2).
    long m = (n + 1) / 2;
    unsigned char *is_comp = (unsigned char *)calloc((size_t)m, 1);
    if (!is_comp) return 1;
    for (long p = 3; p * p <= n; p += 2) {
        if (!is_comp[p / 2]) {
            long step = p;
            long start = p * p / 2;
            for (long j = start; j < m; j += step) is_comp[j] = 1;
        }
    }
    long count = 1; // prime 2
    for (long i = 1; i < m; i++) if (!is_comp[i]) count++;
    printf("%ld\n", count);
    free(is_comp);
    return 0;
}
