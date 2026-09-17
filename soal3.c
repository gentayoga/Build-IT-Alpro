#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *a = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int compare(const void *p1, const void *p2) {
        long long x = *(const long long *)p1;
        long long y = *(const long long *)p2;
        if (x < y) return -1;
        if (x > y) return 1;
        return 0;
    }

    qsort(a, n, sizeof(long long), compare);

    long long MOD = 1000000007LL;

    long long total_pairs = ((long long)n * (n - 1) / 2) % MOD;

    long long same_pairs = 0;
    long long count = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        } else {
            same_pairs = (same_pairs + (count * (count - 1) / 2)) % MOD;
            count = 1;
        }
    }
    same_pairs = (same_pairs + (count * (count - 1) / 2)) % MOD;

    long long ans = (total_pairs - same_pairs + MOD) % MOD;

    printf("%lld\n", ans);

    free(a);
    return 0;
}