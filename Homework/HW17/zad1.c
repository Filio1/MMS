#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int randint(int, int);
void randName(char *);

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Invalid arguments!\n");
        return EXIT_FAILURE;
    }
    int n;
    sscanf(argv[1], "%d", &n);
    for(int i = 0; i < n; i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(pid == 0){
            srand(time(NULL) + i);
            char str[11];
            randName(str);
            printf("%s\n", str);
            exit(EXIT_SUCCESS);
        }
    }
    for(int i = 0; i < n; i++){
        wait(NULL);
    }
    return 0;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void randName(char *name)
{
    int i;
    for(i = 0; i < 10; i++){
        int flag = randint(0, 1);
        if(flag){
            name[i] = randint('a', 'z');
        }
        else{
            name[i] = randint('A', 'Z');
        }
    }
    name[i] = 0;
}

                                                             
                                                            