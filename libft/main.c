#include <stdio.h>
#include "libft.h"

int main(void)
{
    char test_chars[] = {'A', 'z', ' ', '1', 128, -1};
    int i;

    printf("Tests de ft_isascii:\n");
    for (i = 0; i < sizeof(test_chars); i++) {
        printf("ft_isascii('%c') = %d\n", test_chars[i], ft_isascii(test_chars[i]));
    }

    printf("\nTests de ft_tolower:\n");
    for (i = 0; i < sizeof(test_chars); i++) {
        printf("ft_tolower('%c') = '%c'\n", test_chars[i], ft_tolower(test_chars[i]));
    }

    return 0;
}