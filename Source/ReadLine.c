#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 16384

void Help()
{
    printf("\nReads a File and prints specific line on the console...\n\nv.1.0 Created by Kvc - www.batch-man.com\n\nUSAGE:\nCall ReadLine [File] [LineNumber]\n\n");
    return;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Error: missing arguments\n");
        Help();
        return 1;
    }
    if (!strcmp(argv[1], "/?"))
    {
        Help();
        return 0;
    }
    char *file_open = argv[1];
    /* File pointer to hold reference of input file */
    FILE *fTemp;

    char buffer[BUFFER_SIZE];
    fTemp = fopen(argv[1], "r");

    /* fopen() return NULL if unable to open file in given mode. */
    if (fTemp == NULL)
    {
        fprintf(stderr, "%s: %s", file_open, strerror(errno));
        return errno;
    }

    int count = 0;
    while ((fgets(buffer, BUFFER_SIZE, fTemp)) != NULL)
    {
        count++;

        /* If current line is line to read */
        if (count == atoi(argv[2]))
        {
            printf("%s", buffer);
            //fputs(argv[3], fTemp);
            fclose(fTemp);
            return 0;
        }
    }

    return 1;
}
