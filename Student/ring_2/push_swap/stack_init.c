/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:43:44 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/25 23:32:29 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ensure_cheap_onTop(s_node **stack,
													s_node *top_node,
													char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

s_node	*stack_get_cheapest(s_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	append_node (s_node **stack, int n)
{
	s_node	*node;
	s_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(s_node));
	if (!node)
		return ;
	node->next = NULL;
	node->number = n;
	node->cheapest = false;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}else
	{
		last_node = stack_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(s_node **a, char **argv)
{
	long	n;
	int			i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}