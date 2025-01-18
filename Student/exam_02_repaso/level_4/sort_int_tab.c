#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int i = 0;
    int temp = 0;

    while (i < size)
    {
        if (tab[i] > tab[i+1])
        {
            temp = tab[i];
            tab[i] = tab[i+1];
            tab[i+1] = temp;
            i = 0;
            printf("X");
        }
        else
            i++;

    }
}

int main(void)
{
    int size = 5;
    int nums[] = {2, 4, 5, 1, 2};
    int i = 0;

    sort_int_tab(nums, 5);

    while (i < size)
    {
        printf("%d\n", nums[i]);
        i++;
    }
}