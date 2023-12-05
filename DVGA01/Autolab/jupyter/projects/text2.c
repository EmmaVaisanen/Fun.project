#include <stdio.h>
#include <string.h>

#define MAXLENGTH 100
#define KEY 3

int main(){   
char text[MAXLENGTH], c;
fgets(text, sizeof(text), stdin);

int n = strlen(text);

for (int i = 0; i < n; i++)
{
    c = text[i];
    if (c >= 'a' && c <= 'z')
    {
        c = c - KEY; 
        if (c < 'a')
        {
            c = c + 'z' - 'a' + 1;
        }
        text[i] = c;
    }
    else if (c >= 'A' && c<= 'Z')
    {
        c = c - KEY;
        if (c < 'A')
        {
            c = c + 'Z' -'A' + 1;
        }
        text[i] = c;
    }
}
printf("%s", text);

return 0;
}