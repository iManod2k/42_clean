/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:11:15 by akamal-b          #+#    #+#             */
/*   Updated: 2024/11/04 20:15:30 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void read_fd(int fd, char **string)
{
    char *buffer;
    int byte = 1;

    ft_calloc((unsigned char **)&buffer, (BUFFER_SIZE + 1) ,sizeof(char));
    if (!buffer)
        return ;

    while (byte)
    {
        byte = read(fd, buffer, BUFFER_SIZE);
        if (byte == -1)
        {
            if (buffer)
                free(buffer);
            if (*string && string)
                free(*string);
            return ;
        }
        buffer[BUFFER_SIZE] = '\0';
        if (byte > 0)
            ft_strjoin(string, buffer);
        
        // PRUEBA
        if(ft_strchr(buffer, '\n') != NULL)
        {
            ft_bzero(buffer, BUFFER_SIZE);
            break;
        }

        ft_bzero(buffer, BUFFER_SIZE);
    }
    free(buffer);
}

void    ft_get_line(char **line, char **string)
{
    static int s_cont = 0;
    int cont = 0;
    int calc = 0;

    // if ( !(*(string))[s_cont] )
    //     return ;
    // PRUEBA
    if ( (size_t) s_cont > ft_strlen(*string) )
    {
        s_cont = 0;
    }
    if ( !(*(string))[s_cont] )
        return ;
    
    calc = ft_strlen(*string) - ft_strlen(ft_strchr(*string + s_cont, '\n'));
    if ((*(string))[s_cont] != '\n')
        calc++;

    ft_calloc((unsigned char **)line, calc + 2, sizeof(char));
    if ((*(string))[s_cont] == '\n')
    {
        ((*line))[cont] = '\n';
        cont++;
        // s_cont++;
    }
    else
    {
        while (cont < calc)
        {
            if (!(*(string))[s_cont])
                return ;
            ((*line))[cont] = (*(string))[s_cont];
            cont++;
            if ((*(string))[s_cont] == '\n')
            {
                break;
            } 
            s_cont++;
        }
    }
    ((*line))[cont] = '\0';
    s_cont++;
}

char	*get_next_line(int fd)
{
    static char *string = NULL;
    char *line = NULL;
    
    // if (!string)
    
    // PRUEBA
    read_fd(fd, &string);
    if (string == NULL)
    {
        // if (line || *line)
        //     free(line);
        return (NULL);
    }
    // if (read(fd, 0, 0))
    //     printf("ERROR");
    

    ft_get_line(&line, &string);
    if (!line || *line == '\0')
    {
        if (string || *string)
        {
            free(string);
            string = NULL;
        }
        return (NULL);
    }
    // free(line);
    return (line);
}

int main(void)
{
    char *s = NULL;
    int fd;

    fd = open("../fichero.txt", O_RDONLY);
    


    // char c = 0;
    // read(fd, &c, 1);

    // printf("%c", c);
    // if (c == '1')
    //     printf("Bien");


    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = NULL;

    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = NULL;

    if (BUFFER_SIZE > 100) {
        char *temp;
        do {
            temp = get_next_line(fd);
            free(temp);
        } while (temp != NULL);
    }

    s = get_next_line(fd);
    printf("%s#", s);
    free(s);
    s = NULL;

    close(fd);
    fd = open("../fichero.txt", O_RDONLY);
    
    s = get_next_line(fd);
    printf("#%s", s);
    free(s);
    s = NULL;

    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = NULL;

    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = NULL;

    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = NULL;

    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = NULL;

    // char c = 0;
    // read(fd, &c, 1);
    // printf("%c", c);

    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = NULL;

    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = NULL;


    close(fd);
    return (0);
}
