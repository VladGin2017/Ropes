#include "Rope.h"

Rope* NewRope(char* str) {
    Rope* R = malloc(sizeof(Rope));
    R->Value = str;
    R->Weight = strlen(str);
    return Adjust(R);
}

Rope* Adjust(Rope* R) {
    if (R->Weight > Lim) {
        R->Left = NewRope(SubString(R->Value, 0, R->Weight / 2));
        R->Right = NewRope(SubString(R->Value, R->Weight / 2, R->Weight));
        R->Weight = R->Weight / 2;
        R->Value = "";
    }

    return R;
}

char* InsertString(char* string, char* snippet, int loc) {
    char* tmp = malloc(sizeof(char) * loc);
    strncpy(tmp, string, loc);
    char* tmp2 = SubString(string, loc, strlen(string));
    char* newstring = malloc(sizeof(char) * (strlen(string) + strlen(snippet)));
    strncat(newstring, tmp, strlen(tmp));
    strncat(newstring, snippet, strlen(snippet));
    strncat(newstring, tmp2, strlen(tmp2));
    return newstring;
}

char* Split(Rope* R, int s, int e) {
    return SubString(String(R), s, e);
}

Rope* ConCat(Rope* R1, Rope* R2) {
    char* tmp = malloc(sizeof(char) * 2 * (R1->Weight + R2->Weight));
    strncat(tmp, String(R1), strlen(String(R1)));
    strncat(tmp, String(R2), strlen(String(R2)));
    return NewRope(tmp);
}

Rope* Rebalance(Rope* R) {
    char* rope = String(R);
    return NewRope(rope);
}

char* String(Rope* R) {
    char* strx = malloc(sizeof(char) * 2 * R->Weight);

    if (R->Value == "" && R->Left != NULL) {
        strncat(strx, String(R->Left), strlen(String(R->Left)));
    }

    if (R->Value == "" && R->Right != NULL) {
        strncat(strx, String(R->Right), strlen(String(R->Right)));
    }
}

void Insert(Rope* R, char* c, int pos) {

    if (R->Weight > pos) {
        if (R->Left != NULL) {
            Insert(R->Left, c, pos);

            if (R->Right != NULL) {
                R->Weight = R->Weight + R->Right->Weight;
            }
        } else {
            R->Value = InsertString(R->Value, c, pos);
            R->Weight = strlen(R->Value);
        }
    } else {
        if (R->Right != NULL) {
            Insert(R->Right, c, pos - R->Weight);

            if (R->Right != NULL) {
                R->Weight = R->Right->Weight;
            }
        } else {
            R->Value = InsertString(R->Value, c, pos);
            R->Weight = strlen(R->Value);
        }
    }
}

char* SubString(char* str, int s, int e) {
    char* newstring = malloc(sizeof(char) * (e - s));
    int pointer = 0;

    while (s < e) {
        newstring[pointer] = str[s];
        pointer = pointer + 1;
        s = s + 1;
    }

    return newstring;
}

char Index(Rope* R, int pos) {
    if (R->Weight > pos) {
        if (R->Left != NULL) {
            Index(R->Left, pos);
        } else {
            return R->Value[pos];
        }
    } else {
        if (R->Right != NULL) {
            Index(R->Right, pos - R->Weight);
        } else {
            return R->Value[pos];
        }
    }
}

int main() {
    //    ROPE BUILDER
    Rope* R = NewRope("GAGAN");
    Rope* R2 = NewRope("JYOT");
    Rope* R3 = ConCat(R, R2);

    //  SPLIT TEST
    s(Split(R3, 0, 3))

    //    INSERTION TEST
    Insert(R, "vv", 0);

    //      INDEX TEST
    c(Index(R, 3))
    s(Split(R, 1, 2))

    //        STRING TEST
    char* s = String(R3);
    printf("%s\n", s);
}

