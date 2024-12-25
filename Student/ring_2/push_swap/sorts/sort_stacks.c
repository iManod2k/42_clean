/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:18:52 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/25 23:15:58 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ensure_min_onTop(s_node **a)
{
	while ((*a)->number != stack_min(*a)->number)
	{
		if (stack_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

static void	rotate_both_untilTarget(s_node **a,
																		s_node **b,
																		s_node *cheapest_node)
{
	while (*a != cheapest_node
					&& *b != cheapest_node->target_node)
					rr(a, b, false);
	set_index_and_median(*a);
	set_index_and_median(*b);
}

static void	revRotate_both_untilTarget(s_node **a,
																				s_node **b,
																				s_node *cheapest_node)
{
	while (*a != cheapest_node
					&& *b != cheapest_node->target_node)
					rrr(a, b, false);
	set_index_and_median(*a);
	set_index_and_median(*b);
}

static void	move_a_to_b(s_node **a, s_node **b)
{
	s_node	*cheapest_node;

	cheapest_node = stack_get_cheapest(*a);
	if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate_both_untilTarget(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			revRotate_both_untilTarget(a, b, cheapest_node);
	ensure_cheap_onTop(a, cheapest_node, 'a');
	ensure_cheap_onTop(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(s_node **a, s_node **b)
{
	ensure_cheap_onTop(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	sort_stacks(s_node **a, s_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index_and_median(*a);
	ensure_min_onTop(a);
}