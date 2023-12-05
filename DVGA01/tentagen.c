#include <stdio.h>
#define LIMIT 10

int main(){

int tal, antal = 0;
for (int i = 0; i < LIMIT; i++) //Vi använder LIMIT för att undvika magic numbers
{
   scanf("%d", &tal);
   if (tal%2 == 0)
{
    antal++;
}
}


printf("%d", antal);



    return 0;
}