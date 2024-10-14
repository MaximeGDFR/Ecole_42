#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *d;
    const unsigned char *s;

    i = 0;
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    //Cast en char* pour copier octet par octet directement dans la boucle

    //Verifie chevauchement memoire
    if (d < s || d >= s + n)
    {
        //Pas de chevauchement = copie en avant
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else
    {
        //Chevauchement = copie en arriere
        i = n;
        while (i > 0)
        {
            d[i - 1] = s[i - 1];
            i--;
        }
    }

    return (d);
}

/*int main()
{
    char s1 [20] = "Hello world";
    char s2 [] = "Hello world !";
    size_t n = 13;

    printf("Avant memmove: s1 = %s, s2 = %s\n", s1, s2);
    ft_memmove(s1, s2, n);
    printf("Apres memmove: s1 = %s\n", s1);

    return (0);
}*/