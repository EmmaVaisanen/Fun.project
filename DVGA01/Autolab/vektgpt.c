#include <stdio.h>
#include <math.h>

float calculateSD(float array[], int n);

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Error: List size must be between 1 and 100\n");
        return 1;
    }

    float array[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    float SD = calculateSD(array, n);
    printf("Standard Deviation: %.6f\n", SD);

    return 0;
}

float calculateSD(float array[], int n) {
    double sum = 0.0, mean, SD = 0.0;

    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    mean = sum / n;

    sum = 0.0;

    for (int i = 0; i < n; i++)
        sum += (array[i] - mean) * (array[i] - mean);

    SD = sqrt(sum / n);
    return SD;
}
