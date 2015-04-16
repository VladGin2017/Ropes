#include "stdio.h"
#include "string.h"
#include "malloc.h"
typedef struct _Rope {
    struct _Rope *Left, *Right;
    int Weight;
    char* Value;
} Rope;

#define Lim 2

Rope* NewRope(char*);

Rope* Adjust(Rope*);

char* SubString(char*, int , int);

char* Split(Rope*, int , int);

void Insert(Rope*, char*, int);

char* InsertString(char*, char*, int);

char Index(Rope*, int);

char* String(Rope*);

Rope* Rebalance(Rope*);

Rope* ConCat(Rope*, Rope*);

#define c(tok) printf("%c\n", tok);
#define d(tok) printf("%d\n", tok);
#define s(tok) printf("%s\n", tok);
