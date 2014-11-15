#include "stdio.h"
#include "string.h"
#include "malloc.h"
typedef struct Rope Rope;

typedef struct Rope {
    Rope* Left, *Right, *Parent;
    int Weight;
    char* Value;
} Rope;

#define Lim 2

Rope* NewRope(char* str);

Rope* Adjust(Rope* R);

char* SubString(char*, int , int);

Rope Split(Rope*, int , int);

Rope Insert(Rope* R, char* c, int pos);

char* InsertString(char* string, char* snippet, int loc);

#define c(tok) printf("%c\n", tok);
#define d(tok) printf("%d\n", tok);
#define s(tok) printf("%s\n", tok);

