#include <stdio.h>

void my_strcat(char dest[], char source[]);


int main(int argc, char **argv)
{
    char result[1000] = {'F', 'i', 'r', 's', 't', ' ', '\0'};

    if (argc < 2) {
        fprintf(stderr, "Error, too few arguments\n");
        return 1;
    }

    my_strcat(result, argv[1]);
    printf("%s\n", result);

    return 0;
}

void my_strcat(char dest[], char source[])
{
    int i, j;

    i = j = 0;
    while (dest[i])
        i++;
    while((dest[i++] = source[j++]) != '\0')
        ;
}
