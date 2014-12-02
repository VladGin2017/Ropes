#include "stdio.h"
#include "string.h"
#include "malloc.h"
typedef struct Rope Rope;

typedef struct Rope {
    Rope* Left, *Right;
    long Weight;
    char* Value;
} Rope;

#define Lim 1000

Rope* NewRope(char*);

Rope* Adjust(Rope*);

char* SubString(char*, long , long);

char* Split(Rope*, long , long);

void Insert(Rope*, char*, long);

char* InsertString(char*, char*, long);

char Index(Rope*, long);

char* String(Rope*);

Rope* Rebalance(Rope*);

Rope* ConCat(Rope*, Rope*);

#define c(tok) printf("%c\n", tok);
#define d(tok) printf("%d\n", tok);
#define ld(tok) printf("%ld\n", tok);
#define s(tok) printf("%s\n", tok);
