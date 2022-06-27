#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* sumDigits(void*);

typedef struct{
    int *numbers;
    int count;
}numbersInFile_t;

int main(int argc, char** argv)
{
    if(argc <= 1){
        printf("Invalid number of arguments\n");
        return EXIT_FAILURE;
    }
    pthread_t *threads = malloc(sizeof(pthread_t) * (argc-1));
    for(int i = 1, j = 0; i < argc; i++, j++){
        FILE* fp = fopen(argv[i], "r");
        numbersInFile_t nums;
        nums.count = 0;
        while (fscanf(fp, "%d", nums.numbers) != EOF)
        {
            nums.count++;
        }
        rewind(fp);
        nums.numbers = malloc(sizeof(int) * nums.count);
        for(int k = 0; k < nums.count; k++){
            fscanf(fp, "%d", &nums.numbers[i]);
        }
        fclose(fp);
        pthread_create(&threads[j], NULL, sumDigits, (void*)&nums);
    }

    for(int i = 1, j = 0; i < argc; i++, j++){
        int* sum;
        pthread_join(threads[j], (void**)&sum);
        printf("%s - %d\n", argv[i], *sum);
        free(sum);
    }

    free(threads);
    return EXIT_SUCCESS;
}

void* sumDigits(void *arg)
{
    int *sum = malloc(sizeof(int));
    *sum = 0;
    for(int i = 0; i < ((numbersInFile_t*)arg)->count; i++){
        while(((numbersInFile_t*)arg)->numbers[i] > 0){
            int digit = ((numbersInFile_t*)arg)->numbers[i] % 10;
            *sum += digit;
            ((numbersInFile_t*)arg)->numbers[i] /= 10;
        }
    }
    free(((numbersInFile_t*)arg)->numbers);
    return sum;
}