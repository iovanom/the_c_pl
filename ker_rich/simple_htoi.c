#include <stdio.h>
#include <ctype.h>

int myhtoi(const char s[]);

enum hex_chars {
    a=10, b, c, d, e, f
};

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Error, too few arguments provided");
        return 1;
    }

    printf("%d\n", myhtoi(argv[1]));
    return 0;
}

int myhtoi(const char s[])
{
    int i, n;
    char tmp[20];



}
