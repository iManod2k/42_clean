#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int cont;
	t_list *ptr;

	ptr = lst;
	cont = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		cont++;
	}
	return (cont);
}
