/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_src_dst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:26:17 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/26 18:57:00 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both_untiltarget(t_s_node **a,
										t_s_node **b,
										t_s_node *cheapest_node)
{
	while (*a != cheapest_node
		&& *b != cheapest_node->target_node)
		rr(a, b, false);
	set_index_and_median(*a);
	set_index_and_median(*b);
}

static void	revrotate_both_untiltarget(t_s_node **a,
											t_s_node **b,
											t_s_node *cheapest_node)
{
	while (*a != cheapest_node
		&& *b != cheapest_node->target_node)
		rrr(a, b, false);
	set_index_and_median(*a);
	set_index_and_median(*b);
}

void	move_a_to_b(t_s_node **a, t_s_node **b)
{
	t_s_node	*cheapest_node;

	cheapest_node = stack_get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both_untiltarget(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		revrotate_both_untiltarget(a, b, cheapest_node);
	ensure_cheap_ontop(a, cheapest_node, 'a');
	ensure_cheap_ontop(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_s_node **a, t_s_node **b)
{
	ensure_cheap_ontop(a, (*b)->target_node, 'a');
	pa(a, b, false);
}
