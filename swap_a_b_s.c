//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"

void sa(t_lst *lst_a)
{
    t_lst *tmp;
    t_lst swap;

    tmp = lst_a;
    if (tmp->next)
    {
        swap.x = lst_a->x;
        tmp = tmp->next;
        lst_a->x = tmp->x;
        tmp->x = swap.x;
    }
    write(1, "sa\n", 3);
}

void sb(t_lst *lst_b)
{
    t_lst *tmp;
    t_lst swap;

    tmp = lst_b;
    if (tmp->next)
    {
        swap.x = lst_b->x;
        tmp = tmp->next;
        lst_b->x = tmp->x;
        tmp->x = swap.x;
    }
    write(1, "sb\n", 3);
}

void ss(t_lst *lst_a, t_lst *lst_b)
{
    sa(lst_a);
    sb(lst_b);
}