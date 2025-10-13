#include <stdio.h>

long long fib_aux(int n, long long a, long long b) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fib_aux(n - 1, b, a + b);
}

long long fib(int n) {
    return fib_aux(n, 0, 1);
}

int main(void) {
    int n = 50;
    printf("Fib(%d) = %lld\n", n, fib(n));
    return 0;
}
