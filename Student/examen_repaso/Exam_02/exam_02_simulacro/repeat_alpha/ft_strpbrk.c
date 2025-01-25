#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    const char *s = s1;
    const char *needle;

    while (*s)
    {
        needle = s2;
        while (*needle)
        {
            if (*s == *needle)
                return ((char *)s);
            needle++;
        }
        s++;
    }
    return (NULL);
}

int main(void)
{
    char *s1 = "Hala cama astas ! yo? Bien gracas !";
    char *s2 = "";

    printf("%s", ft_strpbrk(s1, s2));
    printf("\n");
    printf("%s", ft_strpbrk(s1, s2));
    return (0);
}