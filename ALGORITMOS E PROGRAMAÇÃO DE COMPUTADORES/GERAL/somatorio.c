#include <stdio.h>

int main() {
    float i = 0, somaID = 0, mediaID = 0, ID = 1;

    while (ID != 0) {
        scanf("%f", &ID);

        somaID = somaID + ID;
        i++;
    }

    mediaID = somaID / (i - 1);

    printf("MEDIA: %.1f\nQUANT: %.0f\n", mediaID, i - 1);

    return 0;
}