#include <stdio.h>

int main()
{
int n = 0;
int sum = 0;

while (1)
{
    scanf ("%d", &n );
  if (n == 0) {
            break;
        }
sum += n;
printf ("%d\n", sum);        
}

    return 0;
}