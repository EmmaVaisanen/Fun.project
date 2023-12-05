#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 // Detta används för att ge vektorn ett gränsvärde för antalet siffror som skrivs ut.

int main() {
    int genereraTalfoljd(int talFoljd[]);  // Skapar vektor med 100 tal.
    int printTalfoljd(const int talFoljd[]); // Skriver ut vektorn som en 10x10 matris
    int bubbleSort(int talFoljd[]); //  Bubblesort kommer att vara den enda funktionen som manipulerar vektorn, vilket är anledningen till varför den inte har en konstant.  
    int calcStat(const int talFoljd[]); // De två sista funktionerna är beroende av Bubblesort och eftersom att vektorn inte kommer att manipuleras är det återigen konstanter som gäller.
    int SokITal(const int talFoljd[]);

    int talfoljd[SIZE];
    int talfoljdgenererad = 0;
    int talfoljdsorterad = 0;

    int val;

    do {
        printf("\nMeny:\n");  // Menyn
        printf("1. Generera talföljd\n");
        printf("2. Sortera talföljd\n");
        printf("3. Beräkna medel, median, max och minvärde\n");
        printf("4. Sök i talföljd\n");
        printf("0. Avsluta\n");

        if (scanf("%d", &val) != 1) // Förebygger att programmet brickas av bokstavsinmatning (hände mig förut :P)
        {
            printf("Error: Ogiltig inmatning, var god och mata in en siffra.\n");
            while (getchar() != '\n') //Programmet försöker märka av om en bokstav matas in
                ;
            continue;
        }

        switch (val) {
            case 1:     // Talföljdsgenerator.
                genereraTalfoljd(talfoljd);
                printTalfoljd(talfoljd);
                talfoljdgenererad = 1;
                break;
            case 2:     // Sorterar talföljden (bubble sort).
                if (talfoljdgenererad) {
                    bubbleSort(talfoljd);
                    printf("\nVektor sorterad");
                    printTalfoljd(talfoljd);
                    talfoljdsorterad = 1;
                } else {
                    printf("Error: Ingen talföljd har blivit genererad\n");
                }
                break;
            case 3:     // Räknar ut min-, maxtal, medelvärde och median.
                if (talfoljdsorterad) {
                    calcStat(talfoljd);
                } else {
                    printf("Error: Talföljden har inte sorterats, gör om föregående steg.\n");
                }
                break;
            case 4:     // Söker efter ett specifikt tal och skriver ut kolumn och rad talet befinner sig på.
                if (talfoljdsorterad) {
                    SokITal(talfoljd);
                } else {
                    printf("Error: Talföljden har inte sorterats, gör om föregående steg.\n");
                }
                break;
            case 0:     // Avslutar programmet
                printf("Program avslutat");
                break;
            default:
                printf("Error: Ogiltig inmatning\n");
                break;
        }
    } while (val != 0);

    return 0;
}
//  Talföljdgenerator
int genereraTalfoljd(int talFoljd[]) {
    for (int i = 0; i < SIZE; i++)  //  Genererar 100 slumpade tal 0 ≤ n ≤ 900
    {
        talFoljd[i] = rand() % 901; //  Siffran 901, då vi vill ha 0 ≤ n ≤ 900
    }
   int talfoljdgenererad = 1;
    return 0;
}
//  Talföljdutskrivare
int printTalfoljd(const int talFoljd[]) {
    printf("\nTalföljd:\n");        //  Printar ut talföljden
    for (int i = 0; i < SIZE; i++)
    {
         printf("%4d ", talFoljd[i]);
        if ((i + 1) % 10 == 0) {     // Radbrytning för var 10e element
            printf("\n");
    }
    }
    return 0;
}
//BubbleSort 
int bubbleSort(int talFoljd[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int a = 0; a < SIZE - i - 1; a++) 
        {
            if (talFoljd[a] > talFoljd[a + 1]) 
            {
                int temp = talFoljd[a]; //  Byter plats och sorterar på elementen
                talFoljd[a] = talFoljd[a + 1];
                talFoljd[a + 1] = temp;
            }
        }
    }
    return 0;
}
//  Medelvärde, median, min och max
int calcStat(const int talFoljd[]) {
    int min = talFoljd[0];      // Eftersom att vektorn räknar från 0 blir det sista värdet 99 om det ska finnas 100 element. 
    int max = talFoljd[99];     
    double sum = 0;
    double medel;
    double median;

//Medelvärde
for (int i = 0; i < SIZE; i++) 
{
    sum = sum + talFoljd[i];
}
medel = sum/SIZE;

//  Median 
median = (talFoljd[SIZE/2] + talFoljd[SIZE/2 - 1]) / 2; //  Det som händer här är att vi tar talen som befinner sig i pos 50 och pos 51, adderar ihop dem och sedan dividerar dem med 2

    printf("Min= %d, ", min);  
    printf("Max= %d", max);
    printf("\nMedel= %.2lf, ", medel);   
    printf("Median= %.2lf\n", median);    

    return 0;
}

// Sök i talföljd
int SokITal(const int talFoljd[]) {
   int tal;
    printf("Number: ");
    scanf("%d", &tal);

    int low = 0;
    int high = SIZE - 1;
    int hittad = 0;
//  Vi använder oss utav binary search, därav low, mid, high.
    while (low <= high) {   // Använder en while loop för att hitta det specifika talet
        int mid = (low + high) / 2;

        if (talFoljd[mid] == tal) {
            hittad = 1;
            int row = mid / 10 + 1; // Raden där talet finns
            int col = mid % 10 + 1; // Kolumnen där talet finns
            printf("Hittad %d på col %d, row %d.\n", tal, col, row);
            break;
        } else if (talFoljd[mid] < hittad) {    //Delar upp matrisen beroende på om mid är större eller mindre än variabeln tal
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!hittad) {
        printf("Tal finns ej i talföljden.\n");
    }
    return 0;
}