/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:12:03 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/16 15:12:03 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
# if defined(_WIN32)
#  include <io.h>
# elif defined(UNIX)
#  include <unistd.h>
# endif

typedef struct s_nodes
{
	int							number;
	int							index;
	int							final_index;
	int							push_cost;
	bool						above_median;
	bool						cheap;
	struct s_nodes	*target_node;
	struct s_nodes	*next_node;
	struct s_nodes	*prev_node;
} s_node;

// Errors
void	free_stack(s_node **a);
void	free_matrix(char **argv);
void	error_free(s_node **a, char **argv, bool argc_is_2);
int		error_repeat(s_node *a, int nbr);

// Stack
s_node	*find_last_node(s_node *head);
void		append_node (s_node **stack, int nbr);

// Beggining
void	stack_init(s_node **a, char **argv, bool if_argc_is_2);

// String Functions
char		**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
long		ft_atol(const char *nptr);