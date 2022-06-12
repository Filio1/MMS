#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 10

typedef struct
{
    char title[151];
    char author[101];
    int pages;
    double price;
}Book;

int randint(int,int);
double randReal(double,double);
void randName(char*);
void printBook(Book *);
int sortTitleASC(const void*, const void*);
int sortTitleDES(const void*, const void*);
int sortNameASC(const void*, const void*);
int sortNameDES(const void*, const void*);
int sortPagesASC(const void*, const void*);
int sortPagesDES(const void*, const void*);
int sortPriceASC(const void*, const void*);
int sortPriceDES(const void*, const void*);

typedef int (*funcPointer_t)(const void*, const void*);

int main()
{
    srand(time(NULL));
    funcPointer_t compareFunctions[] = {
        sortTitleASC,
        sortTitleDES,
        sortNameASC,
        sortNameDES,
        sortPagesASC,
        sortPagesDES,
        sortPriceASC,
        sortPriceDES
    };
    Book books[COUNT];
    for(int i = 0; i < COUNT; i++)
    {
        randName(books[i].author);
        randName(books[i].title);
        books[i].pages = randint(5, 2000);
        books[i].price = randReal(1.0, 1000.0);
    }
    qsort(books, COUNT, sizeof(*books), compareFunctions[5]);
    for(int i = 0; i < COUNT; i++)
    {
        printBook(books+i);
    }
    return 0;
}

int sortTitleASC(const void* el1, const void* el2)
{
    Book b1 = *((Book*)el1);
    Book b2 = *((Book*)el2);
    return strcmp(b1.title, b2.title);
}

int sortTitleDES(const void* el1, const void* el2)
{
    Book b1 = *((Book*)el1);
    Book b2 = *((Book*)el2);
    return strcmp(b2.title, b1.title);
}

int sortNameASC(const void* el1, const void* el2)
{
    Book b1 = *((Book*)el1);
    Book b2 = *((Book*)el2);
    return strcmp(b1.author, b2.author);
}

int sortNameDES(const void* el1, const void* el2)
{
    Book b1 = *((Book*)el1);
    Book b2 = *((Book*)el2);
    return strcmp(b2.author, b1.author);
}

int sortPagesASC(const void* el1, const void* el2)
{
    Book b1 = *((Book*)el1);
    Book b2 = *((Book*)el2);
    return b1.pages - b2.pages;
}

int sortPagesDES(const void* el1, const void* el2)
{
    Book b1 = *((Book*)el1);
    Book b2 = *((Book*)el2);
    return b2.pages - b1.pages;
}

int sortPriceASC(const void* el1, const void* el2)
{
    Book b1 = *((Book*)el1);
    Book b2 = *((Book*)el2);
    if(fabs(b1.price - b2.price) < 0.001)
    {
        return 0;
    }
    else if(b1.price > b2.price)
    {
        return 1;
    }
    return -1;
}

int sortPriceDES(const void* el1, const void* el2)
{
    Book b1 = *((Book*)el1);
    Book b2 = *((Book*)el2);
    if(fabs(b1.price - b2.price) < 0.001)
    {
        return 0;
    }
    else if(b1.price > b2.price)
    {
        return -1;
    }
    return 1;
}

void printBook(Book *book)
{
    printf("Title: %25s Author: %25s pages: %4d price: %.2lf\n", 
                book->title, book->author, book->pages, book->price);
}

void randName(char *name)
{
    int i = 0;
    name[i] = randint('A', 'Z');
    i++;
    int n = randint(5, 10);
    for(int j = 0;j < n; i++, j++)
    {
        name[i] = randint('a', 'z');
    }
    name[i] = ' ';
    i++;
    name[i] = randint('A', 'Z');
    i++;
    n = randint(5, 10);
    for(int j = 0; j < n; i++, j++)
    {
        name[i] = randint('a', 'z');
    }
    name[i] = 0;
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}