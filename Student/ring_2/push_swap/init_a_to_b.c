/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 19:45:36 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/26 18:55:38 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index_and_median(t_s_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_s_node *a, t_s_node *b)
{
	t_s_node	*current_b;
	t_s_node	*target_node;
	long		closest_smaller_number;

	while (a)
	{
		closest_smaller_number = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number
				&& current_b->number > closest_smaller_number)
			{
				closest_smaller_number = current_b->number;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smaller_number == LONG_MIN)
			a->target_node = stack_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_s_node *a, t_s_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_s_node *stack)
{
	long		cheapest_push_cost;
	t_s_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_push_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_push_cost)
		{
			cheapest_push_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_s_node *a, t_s_node *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
