#include <unistd.h>
#include <stdio.h>

static void  print_until_last_delimeter(char *string, int len)
{
	if (string[len] &&
			string[len] != '\0' && 
			string[len] != '\t' && 
			string[len] != ' ' &&
			len >= 0)
			{
					print_until_last_delimeter(string, len-1);
					write(1, &string[len], 1);
			}
}

static int  ft_strlen(char *string)
{
    int len;
    
    len = 0;
    while (string[len])
        len++;
    return (len);
}

void    last_word(char *string)
{
    int last_index;
    
    last_index = ft_strlen(string);
    if (last_index == 0)
        return ;
		
		last_index--;
		while ( string[last_index] != '\0' && 
						(string[last_index] == '\t' || 
						string[last_index] == ' '))
			{
					last_index--;
			}
    print_until_last_delimeter(string, last_index);
    
}

int main(int argc, char **argv)
{
    if (argc == 2)
    	last_word(argv[1]);
		write(1, "\n", 1);
    return (0);
}