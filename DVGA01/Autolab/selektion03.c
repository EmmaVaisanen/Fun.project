#include <stdio.h>

int main()

{
int n;
int summa = 0;
int sistterm = 0;

scanf ("%d", &n);

for (int i = 1; summa <= n; i++)
{
    sistterm = i; 
    summa += i;
}

printf("%d %d\n", summa, sistterm);



    return 0;
}