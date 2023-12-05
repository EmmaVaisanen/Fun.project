#include <stdio.h>

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);

    int a = x + y;
    int b = x * y;

    if (y != 0) {
        int c = x / y;
        printf("%d %d %d\n", a, b, c);
    } else {
        printf("Ej definierat.\n");
    }

    return 0;
}
