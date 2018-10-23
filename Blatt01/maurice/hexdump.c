#include <stdio.h>
#include <memory.h>
#include <malloc.h>

void hexdump (FILE *output, char *buffer, int length);

void hexdump (FILE *output, char *buffer, int length)
{
    int i = 0;
    while(i <= length) {
        fprintf(output, "%.6x : ", i);
        char characters[16];
        for(int j = 0; j < 16; j++, i++) {
            if(i <= length) {
                unsigned char c = (unsigned char) buffer[i];
                if(c > 31 && c < 127) {
                    characters[j] = c;
                } else {
                    characters[j] = '.';
                }
                fprintf(output, "%.2x ", c);
            } else {
                fprintf(output, "   ");
                characters[j] = '\0';
            }
        }
        fprintf(output, "  %s\n", characters);
    }
    fprintf(output, "%s", "\n");
}