#include <stdio.h>

void test2()
{
    extern int gl;

    printf("test2\n");
    printf("%d\n", gl);
}
