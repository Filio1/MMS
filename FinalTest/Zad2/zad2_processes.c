#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    if(argc <= 1){
        printf("Invalid number of arguments\n");
        return EXIT_FAILURE;
    }
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }
    int sumAll = 0;
    for(int i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return EXIT_FAILURE;
        }
        if(pid == 0){
            //child
            close(fd[0]);
            int num;
            int sum = 0;
            while(fscanf(fp, "%d", &num) != EOF){
                while(num > 0){
                    sum += num % 10;
                    num /= 10;
                }
            }
            if (write(fd[1], &sum, sizeof(int)) == -1) {
                perror("writing");
                return EXIT_FAILURE;
            }
            close(fd[1]);
            exit(EXIT_SUCCESS);
        }
        else{
            //parent
            close(fd[1]);
            int sumFile;
            if (read(fd[0], &sumFile, sizeof(int)) == -1) {
                perror("reading");
                return EXIT_FAILURE;
            }
            printf("%s - %d\n", argv[i], sumFile);
            sumAll += sumFile;
            fclose(fp);
            close(fd[0]);
            wait(NULL);
        }
        printf("Total: %d\n", sumAll);
    }
    return EXIT_SUCCESS;
}