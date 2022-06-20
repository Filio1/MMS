#include <stdio.h>
#include <stdint.h>
#include <string.h>

void binToText(char*, char*);
void textToBin(char*, char*);

int main(int argc, char** argv)
{
    char* source = argv[1];
    char* destination = argv[2];
    if(!strcmp(argv[3], "-TB"))
    {
        textToBin(source, destination);
    }
    else if(!strcmp(argv[3], "-BT"))
    {
        binToText(source,destination);
    }
    return 0;
}

void textToBin(char* src, char* dest)
{
    FILE* file_src = fopen(src, "r");
    if(file_src == NULL)
    {
        fprintf(stderr, "Couldn't open the file\n");
        fclose(file_src);
        return;
    }
    uint16_t number;
    FILE* file_dest = fopen(dest, "wb");
    if(file_dest == NULL)
    {
        fprintf(stderr, "Can't create file\n");
        fclose(file_dest);
        return;
    }
    while (fscanf(file_src, "%hu", &number) != EOF)
    {
        fwrite(&number, sizeof(number), 1, file_dest);
    }
    fclose(file_src);
    fclose(file_dest);
}

void binToText(char* src, char* dest)
{
    FILE* file_src = fopen(src, "rb");
    if(file_src == NULL)
    {
        fprintf(stderr,"Couldn't open the file\n");
        fclose(file_src);
        return;
    }
    uint16_t number;
    FILE* file_dest = fopen(dest, "w");
    if(file_dest == NULL)
    {
        fprintf(stderr, "Can't create file\n");
        fclose(file_dest);
        return;
    }
    while(1)
    {
        if(fread(&number, sizeof(number), 1, file_src) == EOF)
        {
            break;
        }
        printf("%d\n", number);
        fprintf(file_dest, "%hu\n", number);
    }
    fclose(file_src);
    fclose(file_dest);
}