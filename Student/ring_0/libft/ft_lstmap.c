#include "libft.h"

t_list	*ft_lstmap(t_list *lstm void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	lst_map = NULL;
	while (lst != NULL)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (elem == NULL)
			ft_lstclear(&elem, (*del));
		else
			ft_lstadd_back(&lst_map, elem);
		lst = lst->next;
	}
	return (lst_map);
}
