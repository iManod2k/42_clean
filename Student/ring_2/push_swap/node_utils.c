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