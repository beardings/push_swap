//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"

void ra(t_lst **lst_a, t_num **num, int i)
{
    t_lst *tmp;
    t_lst *res;

    tmp = *lst_a;
    if (*lst_a != NULL)
    {
        *lst_a = (*lst_a)->next;
        tmp->next = NULL;
        res = *lst_a;
        if (res != NULL)
        {
            while (res->next != NULL)
                res = res->next;
            res->next = tmp;
            i == 1 ? (*num)->com = neednextlst((*num)->com, 1) : 0;
            i == 1 ? (*num)->lenop++ : 0;
        }
        //write(1, "ra\n", 3);
    }
}

void rb(t_lst **lst_b, t_num **num, int i)
{
    t_lst *tmp;
    t_lst *res;

    tmp = *lst_b;
    if (*lst_b != NULL)
    {
        *lst_b = (*lst_b)->next;
        tmp->next = NULL;
        res = *lst_b;
        if (res != NULL)
        {
            while (res->next != NULL)
                res = res->next;
            res != NULL ? res->next = tmp : 0;
            res == NULL ? res = tmp : 0;
            i == 1 ? (*num)->com = neednextlst((*num)->com, 2) : 0;
            i == 1 ? (*num)->lenop++ : 0;
        }
    }
    //write(1, "rb\n", 3);
}

void rr(t_lst *lst_a, t_lst *lst_b, t_num **num, int i)
{
    ra(&lst_a, num, i);
    rb(&lst_b, num, i);
}


void pushres(t_lst **lst, t_lst **lil)
{
    if (*lst)
        (*lil)->next = *lst;
    *lst = *lil;
}

void pb(t_lst **lst_a, t_lst **lst_b, t_num **num, int i)
{
    t_lst *lal;

    if ((*lst_a) != NULL)
    {
        lal = createlst();
        lal->x = (*lst_a)->x;
        *lst_a = (*lst_a)->next;
        pushres(lst_b, &lal);
        i == 1 ? (*num)->com = neednextlst((*num)->com, 4) : 0;
        i == 1 ? (*num)->lenop++ : 0;
    }
    //write(1, "pb\n", 3);
}

void pa(t_lst **lst_a, t_lst **lst_b, t_num **num, int i)
{
    t_lst *lol;

    if (*lst_b != NULL)
    {
        lol = createlst();
        lol->x = (*lst_b)->x;

        *lst_b = (*lst_b)->next;
        pushres(lst_a, &lol);
        i == 1 ? (*num)->com = neednextlst((*num)->com, 3) : 0;
        i == 1 ? (*num)->lenop++ : 0;
    }
    //write(1, "pa\n", 3);
}