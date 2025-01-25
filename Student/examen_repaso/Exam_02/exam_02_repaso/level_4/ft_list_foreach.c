#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *aux;

	aux = begin_list;
	while (aux)
	{
		(*f)(aux->data);
		aux = aux->next;
	}
}

// void function (void *str)
// {
// 	((char *)str)[0] = 'A';
// }

// void	free_nodes(t_list *list)
// {
// 	t_list *aux;

// 	while (list)
// 	{
// 		aux = list->next;
// 		list->data = NULL;
// 		free(list);
// 		list = aux;
// 	}

// 	list = NULL;
// }

// int main(void)
// {
// 	char str1[] = "Hola";
// 	char str2[] = "Como";
// 	char str3[] = "Estas";

// 	t_list *list = malloc(sizeof(t_list));
// 	t_list *aux = list;
// 		list->data = str1;
// 			list->next = malloc(sizeof(t_list));
// 			list->next->data = str2;
// 				list->next->next = malloc(sizeof(t_list));
// 				list->next->next->data = str3;
// 					list->next->next->next = NULL;

// 	ft_list_foreach(list, &function);
// 	while (aux)
// 	{
// 		printf("%s\n", (char *)aux->data);
// 		aux = aux->next;
// 	}
// 	free_nodes(list);
// }