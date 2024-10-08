/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akamal-b <akamal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:58:05 by akamal-b          #+#    #+#             */
/*   Updated: 2024/10/07 19:25:34 by akamal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lstm, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;
	t_list	*elem;

	if (lstm == NULL)
		return (NULL);
	lst_map = NULL;
	while (lstm != NULL)
	{
		elem = ft_lstnew((*f)(lstm->content));
		if (elem == NULL)
			ft_lstclear(&elem, (*del));
		else
			ft_lstadd_back(&lst_map, elem);
		lstm = lstm->next;
	}
	return (lst_map);
}
