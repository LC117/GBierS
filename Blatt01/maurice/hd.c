#include <stdio.h>
#include <memory.h>

extern void hexdump (FILE *output, char *buffer, int length);

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++) {
        char *input = argv[i];
        hexdump(stdout, input, (int) strlen(input));
    }
}