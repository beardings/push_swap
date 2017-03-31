//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"

void sa(t_lst *lst_a, t_num **num)
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
    (*num)->com = neednextlst((*num)->com, 5);
    (*num)->lenop++;
}

void sb(t_lst *lst_b, t_num **num)
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
    (*num)->com = neednextlst((*num)->com, 6);
    (*num)->lenop++;
}

void ss(t_lst *lst_a, t_lst *lst_b, t_num **num)
{
    sa(lst_a, num);
    sb(lst_b, num);
}