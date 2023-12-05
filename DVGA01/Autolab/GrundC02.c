#include <stdio.h>

int main() {
    char bokstav;

    scanf(" %c", &bokstav);

    if (bokstav >= 'b' && bokstav <= 'y') {
        char fore = bokstav - 1;
        char efter = bokstav + 1;

        printf("%c %c\n", fore, efter);
    } else {
        printf("Ange en bokstav mellan b och y.\n");
    }

    return 0;
}