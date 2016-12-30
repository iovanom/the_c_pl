#include <stdio.h>
#include <string.h>

void squeeze(char src[], char chars[]);
int char_in_str(char c, char str[]);

int main(int argc, char **argv)
{
    char *src, *chars;

    if (argc < 3){
        fprintf(stderr, "Error, too few arguments");
        return 1;
    }

    src = strdup(argv[1]);
    chars = strdup(argv[2]);
    squeeze(src, chars);

    printf("%s\n", src);

    return 0;
}

void squeeze(char src[], char chars[])
{
    int i, j;

    i = j = 0;
    while (src[i]) {
        if (!char_in_str(src[i], chars))
            src[j++] = src[i];
        i++;
    }
    src[j] = '\0';
}

int char_in_str(char c, char str[])
{
    int i;
    
    i = 0;
    while (str[i])
        if (str[i++] == c)
            return 1;
    return 0;
}
