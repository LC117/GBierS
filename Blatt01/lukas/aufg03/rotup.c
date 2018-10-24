#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Hilfsfunktionen
int isLetter(char);

int isSmallLetter(char);

char *allocArr(int, const char *);

int main()
{
    // init bufferArr with size 100
    int arrSize = 100, itemCount = 0, readSize = 10;
    char *bufferArr = allocArr(arrSize, NULL);

    // read from stdin and write into bufferArr
    while (read(STDIN_FILENO, &bufferArr[itemCount], readSize) > 0)
    {
        // increase itemCount
        itemCount += strlen(&bufferArr[itemCount]);
        // stop input on '\n'
        if (bufferArr[itemCount - 1] == '\n')
        {
            // remove \n
            bufferArr[itemCount - 1] = '\0';
            itemCount--;
            break;
        }

        // check bufferArr size
        if (arrSize <= itemCount + 1)
        {
            // bufferArr to small => reallocate bufferArr
            int newArrSize = arrSize * 2;
            bufferArr = allocArr(newArrSize, bufferArr);
            arrSize = newArrSize;
        }
    }

    // write output
    write(STDOUT_FILENO, "Hallo: ", 7);
    // write input
    write(STDOUT_FILENO, bufferArr, itemCount);
    write(STDOUT_FILENO, " -- ", 4);
    // capitilize all small letters
    int i = 0;
    while (i < itemCount) {
        char c = bufferArr[i];
        if (isSmallLetter(c))
        {
            // convert small letter to capital letter
            c = c - 'a' + 'A';
        }

        // output if c is a letter
        if (isLetter(c))
        {
            // "encrypt" letter => shift 13 within the alphabet
            c = (c - 'A' + 13) % 26 + 'A';
            // write encrypted letter
            write(STDOUT_FILENO, &c, 1);
        }
        else
        {
            // stop when the first non-letter is reached
            break;
        }
        i++;
    }
    // return to new line
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}

// allocates new char* with newSize and copies the old content
char *allocArr(int newSize, const char *oldArr)
{
    if (oldArr == NULL)
    {
        return (char *)calloc(newSize, sizeof(char));
    }
    else
    {
        return (char *)realloc((void *) oldArr, newSize);
    }
}

// returns wether the given char is a letter
int isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// returns whether the given char is a small letter
int isSmallLetter(char c)
{
    return c >= 'a' && c <= 'z';
}