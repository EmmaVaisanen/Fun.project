#include <stdio.h>

int main()

{    
int year;
scanf ("%d", &year);

if (year % 400 == 0) {
        printf("t");
    } 
else if (year % 100 == 0) {
        printf("f");
    } 
else if (year % 4 == 0) {
        printf("t");
    } 
else {
        printf("f");
    }

return 0;
}