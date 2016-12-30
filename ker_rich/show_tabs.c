#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == '\b' || c == '\\') {
            putchar('\\');
            if (c == '\t')
                putchar('t');
            if (c == '\b')
                putchar('b');
            if (c == '\\')
                putchar('\\');
        } else {
            putchar(c);
        }
    }
}
