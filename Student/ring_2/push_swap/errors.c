/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:47:51 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/22 17:49:23 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n) 
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) 
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) 
		return (1);
	while (*++str_n) 
	{
		if (!(*str_n >= '0' && *str_n <= '9')) 
			return (1);
	}
	return (0);
}

int	error_duplicate(s_node *a, int n) 
{
	if (!a) 
		return (0);
	while (a) 
	{
		if (a->number == n) 
			return (1);
		a = a->next; 
	}
	return (0);
}

void	free_stack(s_node **stack) 
{
	s_node	*tmp; 
	s_node	*current;

	if (!stack) 
		return ;
	current = *stack;
	while (current) 
	{
		tmp = current->next; 
		current->number = 0; 
		free(current); 
		current = tmp; 
	}
	*stack = NULL;
}

void	free_errors(s_node **a) 
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}