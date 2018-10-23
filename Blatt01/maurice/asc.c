#include <stdio.h>

/**
 * Can't print the first few characters because they are reserved.
 */
int main() {
    printf("Oct Dec Hex Char\n");
    char str[12];
    for(int i = 0; i < 128; i++) {
        sprintf(str, "%i", i);
        char c = (char) i;
        printf("%.3o %-3s %.2x  %c\n", i, str, i, c);
    }
    return 0;
}