#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    int linesRead = 0;
    if(argc == 1){
        int c;
        while((read(STDIN_FILENO, &c, 1) > 0) && linesRead < 10){
            write(STDOUT_FILENO, &c, 1);
            if(c == '\n')
            {
                linesRead++;
            }
        }
    }
    else if(argc == 2){
        int fd = open(argv[1], O_RDONLY);
        if(fd == -1){
            perror("open read file");
            return EXIT_FAILURE;
        }
        int c;
        while((read(fd, &c, 1) > 0) && linesRead < 10)
        {
            write(STDOUT_FILENO, &c, 1);
            if(c == '\n')
            {
                linesRead++;
            }
        }
        close(fd);
    }
    else{
        for(int i = 1; argv[i]; i++){
            int fd = open(argv[i], O_RDONLY);
            if(fd == -1){
                perror("open read file");
                return EXIT_FAILURE;
            }
            write(STDOUT_FILENO, argv[i], strlen(argv[i]));
            int c = '\n';
            write(STDOUT_FILENO, &c, 1);
            while((read(fd, &c, 1) > 0) && linesRead < 10)
            {
                write(STDOUT_FILENO, &c, 1);
                if(c == '\n')
                {
                    linesRead++;
                }
            }
            linesRead = 0;
            close(fd);
        }
    }
    return 0;
}