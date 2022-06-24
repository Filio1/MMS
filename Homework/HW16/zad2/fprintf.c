#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>

void myfprintf(FILE*, const char*, ...);

int main()
{
    int n = 5;
    myfprintf(stdout, "%d", n);
    return 0;
}

void myfprintf(FILE* stream, const char* format, ...)
{
    int fd = fileno(stream);
    va_list argl;
    va_start(argl, format);
    for(int i = 0; format[i]; i++){
        if(format[i] == '%'){
            switch (format[i + 1])
            {
            case 'd':
                int num = va_arg(argl, int);
                if(write(fd, &num, sizeof(int)) == -1){
                    perror("write");
                }
                i++;
                break;
            default:
                write(fd, &format[i], 1);
                break;
            }
        }
    }
    va_end(argl);
    close(fd);
}