/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:55:54 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/26 18:56:47 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_s_node	*stack_min(t_s_node *stack)
{
	long		min;
	t_s_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->number < min)
		{
			min_node = stack;
			min = stack->number;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_s_node	*stack_max(t_s_node *stack)
{
	long		max;
	t_s_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max_node = stack;
			max = stack->number;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	stack_len(t_s_node *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

bool	stack_sorted(t_s_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_s_node	*stack_last_node(t_s_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
