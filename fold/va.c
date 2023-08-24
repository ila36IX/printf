#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _sum(va_list args) {
    int sum = 0;
    int value;

    while ((value = va_arg(args, int)) != 0) {
        sum += value;
    }

    printf("Sum: %d\n", sum);

    return sum;
}

void sum_with_count(int count, ...) {
    va_list args;
    if (count < 0) {
        fprintf(stderr, "Error: count cannot be negative.\n");
        exit(1);
    }


    va_start(args, count);
    _sum(args);
    va_end(args);
}

int main() {
    sum_with_count(5, 1, 2, 3, 4, 5);
    return 0;
}

