//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"

void ra(t_lst **lst_a, t_num **num)
{
    t_lst *tmp;
    t_lst *res;

    tmp = *lst_a;
    *lst_a = (*lst_a)->next;
    tmp->next = NULL;
    res = *lst_a;
    while (res->next != NULL)
        res = res->next;
    res->next = tmp;
    write(1, "ra\n", 3);
    (*num)->com = neednextlst((*num)->com, 1);
    (*num)->lenop++;
}

void rb(t_lst **lst_b, t_num **num)
{
    t_lst *tmp;
    t_lst *res;

    tmp = *lst_b;
    *lst_b = (*lst_b)->next;
    tmp->next = NULL;
    if (*lst_b != NULL)
    {
        res = *lst_b;
        while (res->next != NULL)
            res = res->next;
        res != NULL ? res->next = tmp : 0;
        res == NULL ? res = tmp : 0;
    }
    write(1, "rb\n", 3);
    (*num)->com = neednextlst((*num)->com, 2);
    (*num)->lenop++;
}

void rr(t_lst *lst_a, t_lst *lst_b, t_num **num)
{
    ra(&lst_a, num);
    rb(&lst_b, num);
}


void pushres(t_lst **lst, t_lst **lil)
{
    if (*lst)
        (*lil)->next = *lst;
    *lst = *lil;
}

void pb(t_lst **lst_a, t_lst **lst_b, t_num **num)
{
    t_lst *lal;

    if ((*lst_a) != NULL)
    {
        lal = createlst();
        lal->x = (*lst_a)->x;
        *lst_a = (*lst_a)->next;
        pushres(lst_b, &lal);
    }
    write(1, "pb\n", 3);
    (*num)->com = neednextlst((*num)->com, 4);
    (*num)->lenop++;
}

void pa(t_lst **lst_a, t_lst **lst_b, t_num **num)
{
    t_lst *lol;

    lol = createlst();
    lol->x = (*lst_b)->x;
    if (*lst_b != NULL)
    {
        *lst_b = (*lst_b)->next;
        pushres(lst_a, &lol);
    }
    write(1, "pa\n", 3);
    (*num)->com = neednextlst((*num)->com, 3);
    (*num)->lenop++;
}