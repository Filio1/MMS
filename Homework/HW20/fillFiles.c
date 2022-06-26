#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE* fp = fopen("file2.bin", "wb");
    for(int i = 0; i < 10; i++){
        int num = rand() % 10 + 1;
        fwrite(&num, sizeof(num), 1, fp);
    }
    fclose(fp);
    return 0;
}