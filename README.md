# fastest-primes

Count the primes <= N (1 <= N <= 5,000,000). Reads N on stdin, prints the count on stdout.

## Program
`primes.c` — optimized odd-only Sieve of Eratosthenes (byte array), C, stdlib only.
A prebuilt x86-64 binary `primes` is included (built with `gcc -O3`).

## Run command
```
./run.sh
```
(`run.sh` executes the prebuilt `./primes`, or compiles it with `gcc -O3` first if the binary is absent.)

## Correctness (public samples)
| N | count |
|---|---|
| 10 | 4 |
| 100 | 25 |
| 1000 | 168 |
| 100000 | 9592 |
| 1000000 | 78498 |
| 5000000 | 348513 |

All verified locally. Edge cases: N=1 -> 0, N=2 -> 1.

## Speed (local, N=5,000,000, wall clock incl. process spawn)
min ~0.009 s, median ~0.017 s (20 runs). Sieve itself ~0.007 s user time.
