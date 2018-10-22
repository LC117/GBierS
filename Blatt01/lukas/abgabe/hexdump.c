#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isPrintableChar(char);

void hexdump(FILE *output, char *buffer, int length)
{
    int offset = 0;
    while (offset <= length)
    {
        if (offset % 16 == 0)
        {
            // print the offset
            fprintf(output, "%06x :", offset);
        }

        // print the current byte
        fprintf(output, " %02x", (unsigned char) buffer[offset]);

        if ((offset + 1) % 16 == 0 || length == offset)
        {

            // add missing spaces
            int missingSpaces = 16 - offset % 16;
            while (missingSpaces)
            {
                fprintf(output, "   ");
                missingSpaces--;
            }

            // print single chars
            for (int i = offset - (offset % 16); i <= offset; i++)
            {
                char c = buffer[i];
                if (!isPrintableChar(c))
                {
                    // replace char with '.', if not printable
                    c = '.';
                }
                fprintf(output, "%c", c);
            }

            fprintf(output, "\n");
        }

        offset++;
    }
    // separate last line with new line
    fprintf(output, "\n");
}

int isPrintableChar(char c)
{
    return c >= 32 && c <= 126;
}
