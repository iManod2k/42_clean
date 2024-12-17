/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:57:03 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/17 19:57:03 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(s_node **a, char **argv, bool if_argc_is_2)
{
	long	number;

	while (*argv)
	{
		number = atol(*argv);
		if (number > INT_MAX || number < INT_MIN)
			error_free(a, argv, if_argc_is_2);
		if (error_repeat(*a, (int) number))
			error_free(a, argv, if_argc_is_2);
		append_node(a, (int) number);
		argv++;
	}
}