#include <stdio.h>
#include <memory.h>

extern void hexdump (FILE *output, char *buffer, int length);

int main() {
    char* input = "Grundlagen Betriebssystem und Systemsoftware";
    hexdump(stdout, input, (int) strlen(input));
}