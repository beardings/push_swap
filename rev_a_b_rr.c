//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"

void rra(t_lst **lst_a)
{
    t_lst *tmp;
    t_lst *res;

    if (*lst_a != NULL && (checklstsize(lst_a) > 1))
    {
        tmp = *lst_a;
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        res = tmp;
        res = res->next;
        tmp->next = NULL;
        res->next = *lst_a;
        *lst_a = res;
    }
    write(1, "rra\n", 4);
}

void rrb(t_lst **lst_b)
{
    t_lst *tmp;
    t_lst *res;

    if (*lst_b != NULL && (checklstsize(lst_b) > 1))
    {
        tmp = *lst_b;
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        res = tmp;
        res = res->next;
        tmp->next = NULL;
        res->next = *lst_b;
        *lst_b = res;
    }
    write(1, "rrb\n", 4);
}

void rrr(t_lst *lst_a, t_lst *lst_b)
{
    rra(&lst_a);
    rrb(&lst_b);
}