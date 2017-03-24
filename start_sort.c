//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"

void sort_lessfor_a(t_lst **lst, int size)
{
    t_lst *tmp;

    tmp = *lst;
    if (tmp != NULL)
    {
        if (size == 2)
            tmp->x > tmp->next->x ? sa(*lst) : 0;
        if (size == 3)
        {
            if (tmp->x > tmp->next->x)
            {
                if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                    sa(*lst);
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    ra(lst);
                    sa(*lst);
                }
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                    ra(lst);
            }
            else if (tmp->x < tmp->next->x)
            {
                if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                    rra(lst);
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    sa(*lst);
                    ra(lst);
                }
            }
        }
    }
}

void sort_lessfor_b(t_lst **lst, int size)
{
    t_lst *tmp;

    tmp = *lst;
    if (tmp != NULL)
    {
        if (size == 2)
            tmp->x < tmp->next->x ? sb(*lst) : 0;
        if (size == 3)
        {
            if (tmp->x < tmp->next->x)
            {
                if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                {
                    rb(lst);
                    sb(*lst);
                }
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                    sb(*lst);
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                    rb(lst);
            }
            else if (tmp->x > tmp->next->x)
            {
                if ((tmp->x > tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                {
                    rrb(lst);
                    sb(*lst);
                }
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                    rrb(lst);
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                    rrb(lst);
            }
        }
    }
}

void sort_lessfor(t_lst **lst, int size)
{
    t_lst *tmp;

    tmp = *lst;
    if (tmp != NULL)
    {
        if (size == 1)
            tmp->x > tmp->next->x ? sa(*lst) : 0;
        if (size == 2)
            tmp->x > tmp->next->x ? sa(*lst) : 0;
        if (size == 3)
        {
            if (tmp->x > tmp->next->x)
            {
                if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                    sa(*lst);
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    ra(lst);
                    sa(*lst);
                    rra(lst);
                    sa(*lst);
                    ra(lst);
                    sa(*lst);
                    rra(lst);
                }
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                {
                    sa(*lst);
                    ra(lst);
                    sa(*lst);
                    rra(lst);
                }
            }
            else if (tmp->x < tmp->next->x)
            {
                if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    ra(lst);
                    sa(*lst);
                    rra(lst);
                    sa(*lst);
                }
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    ra(lst);
                    sa(*lst);
                    rra(lst);
                }
            }
        }
    }
}


int  begin_sort(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    t_lst *tmp;
    int wow;
    int skiko;


    skiko = 0;
    wow = size;
    tmp = *lst_a;
    while (tmp != NULL && wow > 0)
    {
        if (tmp->x < (*num)->mid)
        {
            pb(lst_a, lst_b);
            tmp = tmp->next;
            (*num)->start++;
            (*num)->lenop++;
            skiko++;
            wow--;
        }
        else
        {
            tmp = tmp->next;
            ra(lst_a);
            (*num)->skira++;
            wow--;
        }
    }
    (*num)->end = (*num)->len - (*num)->start;
    return (skiko);
}


int  findmid(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    int max;
    int min;
    t_lst *tmp;
    int i;

    i = 0;
    tmp = *lst_a;
    max = tmp->x;
    min = tmp->x;
    while (tmp != NULL &&  size > i)
    {
        if (tmp->x < min)
            min = tmp->x;
        if (tmp->x > max)
            max = tmp->x;
        tmp = tmp->next;
        i++;
    }
    (*num)->mid = (max + min) / 2;
    return (begin_sort(lst_a, lst_b, num, size));
}


void return_bina(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    while (size > 0)
    {
        pb(lst_a, lst_b);
        (*num)->lenop++;
        (*num)->end++;
        size--;
    }
}

void return_binb(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    while (size > 0)
    {
        pa(lst_a, lst_b);
        (*num)->lenop++;
        (*num)->end++;
        size--;
    }
}

void sort_a(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    int skiko = 0;

    if (size > 3)
    {
        skiko = findmid(lst_a, lst_b, num, size);
        sort_a(lst_a, lst_b, num, size - skiko);
        sort_b(lst_a, lst_b, num, skiko);
        return_binb(lst_a, lst_b, num, skiko);
    }
    else
        sort_lessfor_a(lst_a, size);
}
















/*int  begin_sort_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    t_lst *tmp;
    int wow;
    int i;
    int skiko;
    int k;

    k = 0;
    i = 0;
    skiko = 0;
    wow = size;
    tmp = *lst_b;
    while (tmp != NULL && wow > 0)
    {
        if (size > 3)
        {
            if (tmp->x > (*num)->mid)
            {
                pa(lst_a, lst_b);
                tmp = tmp->next;
                (*num)->end++;
                (*num)->start--;
                (*num)->lenop++;
                skiko++;
                wow--;
                k++;
            }
            else
            {
                tmp = tmp->next;
                rb(lst_b);
                (*num)->skira++;
                wow--;
                i++;
            }
        }
        else
        {
            pa(lst_a, lst_b);
            tmp = tmp->next;
            (*num)->end++;
            (*num)->start--;
            (*num)->lenop++;
            wow--;
        }

    }
    while (i > 0)
    {
        rrb(lst_b);
        i--;
    }
    i == 0 && k > 0 ? sort_lessfor(lst_a, size - i - k) :  sort_lessfor(lst_a, size - i);
    return (skiko);
}



int checkmid(t_num **num, t_lst **lst_b, int size)
{
    int len;
    t_lst *tmp;

    len = 0;
    tmp = *lst_b;
    while (tmp != NULL && size > 0)
    {
        if (tmp->x > (*num)->mid)
            len++;
        tmp = tmp->next;
        size--;
    }
    if (len > 3)
    {
        (*num)->first_b = (*num)->mid;
        return (1);
    }
    (*num)->pro = len;
    return (0);
}

int  findmid_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    int max;
    int min;
    t_lst *tmp;
    int i;
    int www;

    www = 0;
    if (*lst_b != NULL) {

        i = 0;

        tmp = *lst_b;
        max = tmp->x;
        min = tmp->x;
        if (size > 3) {
            while (tmp != NULL && size > i) {
                if (tmp->x < min)
                    if (tmp->x > (*num)->first_b)
                        min = tmp->x;
                if (tmp->x > max)
                    if (tmp->x > (*num)->first_b)
                        max = tmp->x;
                tmp = tmp->next;
                i++;
            }
            (*num)->mid = (max + min) / 2;
            if ((checkmid(num, lst_b, size) == 1))
                findmid_b(lst_a, lst_b, num, size);
            www = begin_sort_b(lst_a, lst_b, num, size);
            size -= www;
            (*num)->first_b = 0;
            findmid_b(lst_a, lst_b, num, size);
        } else
            www = begin_sort_b(lst_a, lst_b, num, size);
    }
    return (www);
}*/


int checkmid(t_num **num, t_lst **lst_b, int size)
{
    int len;
    t_lst *tmp;

    len = 0;
    tmp = *lst_b;
    while (tmp != NULL && size > 0)
    {
        if (tmp->x > (*num)->mid)
            len++;
        tmp = tmp->next;
        size--;
    }
    if (len > 3)
    {
        (*num)->first_b = (*num)->mid;
        return (1);
    }
    (*num)->pro = len;
    return (0);
}

int  begin_sort_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    t_lst *tmp;
    int skiko;
    int i;

    i = 0;
    skiko = 0;
    tmp = *lst_b;
    while (tmp != NULL && size > 0)
    {
        if (tmp->x >= (*num)->mid)
        {
            pa(lst_a, lst_b);
            tmp = tmp->next;
            (*num)->start++;
            (*num)->lenop++;
            skiko++;
            size--;
        }
        else
        {
            tmp = tmp->next;
            rb(lst_b);
            (*num)->skira++;
            size--;
            i++;
        }
    }
    while (i > 0)
    {
        rrb(lst_b);
        i--;
    }
    sort_lessfor(lst_a, skiko);
    return (skiko);
}


int  findmid_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    int max;
    int min;
    t_lst *tmp;
    int i;

    i = 0;
    tmp = *lst_b;
    max = tmp->x;
    min = tmp->x;
    while (tmp != NULL &&  size > i)
    {
        if (tmp->x < min)
            if (tmp->x < (*num)->first_b)
                min = tmp->x;
        if (tmp->x > max)
            if (tmp->x > (*num)->first_b)
                max = tmp->x;
        tmp = tmp->next;
        i++;
    }
    (*num)->mid = (max + min) / 2;
    if ((checkmid(num, lst_b, size) == 1))
        findmid_b(lst_a, lst_b, num, size);
    return (begin_sort_b(lst_a, lst_b, num, size));
}


void sort_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    int skiko = 0;

    if (size > 3)
    {
        skiko = findmid_b(lst_a, lst_b, num, size);
        sort_b(lst_a, lst_b, num, size - skiko);
        sort_a(lst_a, lst_b, num, skiko);
        return_bina(lst_a, lst_b, num, skiko);
    }
    else
        sort_lessfor_b(lst_b, size);
}

void start_sort(t_lst *lst_a, t_lst *lst_b, t_num *num)
{
    if (num->len > 4)
        sort_a(&lst_a, &lst_b, &num, num->len);
    else if (num->len < 4)
        sort_lessfor_a(&lst_a, num->len);
    write(1, "\n", 1);
    putout(lst_a, lst_b);
}