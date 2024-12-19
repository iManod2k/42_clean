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

void    set_price(s_node *a, s_node *b)
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while (b)
    {
        b->push_cost = b->index;
        if (!(b->above_median))
            b->push_cost = len_b - (b->index);
        if (b->target_node->above_median)
            b->push_cost += b->target_node->index;
        else
            b->push_cost += len_a - (b->target_node->index);
        b = b->next_node;
    }
}

void	set_cheapest(s_node *b)
{
	long		cheapest_move;
	s_node	*cheapest_node;

	if (b == NULL)
		return ;
	cheapest_move = INT_MAX;
	while (b)
	{
		if (b->push_cost < cheapest_move)
		{
			cheapest_node = b;
			cheapest_move = b->push_cost;
		}
		b = b->next_node;
	}
	cheapest_node->cheap = true;
}

void	init_nodes(s_node *a, s_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}