/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:29:56 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/26 18:41:46 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_s_node **dst, t_s_node **src)
{
	t_s_node	*pushed_node;

	if (*src == NULL)
		return ;
	pushed_node = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (*dst == NULL)
	{
		(*dst) = pushed_node;
		pushed_node->next = NULL;
	}
	else
	{
		pushed_node->next = *dst;
		pushed_node->next->prev = pushed_node;
		*dst = pushed_node;
	}
}

void	pa(t_s_node **a, t_s_node **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_s_node **b, t_s_node **a, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}
