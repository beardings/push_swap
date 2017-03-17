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
        }
        else // нужно так переписать ра что бы не использовать его ещё раз
        {
            pb(lst_a, &num->ost);
            tmp = tmp->next;
        }
    }
    *lst_a = num->ost;
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

    len = num->len - num->start;
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
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
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

            }
        }
    }
}

void return_bina(t_lst **lst_a, t_lst **lst_b)
{
    while (*lst_b != NULL)
        pa(lst_a, lst_b);
}

void start_sort(t_lst *lst_a, t_lst *lst_b, t_num *num)
{
    if (num->len > 4) // рекурсию можно замутить как раз таки через вайл
    {
        findmid(&lst_a, num);
        begin_sort(&lst_a, &lst_b, num);
        if (num->end > 3)
        {

        }
        else if (num->end < 4)
            sort_lessfor_a(&lst_a, num); // если нам не меньше 4 то я доолжен  увеличить медиану
        if (num->start > 3)
        {

        }
        else if (num->start < 4)
            sort_lessfor_b(&lst_b, num);
    }
    else if (num->len < 4)
        sort_lessfor_a(&lst_a, num);
    if (num->len > 4)
        return_bina(&lst_a, &lst_b);
    write(1, "\n", 1);
    putout(lst_a, lst_b);
}