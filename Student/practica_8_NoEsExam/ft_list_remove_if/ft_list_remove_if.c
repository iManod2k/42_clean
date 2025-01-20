#include "ft_list.h"

#include <stdio.h>
int cmp (void *d1, void *d2)
{
    char l1 = ((char *)d1)[0];
    char l2 = ((char *)d2)[0];

    if (l1 == l2)
        return (0);
    else
        return (1);
}


#include <unistd.h>
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *previous;
    t_list *aux;

    if (!begin_list || !*begin_list)
        return ;

    while ( (*begin_list) )
    {
        previous = (*begin_list);
        (*begin_list) = (*begin_list)->next;
        if ( (*begin_list) && (cmp((*begin_list)->data, data_ref) == 0))
        {
            aux = (*begin_list);
            (*begin_list) = (*begin_list)->next;
            free(aux);

            if ( !(*begin_list) )
            {
                previous->next = NULL;
                break ;
            }
        }
    }
}

void ft_list_remove_if_2(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if_2(begin_list, data_ref, cmp);
	}
	else // if there is a no else, you cant pass the Moulinette, tryed 2023.09.08
	{
		cur = *begin_list;
		ft_list_remove_if_2(&cur->next, data_ref, cmp);
	}
}

int main()
{
    char *n1 = malloc(sizeof(char) * 2);
    n1[0] = '1';
    n1[1] = '\0';
    char *n2 = malloc(sizeof(char) * 2);
    n2[0] = '2';
    n2[1] = '\0';
    char *n3 = malloc(sizeof(char) * 2);
    n3[0] = '3';
    n3[1] = '\0';
    char *n4 = malloc(sizeof(char) * 2);
    n4[0] = '4';
    n4[1] = '\0';
    t_list *list = malloc (sizeof(size_t));
    list->data = n1;
    list->next = malloc (sizeof(size_t));
    list->next->data = n2;
    list->next->next = malloc (sizeof(size_t));
    list->next->next->data = n3;
    list->next->next->next = malloc (sizeof(size_t));
    list->next->next->next->data = n4;
    list->next->next->next->next = NULL;
    t_list *list_aux = list;
    printf("%p\n", ((char *)(list)));
    printf("%p\n", ((char *)list->next));
    printf("%p\n", ((char *)list->next->next));
    printf("%p\n", ((char *)list->next->next->next));
    printf("\n\n");
    ft_list_remove_if_2(&list, n2, &cmp);
    // printf("1- %p - %s\n", (list_aux), (char *)list_aux->data);
    // printf("2- %p - %s\n", (list_aux->next), (char *)list_aux->next->data);
    // printf("3- %p - %s\n", (list_aux->next->next), (char *)list_aux->next->next->data);
    // printf("4- %p - %s\n", (list_aux->next->next->next), (char *)list_aux->next->next->next->data);
    printf("1- %p\n", (list_aux));
    printf("2- %p\n", (list_aux->next));
    printf("3- %p\n", (list_aux->next->next));
    printf("4- %p\n", (list_aux->next->next->next));
}