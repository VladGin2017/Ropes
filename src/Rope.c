#include "Rope.h"

char* concatstring(char* a, char* b);

Rope* NewRope(char* str) {
    Rope* R = malloc(sizeof(Rope));
    R->Value = malloc((strlen(str) + 1));
    strcpy(R->Value, str);
    return Adjust(R);
}

void Preorder(Rope *r, visitFunc *f) {
  if (r == NULL) {
    return;
  }
  Preorder(r->Left, f);
  Preorder(r->Right, f);
  f(r->Value);
  f(r);
}

void DestoryRope(Rope *r) {
  Preorder(r, free);
}


Rope* Adjust(Rope* R) {
    R->Weight = strlen(R->Value);
    if (R->Weight > Lim) {
        char* a = SubString(R->Value, 0, R->Weight / 2);
        char* b = SubString(R->Value, R->Weight / 2, R->Weight);

        if (strlen(a) != 0) {
            R->Left = NewRope(a);
        }

        if (strlen(b) != 0) {
            R->Right = NewRope(b);
        }

        R->Weight /= 2;
        free(R->Value);
        free(a);
        free(b);
        R->Value = "";
    }

    return R;
}

char* InsertString(char* string, char* snippet, long loc) {
    char* tmp = malloc(loc + 1);
    strcpy(tmp, string);
    char* tmp2 = SubString(string, loc, strlen(string));
    char* newstring = malloc((strlen(string) + strlen(snippet)) + 1);
    strcat(newstring, tmp);
    strcat(newstring, snippet);
    strcat(newstring, tmp2);
    free(tmp);
    free(tmp2);
    return newstring;
}

char* Split(Rope* R, long s, long e) {
    return SubString(String(R), s, e);
}

long TotalWeight(Rope* R) {
    long weight = R->Weight;

    if (R->Right != NULL) {
        weight += R->Right->Weight;
    } else if (R->Right == NULL && R->Value != "") {
        weight += strlen(R->Value);
    }
}

Rope* ConCat(Rope* R1, Rope* R2) {
    char* tmp = malloc((TotalWeight(R1) + TotalWeight(R2)) + 1);
    strcpy(tmp, String(R1));
    strcat(tmp, String(R2));
    return NewRope(tmp);
}

Rope* Rebalance(Rope* R) {
    char* rope = String(R);
    return NewRope(rope);
}


char* String(Rope* R) {

    if (R->Value != "") {
        return R->Value;
    } else {
        return concatstring(String(R->Left), String(R->Right));
    }
}

void Insert(Rope* R, char* c, long pos) {
    if (R->Weight < pos) {
        if (R->Right != NULL) {
            Insert(R->Right, c, pos - R->Weight);
        }
    } else {
        if (R->Left != NULL) {
            Insert(R->Left, c, pos);
        } else {
            InsertString(R->Value, c, pos);
        }
    }
}

char* SubString(char* str, long s, long e) {
    char* newstring;
    newstring = malloc((e - s) + 1);
    long pointer = 0;

    while (s < e) {
        newstring[pointer] = str[s];
        pointer = pointer + 1;
        s = s + 1;
    }

    return newstring;
}


char* concatstring(char* a, char* b) {
    char* ex;
    int len = strlen(a) + strlen(b) + 1;
    ex = malloc(sizeof(char) * len);

    if (strlen(a) != 0) {
      strcpy(ex, a);
    }

    if (strlen(b) != 0) {
      strcat(ex, b);
    }

    return ex;
}

char Index(Rope* R, long pos) {
    if (R->Weight < pos) {
        if (R->Right != NULL) {
            Index(R->Right, pos - R->Weight);
        }
    } else {
        if (R->Left != NULL) {
            Index(R->Left, pos);
        } else {
            return R->Value[pos];
        }
    }
}

int main() {
    //    //    ROPE BUILDER
    //    Rope* R = NewRope("GAGAN");
    //    Rope* R2 = NewRope("JYOT");
    //    Rope* R3 = ConCat(R, R2);

    //  SPLIT TEST
    //s(Split(R3, 0, 3))

    //    //    INSERTION TEST
    //    Insert(R, "vv", 0);

    //    //      INDEX TEST
    //    c(Index(R, 3))
    //    s(Split(R, 1, 2))

    //    //        STRING TEST
    //    char* s = String(R3);
    //    printf("%s\n", s);
    FILE* f = fopen("/home/voldyman/big.txt", "r+");
    if (f == NULL) {
      printf("File could not be opened\n");
      return 1;
    }
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* S = malloc(fsize + 1);
    fread(S, fsize, 1, f);
    fclose(f);
    Rope* R = NewRope(S);
    c(Index(R, 103818668))
      c(Index(R, 103818669))
      c(Index(R, 103818670))
      c(Index(R, 103818671))
      String(R);
    ld(strlen(String(R)));
        s(Split(R, 0, 500))
    free(S);
        DestoryRope(R);
    return 0;
}
