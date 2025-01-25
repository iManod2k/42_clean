#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{

    t_list *lst_aux = lst;
    int aux = 0;

    while (lst_aux)
    {
        if (lst_aux->next && (ascending(lst_aux->data, lst_aux->next->data) == 0))
        {
            aux = lst_aux->data;
            lst_aux->data = lst_aux->next->data;
            lst_aux->next->data = aux;
            lst_aux = lst;
        }
        else
            lst_aux = lst_aux->next;
    }
    return (lst);
}
/*
int main(void)
{
    t_list *nums;

    nums = malloc(sizeof(t_list));
    nums->data = 3;
    nums->next = malloc(sizeof(t_list));
    nums->next->data = 2;
    nums->next->next = malloc(sizeof(t_list));
    nums->next->next->data = 1;

    sort_list(nums, &ascending);

    printf("%d", nums->data);
    printf("%d", nums->next->data);
    printf("%d", nums->next->next->data);
    return (0);
}*/