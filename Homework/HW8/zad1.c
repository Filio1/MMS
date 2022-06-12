#include <stdio.h>
#include <string.h>

size_t myStrLen(const char *);
size_t myStrnLen(const char *, size_t);
char* myStrcat(char*, char*);
char* myStrncat(char*, char*, size_t);
char* myStrcpy(char*, char*);
char* myStrncpy(char*, char*, size_t);
int myStrcmp(const char*, const char*);
int myStrncmp(const char*, const char*,size_t);

int main()
{
    char str[] = "How long is this?";
    char str2[] = "A longer string than the first one";
    printf("%d\n", myStrncmp(str,str2, 10));
    myStrncpy(str2, str, sizeof(str2));
    printf("s1=%s\ns2=%s\n", str, str2);
    printf("%d\n", myStrncmp(str,str2, 10));
    //printf("%lu %lu\n%lu %lu\n", myStrLen(str), strlen(str), myStrnLen(str2,17), strnlen(str2,17));
    return 0;
}

int myStrcmp(const char *str1, const char *str2)
{
    int diff = 0;
    int len_first = strlen(str1);
    int len_second = strlen(str2);
    int len_diff = len_first - len_second;
    if(len_diff == 0)
    {
        for(int i = 0; str1[i]; i++)
        {
            diff = str1[i] - str2[i];
            if(diff != 0) return diff;
        }
        return diff;
    }
    else if(len_diff < 0)
    {
        for(int i = 0; i <= len_first; i++)
        {
            diff = str1[i] - str2[i];
            if(diff != 0) return diff;
        }
        return diff;
    }
    else
    {
        for(int i = 0; i <= len_second; i++)
        {
            diff = str1[i] - str2[i];
            if(diff != 0) return diff;
        }
        return diff;
    }
}

int myStrncmp(const char *str1, const char *str2, size_t n)
{
    int diff = 0;
    int len_first = strlen(str1);
    int len_second = strlen(str2);
    int len_diff = len_first - len_second;
    if(len_diff == 0)
    {
        for(int i = 0; str1[i] && i < n; i++)
        {
            diff = str1[i] - str2[i];
            if(diff != 0) return diff;
        }
        return diff;
    }
    else if(len_diff < 0)
    {
        for(int i = 0; i <= len_first && i < n; i++)
        {
            diff = str1[i] - str2[i];
            if(diff != 0) return diff;
        }
        return diff;
    }
    else
    {
        for(int i = 0; i <= len_second && i < n; i++)
        {
            diff = str1[i] - str2[i];
            if(diff != 0) return diff;
        }
        return diff;
    }
}

char* myStrcat(char* dest, char* src)
{
    size_t destlen = strlen(dest);
    int i = 0;
    for(; src[i]; i++)
    {
        dest[destlen + i] = src[i];
    }
    dest[destlen + i] = 0;
    return dest;
}

char* myStrncat(char* dest, char* src, size_t n)
{
    size_t destLen = strlen(dest);
    int i = 0;
    for(;i < n && src[i]; i++)
    {
        dest[destLen + i] = src[i];
    }
    dest[destLen + i] = 0;
    return dest;
}

char* myStrcpy(char* dest, char* src)
{
    int i = 0;
    for(;src[i]; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = 0;
    return dest;
}

char* myStrncpy(char* dest, char* src, size_t n)
{
    int i = 0;
    for(; i < n && src[i]; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = 0;
    return dest;
}

size_t myStrLen(const char *str)
{
    size_t count = 0;
    while (str[count])
    {
        count++;
    }
    return count;
}

size_t myStrnLen(const char *str, size_t maxlen)
{
    size_t count = 0;
    while (str[count] && count < maxlen)
    {
        count++;
    }
    return count;
}
