/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: akamal-b <akamal-b@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/29 22:11:15 by akamal-b		  #+#	#+#			 */
/*   Updated: 2024/11/10 20:44:12 by akamal-b		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char	*freevars(char *s1, char *s2, char *s3)
{
	if (s1 && *s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(s2);
		s2 = NULL;
	}
	if (s3)
		free(s3);
	return (NULL);
}

void	read_fd(int fd, char **string)
{
	char	*buffer;
	int		byte;

	byte = 1;
	ft_calloc((unsigned char **)&buffer, (BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return ;
	while (!ft_strchr(buffer, '\n') && byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buffer);
			freevars(*string, NULL, NULL);
			return ;
		}
		if (byte == 0)
			break ;
		ft_strjoin(string, buffer, -1, -1);
		if (ft_strchr(buffer, '\n'))
			break ;
		ft_memset(buffer, '\0', byte);
	}
	free(buffer);
}

void	ft_get_line(char **line, char **string)
{
	size_t	cont;
	size_t	max;

	cont = 0;
	max = 0;
	while ((*string)[max] && (*string)[max] != '\n')
		max++;
	ft_calloc((unsigned char **)line, max + 2, sizeof(char));
	if (!(*line))
		return ;
	if ((*string)[max] == '\n')
		max++;
	while (cont < max)
	{
		(*line)[cont] = (*string)[cont];
		cont++;
	}
	(*line)[cont] = '\0';
}

char	*update_str(char *string)
{
	char	*aux;
	size_t	cont;
	size_t	i_jump;

	aux = NULL;
	cont = 0;
	i_jump = 0;
	if (!(string))
		return (NULL);
	while ((string)[cont] && (string)[cont] != '\n')
		cont++;
	if ((string)[cont] == '\n')
		cont++;
	if ((ft_strlen(string) - cont) <= 0)
		return (freevars(string, NULL, NULL));
	ft_calloc((unsigned char **)&aux, (ft_strlen(string) - cont) + 1, 1);
	if (!aux)
		return (freevars(string, NULL, NULL));
	while (cont < ft_strlen(string))
		aux[i_jump++] = string[cont++];
	freevars(string, NULL, NULL);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*string = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_fd(fd, &string);
	if (string == NULL)
		return (freevars(line, NULL, NULL));
	ft_get_line(&line, &string);
	if (!line)
		return (freevars(string, NULL, NULL));
	string = update_str(string);
	if (line && *line == '\0')
	{
		freevars(string, NULL, NULL);
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