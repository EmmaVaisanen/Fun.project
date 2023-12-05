#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char op;
    double a, b;

    scanf("%lf %c %lf", &a, &op, &b);

    switch (op) {
        case '+':
            printf("%.0lf + %.0lf = %.0lf", a, b, a + b);
            break;

        case '-':
            printf("%.0lf - %.0lf = %.0lf", a, b, a - b);
            break;

        case '*':
            printf("%.0lf * %.0lf = %.0lf", a, b, a * b);
            break;

        case '/':
            if (b != 0) {
                printf("%.8lf / %.8lf = %.8lf", a, b, a / b);
            } else {
                printf("NaN");
            }
            break;

        case '^':
            printf("%.0lf ^ %.0lf = %.0lf", a, b, pow(a, b));
            break;

        default:
            printf("Error! Invalid operator.\n");
            break;
    }

    return 0;
}
