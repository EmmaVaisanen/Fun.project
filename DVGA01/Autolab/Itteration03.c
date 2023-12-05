#include <stdio.h>

int main()

{
#define seklangd 10
int num;
int storst, minst; 

for (int i = 1; i <= seklangd; i++)
{
    scanf("%d", &num);
    if (i == 1) {
            storst = minst = num;
        } else {
            if (num > storst) {
                storst = num;
            }
            if (num < minst) {
                minst = num;
            }
        }

}
printf("%d %d\n", storst, minst); 

return 0;
}