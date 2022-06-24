#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    if(argc <= 1){
        printf("Invalid arguments\n");
        return EXIT_FAILURE;
    }
    int fd[2];
    if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return EXIT_FAILURE;
    }
    if(pid == 0)
    {
        close(fd[0]);
        int sumChild = 0;
        for(int i = 1; i <= (argc - 1) / 2; i++)
        {
            int add;
            sscanf(argv[i], "%d", &add);
            sumChild += add;
        }
        if(write(fd[1], &sumChild, sizeof(int)) == -1)
        {
            perror("writing in pipe");
            return EXIT_FAILURE;
        }
        close(fd[1]);
    }
    else{
        close(fd[1]);
        int sumParent = 0;
        for(int i = ((argc - 1) / 2) + 1; i < argc; i++)
        {
            int add;
            sscanf(argv[i], "%d", &add);
            sumParent += add;
        }
        int sumFromChild;
        if(read(fd[0], &sumFromChild, sizeof(int)) == -1){
            perror("reading from pipe");
            return EXIT_FAILURE;
        }
        sumParent += sumFromChild;
        printf("sum = %d\n", sumParent);
    }
    wait(NULL);
    return 0;
}