#include <stdio.h>

int main()
{

char lang;
scanf (" %c", &lang);


switch (lang)
{
case 's':
case 'S':
   printf("hej");
    
    break;
case 'e':
case 'E':
printf("hello");

    break;
case 't':
case 'T':
printf("hallo");
break;

default:
    break;
}




    return 0;
}