#!/bin/sh
# Run the prime counter. Prefers the prebuilt binary; compiles if needed.
if [ -x ./primes ]; then
  exec ./primes
else
  gcc -O3 -o primes primes.c && exec ./primes
fi
