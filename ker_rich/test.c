#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    
    int fd = open("unicode", 0);
    char buf[256];
    char *c = buf;

    int count = read(fd, buf, 256);
    buf[count] = '\0';
    while(*c) {
        printf("%s\n", itoa(*c));
        c++;
    }
    
    /*
    char c[3];
    c[0] = -32;
    c[1] = -77;
    c[2] = -177;

    write(1, c, 2);
    write(1, "\n", 1);
    */
}
