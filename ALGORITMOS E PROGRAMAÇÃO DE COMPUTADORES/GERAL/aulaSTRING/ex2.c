#include <stdio.h>
#define TAM 100

void leia_str(char *s) {
    scanf("\n%[^\n]", s);
}

void verify_str(char *s1, char *s2) {
    int i = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            i = 0;
            break;
        }
    }

    if (i == 0) {
        printf("strings diferentes\n");
    } else {
        printf("strings iguais\n");
    }
}

int main() {
    char str1[TAM], str2[TAM];

    leia_str(str1);
    leia_str(str2);
    verify_str(str1, str2);
    
    return 0;
}