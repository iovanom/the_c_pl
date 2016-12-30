#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 5;

    //print header
    printf("   C    F\n-----------\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * (9.0 / 5.0) + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
