/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:10:33 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/16 15:10:33 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	s_node	*b_stack;
	s_node	*a_stack;
	
	b_stack = NULL;
	a_stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a_stack, argv + 1, argc == 2);
	if (!stack_sorted(a_stack))
	{
		if (stack_len(a_stack) == 2)
			sa(&a_stack, false);
		else if (stack_len(a_stack) == 3)
			sort_three(&a_stack);
		else if (stack_len(a_stack) > 3)
			push_swap(&a_stack, &b_stack);
	}
}
