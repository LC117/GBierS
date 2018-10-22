#include <stdio.h>

int main()
{
    printf("Oct\tDec\tHex\tChar\n");
    for (int i = 0; i < 128; i++)
    {
        printf("%03o\t%i\t%02x\t%c\n",i, i, i, (char) i);
    }
}