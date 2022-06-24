#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        int sym;
        while (read(STDIN_FILENO, &sym, 1) > 0)
        {
            write(STDOUT_FILENO, &sym, 1);
        }
    }
    else
    {
        for(int i = 1; argv[i]; i++)
        {
            int fr = open(argv[i], O_RDONLY);
            if(fr == -1)
            {
                perror("\nopen read file");
                return EXIT_FAILURE;
            }
            int c;
            while (read(fr, &c, 1))
            {
                write(STDOUT_FILENO, &c, 1);
            }
            close(fr);
        }
    }
    return EXIT_SUCCESS;
}