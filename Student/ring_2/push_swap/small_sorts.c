/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:27:07 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/18 16:27:07 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(s_node *stack)
{
	if (stack == NULL)
		return (false);
	while (stack->next_node)
	{
		if (stack->number > stack->next_node->number)
			return (false);
		stack = stack->next_node;
	}
	return (true);
}

static s_node *find_highest(s_node *stack)
{
	int			high_number;
	s_node	*high_node;

	if (stack == NULL)
		return (NULL);

	high_number = INT_MAX;
	while (stack)
	{
		if (stack->number > high_number)
		{
			high_number = stack->number;
			high_node = stack;
		}
		stack = stack->next_node;
	}
	return (high_node);
}

void	sort_three(s_node **a)
{
	s_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if((*a)->next_node == highest_node)
		rra(a, false);
	if ((*a)->number > (*a)->next_node->number)
		sa(a, false);
}

void sort_five(s_node **a, s_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest_node(*a), 'a');
		pb(b, a, false);
	}
}