/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:26:56 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/25 20:33:27 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int											number;
	int											index;
	int											push_cost;
	bool									above_median;
	bool									cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
} s_node;
#endif

// Aux functions
char **split(char *s, char c);

// Beggining
void		init_stack_a(s_node **a, char **argv);
void		ensure_cheap_onTop(s_node **stack, s_node *top_node,char stack_name);
s_node	*stack_get_cheapest(s_node *stack);

// General Preparation commands
void	set_index_and_median(s_node *stack);

// Preparation: A nodes [] -> B stack
void	set_cheapest(s_node *stack);
void	init_nodes_a(s_node *a, s_node *b);

// Preparation: B nodes [] -> A stack
void	init_nodes_b(s_node **a, s_node **b);

// Utils
int			stack_len(s_node *stack);
bool		stack_sorted(s_node *stack);
s_node	*stack_min(s_node *stack);
s_node	*stack_max(s_node *stack);
s_node	*stack_last_node(s_node *stack);

// Sorts
void	sort_three(s_node **a);
void	sort_stacks(s_node **a, s_node **b);

// Movements
void	pa(s_node **a, s_node **b, bool print);
void	pb(s_node **b, s_node **a, bool print);
void	rra(s_node **a, bool print);
void	rrb(s_node **b, bool print);
void	rrr(s_node **a, s_node **b, bool print);
void	ra(s_node **a, bool print);
void	rb(s_node **b, bool print);
void	rr(s_node **a, s_node **b, bool print);
void	sa(s_node	**a, bool print);
void	sb(s_node **b, bool print);
void	ss(s_node **a, s_node **b, bool print);

// Errors
int	error_syntax(char *str_n);
int	error_duplicate(s_node *a, int n);
void	free_stack(s_node **stack);
void	free_errors(s_node **a);