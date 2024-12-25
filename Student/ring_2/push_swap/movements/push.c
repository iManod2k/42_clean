/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:29:56 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/23 17:47:22 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push (s_node **dst, s_node **src)
{
	s_node	*pushed_node;

	if (!src)
		return ;
	pushed_node = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (!dst)
	{
		(*dst) = pushed_node;
		pushed_node->next = NULL;
	}else
	{
		pushed_node->next = (*dst);
		pushed_node->next->prev = pushed_node;
		(*dst) = pushed_node;
	}
}

void	pa(s_node **a, s_node **b, bool print)
{
	push(a, b);
	if (!print)
		write(2, "pa\n", 3);
}

void	pb(s_node **b, s_node **a, bool print)
{
	push(b, a);
	if (!print)
		write(2, "pb\n", 3);
}
