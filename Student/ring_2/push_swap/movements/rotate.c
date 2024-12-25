/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:42:01 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/23 18:49:24 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(s_node **stack)
{
	s_node	*last_node;

	if (!(*stack))
		return ;
	last_node = stack_last_node((*stack));
	last_node->next = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
	last_node->next->prev = last_node;
}

void	ra(s_node **a, bool print)
{
	rotate(a);
	if (!print)
		write(2, "ra\n", 3);
}

void	rb(s_node **b, bool print)
{
	rotate(b);
	if (!print)
		write(2, "rb\n", 3);
}

void	rr(s_node **a, s_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(2, "rr\n", 3);
}