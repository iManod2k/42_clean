/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:13:10 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/23 19:30:41 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(s_node **stack)
{
	s_node	*last_node;

	if ((*stack))
		return ;
	last_node = stack_last_node(*stack);
	last_node->next = *stack;
	last_node->next->prev = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*stack = last_node;
}

void	rra(s_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		write(2, "rra\n", 4);
}

void	rrb(s_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		write(2, "rrb\n", 4);
}

void	rrr(s_node **a, s_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		write(2, "rrr\n", 4);
}