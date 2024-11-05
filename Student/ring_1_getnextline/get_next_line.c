/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:11:15 by akamal-b          #+#    #+#             */
/*   Updated: 2024/11/05 19:19:10 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readmyfd(char *texread, int fd)
{
	ssize_t	bytesread;
	char	*readline;
	char	*temp;

	readline = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!readline)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(texread, '\n') && bytesread > 0)
	{
		bytesread = read(fd, readline, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(readline), free(texread), NULL);
		if (bytesread == 0)
			break ;
		readline[bytesread] = '\0';
		temp = texread;
		texread = ft_strjoin(temp, readline);
		free(temp);
		if (!texread)
			return (NULL);
	}
	free(readline);
	return (texread);
}

char	*createmyline(char *texread)
{
	char	*creatline;
	int		i;
	int		j;

	i = 0;
	if (!texread)
		return (NULL);
	while (texread[i] && texread[i] != '\n')
		i++;
	if (texread[i] == '\n')
		i++;
	creatline = (char *)ft_calloc(i + 1, sizeof(char));
	if (!creatline)
		return (NULL);
	j = 0;
	while (j < i)
	{
		creatline[j] = texread[j];
		j++;
	}
	return (creatline);
}

char	*update_myreadline(char *texread)
{
	size_t	i;
	size_t	j;
	char	*myupdate;
	size_t	len;
	size_t	total_len;

	i = 0;
	j = 0;
	if (!texread)
		return (NULL);
	len = ft_strlen(texread);
	while (texread[i] != '\0' && texread[i] != '\n')
		i++;
	if ((len - i) == 0)
		return (free(texread), NULL);
	myupdate = ft_calloc((ft_strlen(texread) - i + 1), sizeof(char));
	if (!myupdate)
		return (NULL);
	total_len = len - i;
	while (j < total_len)
		myupdate[j++] = texread[++i];
	free(texread);
	return (myupdate);
}

char	*get_next_line(int fd)
{
	static char			*texread;
	char				*texread_final;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!texread)
	{
		texread = ft_calloc(1, sizeof(char));
		if (!texread)
			return (NULL);
	}
	texread = readmyfd(texread, fd);
	texread_final = createmyline(texread);
	if (!texread_final)
		return (free(texread), NULL);
	texread = update_myreadline(texread);
	if (texread_final && *texread_final == '\0')
	{
		free(texread_final);
		free(texread);
		texread_final = NULL;
		texread = NULL;
	}
	return (texread_final);
}

/*
# include <stdio.h>

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
*/