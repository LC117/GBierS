#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern void hexdump (FILE *output, char *buffer, int length);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("No Params passed. Printing Hexdump for test buffers:\n\n");
        
        // no params
        // Test arrays
        char lorem[140] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque interdum rutrum sodales. Nullam mattis fermentum libero, non volutpat.";
        char random0[200], random1[100], random2[20];

        hexdump(stdout, lorem, 140);
        hexdump(stdout, random0, 200);
        hexdump(stdout, random1, 100);
        hexdump(stdout, random2, 20);
    }
    else
    {
        // hexdump for passed params
        for (int i = 1; i < argc; i++)
        {
            hexdump(stdout, argv[i], strlen(argv[i]));
        }
    }

    return 0;
}