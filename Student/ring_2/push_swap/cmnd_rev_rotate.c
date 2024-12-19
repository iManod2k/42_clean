/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmnd_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:30:55 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/18 15:30:55 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(s_node **stack)
{
	s_node	*last_node;

	if (stack == NULL || *stack == NULL || stack_len(*stack) == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next_node = *stack;
	last_node->prev_node->next_node = NULL;
	last_node->prev_node = NULL;
	last_node->next_node->prev_node = last_node;
	*stack = last_node;
}

void	rra(s_node **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(s_node **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(s_node **a, s_node **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}