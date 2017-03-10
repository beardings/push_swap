//
// Created by Mykola Ponomarov on 06.03.17.
//

#include "swap.h"

int main(int c, char **v)
{
    t_lst *list;

    list = NULL;
    if (c > 1)
        list = push_swap(c, v);
    while (list->next != NULL)
    {
        ft_printf("%d\n", list->x);
        list = list->next;
    }
    return (0);
}