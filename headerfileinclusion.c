
#include "preprocessor.h"
#include <string.h>

void headerFileInclusion(FILE *src, FILE *des)
{
    char line[1000];
    char filename[200];
    FILE *header;
    int i, j;

    while (fgets(line, sizeof(line), src) != NULL)
    {
        // Check for #include
        if (strncmp(line, "#include", 8) == 0)
        {
            i = 8;

            // Skip spaces
            while (line[i] == ' ' || line[i] == '\t')
                i++;

            // Check for double quotes or angle brackets
            if (line[i] == '"' || line[i] == '<')
            {
                char closing;

                closing = (line[i] == '"') ? '"' : '>';
                i++;

                j = 0;

                while (line[i] != closing &&
                       line[i] != '\0' &&
                       j < sizeof(filename) - 1)
                {
                    filename[j++] = line[i++];
                }

                filename[j] = '\0';

                if (line[i] == closing)
                {
                    header = fopen(filename, "r");

                    if (header != NULL)
                    {
                        char headerLine[1000];

                        while (fgets(headerLine,
                                     sizeof(headerLine),
                                     header) != NULL)
                        {
                            fputs(headerLine, des);
                        }

                        fclose(header);
                    }
                    else
                    {
                        printf("Header file not found: %s\n",
                               filename);
                    }
                }
                else
                {
                    fputs(line, des);
                }
            }
            else
            {
                fputs(line, des);
            }
        }
        else
        {
            fputs(line, des);
        }
    }
}
