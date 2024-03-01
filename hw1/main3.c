#include <stdio.h>

int power_of_2(int power)
{
    int eq = 1;
    if (power == 0)
    {
        return eq;
    }
    else
    {
        for (int i = power; i > 0; i--)
        {
            eq = eq * 2;
        }
        return eq;
    }
}

int main()
{
    char a[] = "10001111";
    char hex[] = "0123456789ABCDEF";
    int power, count = 0, remain = (sizeof(a) - 1) % 4;

    if (remain == 0)
        power = 3;
    else if (remain == 1)
        power = 0;
    else if (remain == 2)
        power = 1;
    else if (remain == 3)
        power = 2;

    for (int i = 0; i < sizeof(a) - 1; i++)
    {
        if (a[i] == '1')
        {
            count = count + power_of_2(power);
        }
        if (power == 0)
        {
            power = 3;
            if (count != 0)
                printf("%c", hex[count]);
            count = 0;
        }
        else
        {
            power--;
        }
    }

    return 0;
} 