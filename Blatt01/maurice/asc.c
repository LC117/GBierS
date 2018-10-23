#include <stdio.h>

/**
 * Can't print the first few characters because they are reserved.
 */
int main()
{
    printf("Oct\tDec\tHex\tChar\n");
    for(int i = 0; i < 128; i++) {
        printf("%.3o\t%-3i\t%.2x\t%c\n", i, i, i, i);
    }
    return 0;
}