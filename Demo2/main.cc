#include <stdio.h>
#include <stdlib.h>
#include "MathFunctions.h"

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = strtod(argv[1], nullptr); // Clang-Tidy: 'atof' used to convert a string to a floating-point value, but function will not report conversion errors; consider using 'strtod' instead
    int exponent = strtol(argv[2], nullptr, 10); // Clang-Tidy: 'atoi' used to convert a string to an integer value, but function will not report conversion errors; consider using 'strtol' instead
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}
