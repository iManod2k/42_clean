/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:15:27 by jdecorte          #+#    #+#             */
/*   Updated: 2024/10/31 12:16:09 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//------ LIBS ------//
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
//--- BUFFER_SIZE ---//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//-- GET NEXT LINE --//
char	*get_next_line(int fd);
char	*readmyfd(char *texread, int fd);
char	*createmyline(char *texread);
char	*update_texread(char *texread);
//
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t numele, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
#endif
