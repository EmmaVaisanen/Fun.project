#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100
#define RANDOM 901
#define ROWBREAKER 10
#define MIN 0
#define MAX 99
#define ROWFINDER 10
#define COLFINDER 10

int genereraTalfoljd(int talFoljd[]);
int printTalfoljd(const int talFoljd[]);
int bubbleSort(int talFoljd[]);
int calcStat(const int talFoljd[]);
int SokITal(const int talFoljd[]);

int main() {
    int talfoljd[SIZE];
    bool talfoljdgenererad = false;
    bool talfoljdsorterad = false;

    int val;

    do {
        printf("\nMeny:\n");
        printf("1. Generera talföljd\n");
        printf("2. Sortera talföljd\n");
        printf("3. Beräkna medel, median, max och minvärde\n");
        printf("4. Sök i talföljd\n");
        printf("0. Avsluta\n");

        if (scanf("%d", &val) != 1) {
            printf("Error: Ogiltig inmatning, var god och mata in en siffra.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (val) {
            case 1:
                genereraTalfoljd(talfoljd);
                printTalfoljd(talfoljd);
                talfoljdgenererad = true;
                talfoljdsorterad = false; // Reset sorting status
                break;
            case 2:
                if (talfoljdgenererad && !talfoljdsorterad) {
                    bubbleSort(talfoljd);
                    printf("\nVektor sorterad");
                    printTalfoljd(talfoljd);
                    talfoljdsorterad = true;
                } else if (!talfoljdgenererad) {
                    printf("Error: Ingen talföljd har blivit genererad\n");
                } else {
                    printf("Error: Talföljden har redan sorterats\n");
                }
                break;
            case 3:
                if (talfoljdsorterad) {
                    calcStat(talfoljd);
                } else {
                    printf("Error: Talföljden har inte sorterats, gör om föregående steg.\n");
                }
                break;
            case 4:
                if (talfoljdsorterad) {
                    SokITal(talfoljd);
                } else {
                    printf("Error: Talföljden har inte sorterats, gör om föregående steg.\n");
                }
                break;
            case 0:
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
        talFoljd[i] = rand() % RANDOM; //  Siffran 901 (RANDOM), då vi vill ha 0 ≤ n ≤ 900. Använder rand som slumpar de 100 talen.
    }
   int talfoljdgenererad = 1;
    return 0;
}
//  Talföljdutskrivare
int printTalfoljd(const int talFoljd[]) {
    printf("\nTalföljd:\n");        //  Printar ut talföljden
    for (int i = 0; i < SIZE; i++)  //   Skriver ut de 100 elementen
    {
         printf("%4d ", talFoljd[i]);
        if ((i + 1) % ROWBREAKER == 0) {     // Radbrytning för var 10e element
            printf("\n");
    }
    }
    return 0;
}
//BubbleSort 
int bubbleSort(int talFoljd[]) {
    for (int i = 0; i < SIZE - 1; i++) { // For looparna sorterar och byter plats på elementen tills allt är i storleksordning. 
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
    int min = talFoljd[MIN];      //  Eftersom att vektorn räknar från 0 blir det sista värdet 99 om det ska finnas 100 element. 
    int max = talFoljd[MAX];     //  Väljer därför att skriva ut element [0] och [99]
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

    printf("\nMin= %d, ", min);  
    printf("Max= %d", max);
    printf("\nMedel= %.2lf, ", medel);   
    printf("Median= %.2lf\n", median);    

    return 0;
}

// Sök i talföljd  (gjorde en som tog mig timmar att hitta :( )
int SokITal(const int talFoljd[]) {
   int tal;
    printf("Number: ");
    scanf("%d", &tal);

    int low = 0;
    int high = SIZE - 1;
    int hittad = 0;
    while (low <= high) {   //  Använder en while loop för att hitta det specifika talet
        int mid = (low + high) / 2;

        if (talFoljd[mid] == tal) {
            hittad = 1;
            int row = mid / ROWFINDER + 1; // Raden där talet finns
            int col = mid % COLFINDER + 1; // Kolumnen där talet finns
            printf("Hittad %d på col %d, row %d.\n", tal, col, row);
            break;
        } else if (talFoljd[mid] < tal) {    // Delar upp matrisen beroende på om mid är större eller mindre än variabeln tal
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!hittad) {
        printf("Tal finns ej\n");
    }
    return 0;
}