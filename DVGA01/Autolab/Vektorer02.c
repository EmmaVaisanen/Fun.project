#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Error: Listan måste vara mellan 1 till 100 tal stort\n");
        return 1;
    }

    float array[n - 1];

    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    float sum = 0.0, SD = 0.0;

    for (int i = 0; i < n; i++) {
        sum += array[i];
    }

    float mean = sum / n;
    sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += pow(array[i]-mean,2);
    }

    SD = sqrt(sum / (n-1));
    printf("%.6f\n", SD);

    return 0;
}
