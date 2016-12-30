#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int max);
int strindex(char source[], char searchform[]);

int main(int argc, char **argv)
{
    char line[MAXLINE];
    int found = 0;

    if (argc < 2)
        fprintf(stderr, "Error, to few arguments\n");

    while (my_getline(line, MAXLINE) > 0)
        if (strindex(line, argv[1]) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

int my_getline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{

    int i, j, k, index;

    index = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            index = i;
    }
    return index;
}
