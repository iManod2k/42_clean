/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:28:18 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/17 20:28:18 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node	*find_last_node(s_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next_node)
		head = head->next_node;
	return (head);
}

s_node	*find_smallest_node(s_node *stack)
{
	long		smallest;
	s_node	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->number < smallest)
		{
			smallest = stack->number;
			smallest_node = stack;
		}
		stack = stack->next_node;
	}
	return (smallest_node);
}

void	append_node (s_node **stack, int nbr)
{
	s_node	*node;
	s_node	*last_node;

	if (stack == NULL)
		return ;
		node = malloc(sizeof(s_node));
	if (node == NULL)
		return ;
	node->next_node = NULL;
	node->number = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev_node = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next_node = node;
		node->next_node = last_node;
	}
}

int stack_len(s_node *stack)
{
	int	len;

	len = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
			len += 1;
			stack = stack->next_node;
	}

	return (len);
}

s_node	*return_cheapest(s_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next_node;
	}
	return (NULL);
}