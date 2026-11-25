#include "preprocessor.h"
void commentRemoval(FILE *input,FILE *output)
{
    int ch,next;
    while((ch=fgetc(input))!=EOF)
    {
        if(ch=='/')
        {
            next=fgetc(input);
            if(next == '/')
            {
                while(((ch=fgetc(input))!=EOF) && ch !='\n');
                if(ch=='\n')
                {
                    fputc(ch,output);
                }
            }
            else if(next == '*')
            {
                int prev = 0;
                while(((ch=fgetc(input))!=EOF))
                {
                    if(prev == '*' && ch == '/')
                    {
                       break;
                    }
                    prev = ch;
                }
            }
            else
            {
                fputc(ch,output);
                if(next!=EOF)
                {
                    fputc(next,output);
                }
            }
        }
        else
        {
        fputc(ch,output);
        }
    }
}
