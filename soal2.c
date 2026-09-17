#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 0;

    int rounds = 0;

    while (1) {
        if (a > b) swap(&a, &b);
        if (b > c) swap(&b, &c);
        if (a > b) swap(&a, &b);

        if (a == b || b == c) {
            break;
        }

        c--;
        a++;
        rounds++;
    }

    printf("%d\n", rounds);

    return 0;
}