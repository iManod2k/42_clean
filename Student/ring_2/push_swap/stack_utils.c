/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:55:54 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/23 20:02:23 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_node	*stack_min(s_node *stack)
{
	long		min;
	s_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (min > stack->number)
		{
			min_node = stack;
			min = stack->number;
		}
		stack = stack->next;
	}
	return (min_node);
}

s_node	*stack_max(s_node *stack)
{
	long		max;
	s_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (max < stack->number)
		{
			max_node = stack;
			max = stack->number;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	stack_len(s_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

bool	stack_sorted(s_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
}

s_node	*stack_last_node(s_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}