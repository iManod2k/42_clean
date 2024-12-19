/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmnd_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:29:51 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/18 14:29:51 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(s_node **head)
{
	if (*head == NULL || head == NULL || stack_len(*head) == 1)
		return ;
	*head = (*head)->next_node;
	(*head)->prev_node->prev_node = (*head);
	(*head)->prev_node->next_node = (*head)->next_node;
	if ((*head)->next_node)
		(*head)->next_node->prev_node = (*head)->prev_node;
	(*head)->next_node = (*head)->next_node->prev_node;
	(*head)->prev_node = NULL;
}

void	sa(s_node	**a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(s_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(s_node **a, s_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}