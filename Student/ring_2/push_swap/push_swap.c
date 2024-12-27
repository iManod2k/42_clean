/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:23:19 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/27 20:06:41 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_s_node	*a;
	t_s_node	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1 || argc == 2) && !argv[1][0])
		return (1);
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		init_stack_a(&a, argv);
	}
	else
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
