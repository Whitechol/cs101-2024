#include <stdio.h>

int main()
{
    char a[] = "AABBBCCCCddd";
    int count = 1;
    int i = 0;
    while (i != sizeof(a)-1)
    {
        if (a[i] == a[i+1])
        {
            count++;
        }
        else
        {
            printf("%c%d", a[i], count);
            count = 1;
        }
        i++;
    }

    return 0;
}