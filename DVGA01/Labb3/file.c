#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "file.h"

#define MAXFORDON 10
#define MAXTECKEN 50
#define REGNR 6

typedef struct file
{
    char FordonType [MAXTECKEN];
    char FordonBrand [MAXTECKEN];
    char RegNum [REGNR];
    char OwnerName [MAXTECKEN];
    int OwnerAge;

}FordonAgarInfo;

void displayMenu() {        //menyn
    printf("\nMeny:\n");
    printf("1. Lägg till fordon\n");
    printf("2. Ta bort fordon\n");
    printf("3. Sortera fordon efter bilmärke\n");
    printf("4. Information om fordon och ägaren\n");
    printf("5. Skriv ut hela bilregistret\n");
    printf("0. Avsluta\n");
}

void clearInputBuffer() {       //Ser till att programmet inte brickas vid felinmatning
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void laggtill(FordonAgarInfo fordon[], int *numFordon) {
    if (*numFordon < MAXFORDON) {
        FordonAgarInfo NyttFordon;

    printf("Ange fordontyp: ");
        fgets(NyttFordon.FordonType, sizeof(NyttFordon.FordonType), stdin);
        strtok(NyttFordon.FordonType, "\n");

    printf("Ange fordonets märke: ");
        fgets(NyttFordon.FordonBrand, sizeof(NyttFordon.FordonBrand), stdin);
        strtok(NyttFordon.FordonBrand, "\n");

    printf("Ange fordonets registreringsnummer: ");
        fgets(NyttFordon.RegNum, sizeof(NyttFordon.RegNum), stdin);
        strtok(NyttFordon.RegNum, "\n");

    printf("Ange ägarens namn: ");
        fgets(NyttFordon.OwnerName, sizeof(NyttFordon.OwnerName), stdin);
        strtok(NyttFordon.OwnerName, "\n");

    printf("Ange ägarens ålder: ");
        char ageInput[10]; 
        fgets(ageInput, sizeof(ageInput), stdin);
        NyttFordon.OwnerAge = atoi(ageInput); 

        fordon[*numFordon] = NyttFordon;
        (*numFordon)++;

    printf("Fordonet har lagts till i fordonregistret.\n");
    } else {
    printf("Fordonregistret är fullt.\n");
    }
}

void tabort(FordonAgarInfo fordon[], int *numFordon){
int index;

printf("Ange det fordon som skall tas bort (1-%d)", *numFordon);
scanf("%d", &index);

if (index <= 0 || index > *numFordon)
{
    printf ("Error: Ogiltig siffra inmatad, var god och försök igen.\n");
    return;
}

index --;

 for (int i = index; i < *numFordon - 1; i++) {
        fordon[i] = fordon[i + 1];
    }
    (*numFordon)--;
printf("Fordonet har tagits bort från registret.\n");
}

void versalforstabokstav(char str[]){       //Skriver om gemener till versaler för sorteringsalgoritmen.
if(str[0] >= 'a' && str[0] <= 'z') 
{
        str[0] = toupper(str[0]);
}
}

void bilmarkesort(FordonAgarInfo fordon[], int numFordon){
FordonAgarInfo temp;

for (int i = 0; i < numFordon; i++)
{
    versalforstabokstav(fordon[i].FordonBrand);
}
for (int i = 0; i < numFordon - 1; i++) { // For looparna sorterar och byter plats på elementen tills allt är i storleksordning. 
        for (int a = 0; a < numFordon - i - 1; a++) 
        {
            if (strcmp(fordon[a].FordonBrand, fordon[a+1].FordonBrand) > 0)
            {
               temp = fordon[a];
               fordon[a] = fordon[a+1];
               fordon[a+1] = temp;
            }
            
        }
    }
printf("Fordonen har nu sorterats i bokstavsordning\n");
}

void visafordoninfo(FordonAgarInfo){


}

void visaregister(FordonAgarInfo){

}