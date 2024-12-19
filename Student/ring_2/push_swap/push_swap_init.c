/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:57:33 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/18 18:57:33 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(s_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next_node;
		++i;
	}
}

static void	set_target_node(s_node *a, s_node *b)
{
	s_node	*current_a;
	s_node	*target_node;
	long			closest_biggest_nbr;

	while (b)
	{
		closest_biggest_nbr = LONG_MAX;
		current_a = a;
		while(current_a)
		{
			if (current_a->number < closest_biggest_nbr
					&& current_a->number > b->number)
			{
				closest_biggest_nbr = current_a->number;
				target_node = current_a->target_node;
			}
			current_a = a->next_node;
		}
		if (closest_biggest_nbr == LONG_MAX)
			b->target_node = find_smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next_node;
	}
}

void	init_nodes(s_node *a, s_node *b)
{
	set_current_position(a);
	set_current_position(a);

	set_target_node(a, b);
}