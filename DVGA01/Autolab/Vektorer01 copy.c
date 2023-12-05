#include <stdio.h>

int main()
{

int n, input;
scanf("%d", &n);


int a [n];

//lista för a
for (int i = 0; i < n; i++)
{
    scanf("%d", &input);
    a[i] = input;
}

for (int i = 0; i < n; i++)
{
    printf("%d\n", a[i] + b[i]); 
}


    return 0;
}