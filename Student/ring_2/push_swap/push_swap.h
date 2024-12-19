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
	int							push_cost;
	bool						above_median;
	bool						cheap;
	struct s_nodes	*target_node;
	struct s_nodes	*next_node;
	struct s_nodes	*prev_node;
} s_node;

// Beggining
void	stack_init(s_node **a, char **argv, bool if_argc_is_2);

// Errors
void	free_stack(s_node **a);
void	free_matrix(char **argv);
void	error_free(s_node **a, char **argv, bool argc_is_2);
int		error_repeat(s_node *a, int nbr);
int		error_syntax(char *str_number);

// Stack init & modifiers
void	set_current_position(s_node *stack);
void	set_price(s_node *a, s_node *b);
void	set_cheapest(s_node *b);
void	init_nodes(s_node *a, s_node *b);

// String Functions
char		**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
long		ft_atol(const char *nptr);

// Stack
s_node	*find_last_node(s_node *head);
s_node	*find_smallest_node(s_node *stack);
s_node	*return_cheapest(s_node *stack);
void		append_node(s_node **stack, int nbr);
int			stack_len(s_node *stack);

// small Algorythms
bool	stack_sorted(s_node *stack);
void	sort_three(s_node **a);
void	sort_five(s_node **a, s_node **b);

// big Algorythms
void	push_swap(s_node **a, s_node **b);
void	finish_rotation(s_node **stack, s_node *top_node, char stack_name);


// Operations
void	sa(s_node	**a, bool checker);
void	sb(s_node **b, bool checker);
void	ss(s_node **a, s_node **b, bool checker);
void	ra(s_node **a, bool checker);
void	rb(s_node **b, bool checker);
void	rr(s_node **a, s_node **b, bool checker);
void	rra(s_node **a, bool checker);
void	rrb(s_node **b, bool checker);
void	rrr(s_node **a, s_node **b, bool checker);
void	pa(s_node **a, s_node **b, bool checker);
void	pb(s_node **b, s_node **a, bool checker);