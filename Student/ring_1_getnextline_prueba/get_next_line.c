/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:11:15 by akamal-b          #+#    #+#             */
/*   Updated: 2024/11/10 20:02:14 by akamal-b         ###   ########.fr       */
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

    // while (!ft_strchr(buffer, '\n') && byte > 0)
    while (!ft_strchr(buffer, '\n') && byte > 0)
    {
        byte = read(fd, buffer, BUFFER_SIZE);
        if (byte < 0)
        {
            if (buffer)
                free(buffer);
            if (*string && string)
                free(*string);
            return ;
        }
        if (byte == 0)
            break;
        
        buffer[BUFFER_SIZE] = '\0';
        ft_strjoin(string, buffer);

        if ( ft_strchr(buffer, '\n') )
            break ;

        ft_bzero(buffer, byte);

        if (!*string)
            return ;

        // printf("#%d#\n", byte);
        // printf("%s\n", buffer);

    }

    free(buffer);
}

void    ft_get_line(char **line, char **string)
{
    size_t cont = 0;
    size_t max = 0;
    
    while( (*string)[max] && (*string)[max] != '\n' )
        max++;
    
    ft_calloc((unsigned char **)line, max + 2, sizeof(char));
    
    if ( !(*line) )
        return ;

    if ( (*string)[max] == '\n' )
        max++;
        
    while( cont < max )
    {
        (*line)[cont] = (*string)[cont];
        cont++;
    }

    (*line)[cont] = '\0';
}

char *update_str(char *string)
{
    char *aux = NULL;
    size_t cont = 0;
    size_t cont_after_jump = 0;
    size_t i_jump = 0;

    if ( !(string) || !(string)[cont] )
        return (NULL);

    while ( (string)[cont] && (string)[cont] != '\n' )
        cont++;
    
    if ( (string)[cont] == '\n' )
        cont++;

    cont_after_jump = cont;

    while ( (string)[cont_after_jump] )
       cont_after_jump++;

    if ( (cont_after_jump - cont) <= 0 )
    {
        free(string);
        return (NULL);
    }

    ft_calloc((unsigned char **)&aux, (cont_after_jump - cont) + 1, sizeof(char));
    // ft_calloc((unsigned char **)&aux, (ft_strlen(string) - cont) + 1, sizeof(char));
    
    if (!aux) {
        free(string);
        return (NULL);
    }
    
    while ( cont < cont_after_jump )
    {
        aux[i_jump] = string[cont];
        i_jump++;
        cont++;
    }

    aux[i_jump] = '\0';

    free(string);
    string = NULL;
    
    return (aux);
}

char	*get_next_line(int fd)
{
    static char *string = NULL;
    char *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    
    
    read_fd(fd, &string);
    
    if (string == NULL)
    {
        if (line)
        {
            free(line);
            line = NULL;
        }
        return (NULL);
    }
    
    ft_get_line(&line, &string);

    if (!line)
    {
        if (string)
        {
            free(string);
            string = NULL;
        }
        return (NULL);
    }

    string = update_str(string);

    if (line && *line == '\0')
    {
        if (string)
        {
            free(string);
            string = NULL;
        }

        if (line)
        {
            free(line);
            line = NULL;
        }
    }

    return (line);
}
/*
int main(void)
{
    char *s = NULL;
    int fd;

    fd = open("../fichero.txt", O_RDONLY);
    

    s = get_next_line(fd);
    printf("%s", s);
    free(s);
    s = NULL;

    s = get_next_line(fd);
    printf("%s", s);
    free(s);
    s = NULL;

    // close(fd);
    // fd = open("../fichero.txt", O_RDONLY);

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
*/