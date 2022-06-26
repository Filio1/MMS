#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdarg.h>
#include <fcntl.h>

void myfprintf(FILE*, const char*, ...);

int main()
{
    int n = 5;
    myfprintf(stdout, "num = %d", n);
    return 0;
}

void myfprintf(FILE* stream, const char* format, ...)
{
    int fd = fileno(stream);
    char buff[100];
    va_list argl;
    va_start(argl, format);
    for(int i = 0; format[i]; i++){
        if(format[i] == '%'){
            switch (format[i + 1])
            {
            case 'd':
                int num = va_arg(argl, int);
                sprintf(buff, "%d", num);
                fflush(stdout);
                if(write(fd, buff, strlen(buff)) == -1){
                    perror("write");
                }
                i++;
                break;
            default:
                sprintf(buff, "%c", format[i]);
                fflush(stdout);
                write(fd, buff, strlen(buff));
                break;
            }
        }
    }
    va_end(argl);
    close(fd);
}