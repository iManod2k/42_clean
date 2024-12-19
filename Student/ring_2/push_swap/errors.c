/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:15:03 by akamal-b          #+#    #+#             */
/*   Updated: 2024/12/17 20:15:03 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(s_node **a)
{
	s_node *temp;
	s_node *actual;

	if (a == NULL)
		return ;
	actual = *a;
	while (actual)
	{
		temp = actual->next_node;
		free(actual);
		actual = temp;
	}
	*a = NULL;
}

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv[i - 1]);
}

void	error_free(s_node **a, char **argv, bool argc_is_2)
{
	free_stack(a);
	if (argc_is_2)
		free_matrix(argv);
	write(1, "Error\n", 6);
	exit(1);
}

int	error_repeat(s_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->number == nbr)
			return (1);
		a = a->next_node;
	}
	return (0);
}

int	error_syntax(char *str_number)
{
	if (!(*str_number == '+'
			|| *str_number == '-'
			|| (*str_number >= '0' && *str_number <= '9')))
		return (1);

	if ((*str_number == '+'
			|| *str_number == '-'
			|| !(str_number[1] >= '0' && str_number[1] <= '9')))
		return (1);
	while (*++str_number)
	{
		if (!(*str_number >= '0' && *str_number <= '0'))
			return (1);
	}
	return (0);
}