#include <stdio.h>

int main() {
    
    for (int i = 0; i < 10; i+=2) {
        printf("I=%d J=%d\nI=%d J=%d\nI=%d J=%d\n", i + 1, 7, i + 1, 6, i + 1, 5);
    }

    return 0;
}