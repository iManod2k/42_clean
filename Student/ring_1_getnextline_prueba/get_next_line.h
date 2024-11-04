/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:15:27 by jdecorte          #+#    #+#             */
/*   Updated: 2024/11/02 23:00:25 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//------ LIBS ------//
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
//--- BUFFER_SIZE ---//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//-- GET NEXT LINE --//
char	*get_next_line(int fd);
//
void	ft_strdup(const char *s, char **duplicate);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_calloc(unsigned char **p, size_t numele, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
void    ft_get_line(char **line, char **string);
void	ft_strjoin(char **s1, char *s2);
#endif
