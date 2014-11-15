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

Rope Insert(Rope* R, char* c, int pos) {

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
    // ROPE BUILDER
    Rope* R = NewRope("abcdefghijklmnopqrstuvwxyz");
    Insert(R, "vv", 0);
    s(R->Left->Left->Left->Left->Value)
    d(R->Left->Left->Left->Left->Weight)
    // INDEX TEST
    c(Index(R, 3))
}

