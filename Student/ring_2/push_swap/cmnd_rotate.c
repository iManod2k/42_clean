/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmnd_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:16:20 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/21 00:45:38 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(s_node **stack)
{
	s_node	*last_node;
    int     len;

    len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next_node = *stack;
	*stack = (*stack)->next_node;
	(*stack)->prev_node = NULL;
	last_node->next_node->prev_node = last_node;
	last_node->next_node->next_node = NULL;
}

void	ra(s_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(s_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(s_node **a, s_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}