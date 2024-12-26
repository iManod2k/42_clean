/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:26:56 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/26 18:52:54 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int											number;
	int											index;
	int											push_cost;
	bool										above_median;
	bool										cheapest;
	struct s_stack_node							*target_node;
	struct s_stack_node							*next;
	struct s_stack_node							*prev;
}	t_s_node;

// Aux functions
char					**split(const char *s, char c);
long					atol(const char *s);

// Beggining
t_s_node				*stack_get_cheapest(t_s_node *stack);
void					init_stack_a(t_s_node **a, char **argv);
void					ensure_cheap_ontop(t_s_node **stack,
							t_s_node *top_node, char stack_name);

// General Preparation commands
void					set_index_and_median(t_s_node *stack);

// Preparation: A nodes [] -> B stack
void					set_cheapest(t_s_node *stack);
void					init_nodes_a(t_s_node *a, t_s_node *b);

// Preparation: B nodes [] -> A stack
void					init_nodes_b(t_s_node *a, t_s_node *b);

// Utils
int						stack_len(t_s_node *stack);
bool					stack_sorted(t_s_node *stack);
void					move_a_to_b(t_s_node **a, t_s_node **b);
void					move_b_to_a(t_s_node **a, t_s_node **b);
t_s_node				*stack_min(t_s_node *stack);
t_s_node				*stack_max(t_s_node *stack);
t_s_node				*stack_last_node(t_s_node *stack);

// Sorts
void					sort_three(t_s_node **a);
void					sort_stacks(t_s_node **a, t_s_node **b);

// Movements
void					pa(t_s_node **a, t_s_node **b, bool print);
void					pb(t_s_node **b, t_s_node **a, bool print);
void					rra(t_s_node **a, bool print);
void					rrb(t_s_node **b, bool print);
void					rrr(t_s_node **a, t_s_node **b, bool print);
void					ra(t_s_node **a, bool print);
void					rb(t_s_node **b, bool print);
void					rr(t_s_node **a, t_s_node **b, bool print);
void					sa(t_s_node	**a, bool print);
void					sb(t_s_node **b, bool print);
void					ss(t_s_node **a, t_s_node **b, bool print);

// Errors
int						error_syntax(char *str_n);
int						error_duplicate(t_s_node *a, int n);
void					free_stack(t_s_node **stack);
void					free_errors(t_s_node **a);
#endif