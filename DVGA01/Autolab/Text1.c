#include <stdio.h>
#include <string.h>

#define MAX 100

int countab(const char *text) {
    int count = 0;
    int len = strlen(text);

    for (int i = 0; i < len - 1; i++) {
        if (text[i] == 'a' && text[i + 1] == 'b') {
            count++;
        }
    }

    return count;
}

int main() {
    char text[MAX];
    fgets(text, sizeof(text), stdin);
    int abcount = countab(text);
    printf("%d\n", abcount); 
    return 0;
}
