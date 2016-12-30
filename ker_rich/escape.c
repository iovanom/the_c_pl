#include <stdio.h>
#include <string.h>

char *escape(char *src);

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Error, to few arguments"); 
        return 1;
    }

    printf("%s\n", escape(strdup(argv[1])));
    return 0;
}
        
