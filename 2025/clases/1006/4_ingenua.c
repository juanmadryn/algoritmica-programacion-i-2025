#include <stdio.h>

#define MAXN 100
long long memo[MAXN];

long long fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main(void) {
    for (int i = 0; i < MAXN; i++) 
        memo[i] = -1;
    int n = 50;
    printf("Fib(%d) = %lld\n", n, fib(n));
    return 0;
}
