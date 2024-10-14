#include <string.h>
#include <stdio.h>
#include <limits.h>

char *ft_itoa(int value, char *str, int base)
{
    int i;
    int is_negative;
    int result;
    int start;
    int end;
    char temp;

    i = 0;
    is_negative = 0;
    result = 0;
    start = 0;
    temp = 0;
    
    if (value == 0)
    {
        str[i] = '0';
        str[i + 1] = '\0';
        return (str);
    }

    if (value < 0 && base == 10)
    {
        is_negative = 1;
        if (value == INT_MIN)
        {
            value = INT_MAX;
            value ++;
        }
        value = -value;
    }

    while (value != 0)
    {
        result = value % base;
        if (result < 0)
            result = -result;

        if (result > 9)
            str[i] = result - 10 + 'a';
        else
            str[i] = result + '0';
        value /= base;
        i++;
    }

    if (is_negative)
    {
        str[i] = '-';
        i++;
    }

    str[i] = '\0';

    end = i - 1;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    return (str);
}

/*int main()
{
    char buffer[20];
    printf("1234 en base 10 : %s\n", ft_itoa(1234, buffer, 10));
    printf("-1234 en base 10 : %s\n", ft_itoa(-1234, buffer, 10));
    printf("1234 en base 16 : %s\n", ft_itoa(1234, buffer, 16));
    return (0);
}*/