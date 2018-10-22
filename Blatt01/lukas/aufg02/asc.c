#include <stdio.h>

int main()
{
    // Frage: Wie white-space-chars ausgeben?! (e.g. \n)
    printf("Oct\tDec\tHex\tChar\n");
    for (int i = 0; i < 128; i++)
    {
        printf("%03o\t%-i\t%02x\t%c\n",i, i, i, i);
    }
}