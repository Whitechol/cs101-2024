#include <stdio.h>

void print_str(char str[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%c", str[i]);
}

int main()
{
    char a[] = "Hello";
    char ivs_a[sizeof(a) - 1];
    for (int i = 0, j = sizeof(ivs_a) - 1; i < sizeof(ivs_a); i++, j--)
    {
        ivs_a[j] = a[i];
    }
    
    print_str(ivs_a, sizeof(ivs_a));

    return 0;
}
