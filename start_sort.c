//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"

void findmid(t_lst **lst_a, t_num *num)
{
    int max;
    int min;
    t_lst *tmp;

    tmp = *lst_a;
    max = tmp->x;
    min = tmp->x;
    while (tmp != NULL)
    {
        if (tmp->x < min)
            min = tmp->x;
        if (tmp->x > max)
            max = tmp->x;
        tmp = tmp->next;
    }
    num->mid = (min + max)/2;
}

void begin_sort(t_lst **lst_a, t_lst **lst_b, t_num *num)
{
    t_lst *tmp;

    tmp = *lst_a;
    while (tmp != NULL)
    {
        if (tmp->x <= num->mid)
        {
            pb(lst_a, lst_b);
            tmp = tmp->next;
            num->start++;
            num->lenop++;
        }
        else // нужно так переписать ра что бы не использовать его ещё раз
        {
            pb(lst_a, &num->ost);
            tmp = tmp->next;
            num->lenop++;
        }
    }
    *lst_a = num->ost;
    num->ost = NULL;
    num->end = num->len - num->start;
}

void sort_lessfor_a(t_lst **lst, t_num *num)
{
    t_lst *tmp;
    int len;

    len = num->len - num->start;
    tmp = *lst;
    if (tmp != NULL)
    {
        if (len == 2)
            tmp->x > tmp->next->x ? sa(*lst) : 0;
        if (len == 3)
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

void sort_lessfor_b(t_lst **lst, t_num *num)
{
    t_lst *tmp;
    int len;

    len = num->len - (num->start + num->end);
    tmp = *lst;
    if (tmp != NULL)
    {
        if (len == 2)
            tmp->x < tmp->next->x ? sb(*lst) : 0;
        if (len == 3)
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

int checkmid(t_num *num, t_lst **lst_b)
{
    int len;
    t_lst *tmp;

    len = 0;
    tmp = *lst_b;
    while (tmp != NULL)
    {
        if (tmp->x > num->mid)
            len++;
        tmp = tmp->next;
    }
    if (len == 3)
        return (1);
    else
    {
        num->mid -= 1;
        checkmid(num, lst_b);
    }
    return (0);
}

void return_bina(t_lst **lst_a, t_lst **lst_b, t_num *num)
{
    while (*lst_b != NULL)
    {
        pa(lst_a, lst_b);
        num->lenop++;
        num->end++;
    }
}

void end_sort(t_lst **lst_a, t_lst **lst_b, t_num *num)
{
    t_lst *tmp;

    tmp = *lst_b;
    while (tmp != NULL)
    {
        if (tmp->x > num->mid)
        {
            pb(lst_b, &num->per);
            tmp = tmp->next;
            num->start--;
            num->lenop++;
        }
        else // нужно так переписать что бы не перезаписывать мои данные в отдельную функцию
        {
            pb(lst_b, &num->ost);
            tmp = tmp->next;
            num->lenop++;
        }
    }
    sort_lessfor_b(&num->per, num);
    return_bina(lst_a, &num->per, num);
    *lst_b = num->ost;
    num->ost = NULL;
    num->per = NULL;
    num->end = num->len - num->start;
}

void start_sort(t_lst *lst_a, t_lst *lst_b, t_num *num)
{
    if (num->len > 4)
    {
        findmid(&lst_a, num);
        begin_sort(&lst_a, &lst_b, num);
        while (num->end > 3)
        {
            findmid(&lst_a, num);
            begin_sort(&lst_a, &lst_b, num);
        }
        if (num->end < 4)
            sort_lessfor_a(&lst_a, num);
        while (num->start > 3)
        {
            if ((checkmid(num, &lst_b)) == 1)
                end_sort(&lst_a, &lst_b, num);
        }
        num->start -= num->start;
        sort_lessfor_b(&lst_b, num);
        return_bina(&lst_a, &lst_b, num);
    }
    else if (num->len < 4)
        sort_lessfor_a(&lst_a, num);
    write(1, "\n", 1);
    putout(lst_a, lst_b);
}