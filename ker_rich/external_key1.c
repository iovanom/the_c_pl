#include <stdio.h>

char str[] = "Hello, World!";
int gl = 1000;

struct TestStatic {
    int test;
};

void test1(void);
void test2(void);
static void foo();

int main()
{

    printf("Main\n");
    printf("%d\n", gl);

    test1();
    test2();
    foo();

    return 0;
}

static void foo()
{
    printf("Static function");
}
