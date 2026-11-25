#include "preprocessor.h"

int main(int argc, char *argv[])
{
    FILE *src = NULL, *des = NULL;
    FILE *temp1 = NULL, *temp2 = NULL;

    char outputfile[100];
    int len;

    if (argc != 2)
    {
        printf("Provide ./mypreprocessor filename.c\n");
        return 0;
    }

    src = fopen(argv[1], "r");

    if (src == NULL)
    {
        printf("Input file not found\n");
        return 0;
    }

    strcpy(outputfile, argv[1]);

    len = strlen(outputfile);

    if (len < 2 || outputfile[len-2] != '.' ||
        outputfile[len-1] != 'c')
    {
        printf("Input file must be .c file\n");
        fclose(src);
        return 0;
    }

    outputfile[len-1] = 'i';

    des = fopen(outputfile, "w");

    if (des == NULL)
    {
        printf("Output file creation failed\n");
        fclose(src);
        return 0;
    }

    temp1 = tmpfile();
    temp2 = tmpfile();

    if (temp1 == NULL || temp2 == NULL)
    {
        printf("Temporary file creation failed\n");
        if (temp1 != NULL) fclose(temp1);
        if (temp2 != NULL) fclose(temp2);
        fclose(src);
        fclose(des);
        return 0;
    }

    //  Remove comments
     commentRemoval(src, temp1);
     rewind(temp1);

    //  Include header files
    headerFileInclusion(temp1, temp2);
    rewind(temp2);

     //  Replace macros
     process_macros(temp2, des);

    fclose(src);
    fclose(temp1);
    fclose(temp2);
    fclose(des);

    printf("Preprocessing completed successfully\n");
    printf("Output file: %s\n", outputfile);

    return 0;
}
