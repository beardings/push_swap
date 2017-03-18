//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"


/*void pb(t_lst **lst_a, t_lst **lst_b)
{
    t_lst *tmp;
    t_lst *push;

    push = createlst();
    tmp = *lst_a;
    if (*lst_a != NULL)
    {
        push->x = tmp->x;
        tmp = tmp->next;
        *lst_a = tmp;
        push->next = *lst_b;
        *lst_b = push;
    }
    write(1, "pb\n", 3);
}

void pa(t_lst **lst_a, t_lst **lst_b)
{
    t_lst *tmp;
    t_lst *push;

    push = createlst();
    tmp = *lst_b;
    if (*lst_b != NULL)
    {
        push->x = tmp->x;
        tmp = tmp->next;
        *lst_b = tmp;
        push->next = *lst_a;
        *lst_a = push;
    }
    write(1, "pa\n", 3);
}*/

void ra(t_lst **lst_a)
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
    //write(1, "ra\n", 3);
}

void rb(t_lst **lst_b)
{
    t_lst *tmp;
    t_lst *res;

    tmp = *lst_b;
    *lst_b = (*lst_b)->next;
    tmp->next = NULL;
    res = *lst_b;
    while (res->next != NULL)
        res = res->next;
    res->next = tmp;
    //write(1, "rb\n", 3);
}

void rr(t_lst *lst_a, t_lst *lst_b)
{
    ra(&lst_a);
    rb(&lst_b);
}


void pushres(t_lst **lst, t_lst **lil)
{
    if (*lst)
        (*lil)->next = *lst;
    *lst = *lil;
}

void pb(t_lst **lst_a, t_lst **lst_b)
{
    t_lst *lal;

    lal = createlst();
    lal->x = (*lst_a)->x;
    if ((*lst_a) != NULL)
    {
        *lst_a = (*lst_a)->next;
        pushres(lst_b, &lal);
    }
    //write(1, "pb\n", 3);
}

void pa(t_lst **lst_a, t_lst **lst_b)
{
    t_lst *lol;

    lol = createlst();
    lol->x = (*lst_b)->x;
    if (*lst_b != NULL)
    {
        *lst_b = (*lst_b)->next;
        pushres(lst_a, &lol);
    }
    //write(1, "pa\n", 3);
}