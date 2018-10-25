#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <malloc.h>

/**
 * A-Z : 65-90
 * a-z : 97-122
 * a + 32 = A
 */
int main()
{
    char input[256];
    read(0, input, 256);
    // Cut everything off after newline, because weird stuff happens afterwards
    for(int i = 0; i < 256; i++) {
        if(input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    size_t length = strlen(input);
    char *rot13 = malloc(length);
    for(int i = 0; i < length; i++) {
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
    size_t len = strlen(input) + strlen(rot13) + 13;
    char* output = malloc(len);
    strcpy(output, "Hallo: "); // 7
    strcat(output, input);
    strcat(output, " -- "); // 4
    strcat(output, rot13);
    strcat(output, "\n"); // 2
    write(1, output, strlen(output));
    return 0;
}
