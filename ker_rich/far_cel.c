#include <stdio.h>

float fahrtocel(float fahr);

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    //print header
    printf("   F     C\n");
    printf("-----------\n");
    while (fahr <= upper) {
        celsius = fahrtocel(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

float fahrtocel(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}
