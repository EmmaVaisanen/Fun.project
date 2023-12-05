#include <stdio.h>
#include <stdbool.h>
#include "file.h"

void displayMenu() {
    printf("\nMeny:\n");
    printf("1. Lägg till fordon\n");
    printf("2. Ta bort fordon\n");
    printf("3. Sortera fordon efter bilmärke\n");
    printf("4. Information om fordon och ägaren\n");
    printf("5. Skriv ut hela bilregistret\n");
    printf("0. Avsluta\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int val;

    do {
        displayMenu();

        if (scanf("%d", &val) != 1) {
            printf("Error: Ogiltig inmatning, var god och mata in en siffra.\n");
            clearInputBuffer();
            continue;
        }

        switch (val) {
            case 1:
                
                break;
            case 2:
                
                break;
            
            case 0:
                printf("Program avslutat\n");
                break;
            default:
                printf("Error: Ogiltig inmatning\n");
                break;
        }
    } while (val != 0);

    return 0;
}
