#include <stdio.h>

int main() {
    int troskelvarde = 204000;
    double lag = 0.30;
    double hog = 0.50;
    int brutto;
    double netto;

    scanf("%d", &brutto);

    if (brutto <= troskelvarde) {
        netto = brutto - (brutto * lag);
    } 
    else {
        netto = brutto - (troskelvarde*lag+(brutto-troskelvarde)*hog);
    }

    printf("%.1lf\n", netto);

    return 0;
    
}