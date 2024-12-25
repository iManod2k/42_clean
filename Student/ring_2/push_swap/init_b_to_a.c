/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:47:31 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/23 19:58:05 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(s_node *a, s_node *b)
{
	s_node	*current_a;
	s_node	*target_node;
	long		closest_bigger_number;
	
	while (b)
	{
		closest_bigger_number = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number
					&& current_a->number < closest_bigger_number)
			{
				closest_bigger_number = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_bigger_number == LONG_MAX)
			b->target_node = stack_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(s_node **a, s_node **b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_target_b(a, b);
}