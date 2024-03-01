#include <stdio.h>

int main()
{
    char a[] = "A4B1C3f3";
    for (int i = 0; i < sizeof(a) - 1; i = i + 2)
    {
        while (a[i + 1] != '0')
        {
            printf("%c", a[i]);
            a[i+1] = a[i+1] - 1;
        }
    }

    return 0;
}