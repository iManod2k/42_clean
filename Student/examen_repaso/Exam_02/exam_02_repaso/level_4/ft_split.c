#include <unistd.h>
#include <stdlib.h>

int count_words(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            count++;
        i++;
    }
    return (count);
}

int count_letters(char *str)
{
    int count = 1;
    int i = 0;

    while (str[i])
    {
        if (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            count++;
        i++;
    }
    return (count);
}

#include <stdio.h>
char    **ft_split(char *str)
{
    char *string = str;
    int words = count_words(string);
    char **split_str = malloc(sizeof(char *) * words + 1);

    int start;
    int end;
    int cont = 0;
    int it_split;
    int it_wc = 0;
    while (string[cont])
    {
        while (str[cont] && (str[cont] == ' ' || str[cont] == '\t' || str[cont] == '\n'))
            cont++;
        start = cont;
        while (str[cont] && (str[cont] != ' ' && str[cont] != '\t' && str[cont] != '\n'))
            cont++;
        end = cont - 1;
        
        split_str[it_wc] = malloc(sizeof(char) * (end - start) + 1);
        it_split = 0;
        while (start <= end)
        {
            split_str[it_wc][it_split] = str[start];
            start++;
            it_split++;
        }
        it_wc++;
        cont++;
    }



    return (split_str);
}

int main(void)
{
    char string[] = "";
    char **splitted = ft_split(string);

    // printf("#%c#", splitted[1][3]);
    int i;
    i = 0;

    while (splitted[i])
    {
        printf("#%s#", splitted[i]);
        i++;
    }
}