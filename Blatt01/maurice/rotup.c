#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <malloc.h>

/**
 * A-Z : 65-90
 * a-z : 97-122
 * a + 32 = A
 * -52 = -'A' + 13
 * TODO Komischer Output für ABCDEFGHIJKLMNOPQRSTUVWXYZ -> NOPQRSTUVWXYZABCDEFGHIJKLM�
 */
int main()
{
    char input[256];
    char rot13[256];
    read(0, input, 256);
    for(int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if(c < 'A' || c > 'z' || (c < 'a' && c > 'Z')) {
            break;
        }
        if(c > 90) {
            c = (char) (c - 32);
        }
        char rot13c = (char) ('A' + ((c - 'A' + 13) % 26));
        rot13[i] = rot13c;
    }
    size_t len = strlen(input) + strlen(rot13) + 14;
    char* output = malloc(len);
    strcpy(output, "Hallo: ");
    strcat(output, input);
    strcat(output, " -- ");
    strcat(output, rot13);
    write(1, output, strlen(output));
    return 0;
}
