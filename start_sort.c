//
// Created by Mykola Ponomarov on 14.03.17.
//

#include "swap.h"

void sort_lessfor_a(t_lst **lst, int size, t_num **num)
{
    t_lst *tmp;

    tmp = *lst;
    if (tmp != NULL)
    {
        if (size == 2)
        {
            if (tmp->x > tmp->next->x)
                sa(*lst, num);
        }
        if (size == 3)
        {
            if (tmp->x > tmp->next->x)
            {
                if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                    sa(*lst, num);
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    ra(lst, num);
                    sa(*lst, num);
                }
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                    ra(lst, num);
            }
            else if (tmp->x < tmp->next->x)
            {
                if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                    rra(lst, num);
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    sa(*lst, num);
                    ra(lst, num);
                }
            }
        }
    }
}

void sort_lessfor_b(t_lst **lst, int size, t_num **num)
{
    t_lst *tmp;

    tmp = *lst;
    if (tmp != NULL)
    {
        if (size == 2)
        {
            if (tmp->x < tmp->next->x)
                sb(*lst, num);
        }
        if (size == 3)
        {
            if (tmp->x < tmp->next->x)
            {
                if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                {
                    rb(lst, num);
                    sb(*lst, num);
                    rrb(lst, num);
                    sb(*lst, num);
                    rb(lst, num);
                    sb(*lst, num);
                    rrb(lst, num);
                }
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    sb(*lst, num);
                }
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    sb(*lst, num);
                    rb(lst, num);
                    sb(*lst, num);
                    rrb(lst, num);
                }
            }
            else if (tmp->x > tmp->next->x)
            {
                if ((tmp->x > tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                {
                    rb(lst, num);
                    sb(*lst, num);
                    rrb(lst, num);
                }
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                    rrb(lst, num);
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                {
                    rb(lst, num);
                    sb(*lst, num);
                    rrb(lst, num);
                    sb(*lst, num);
                }
            }
        }
    }
}

void sort_lessfor(t_lst **lst, int size, t_num **num)
{
    t_lst *tmp;

    tmp = *lst;
    if (tmp != NULL)
    {
        if (size == 1)
            tmp->x > tmp->next->x ? sa(*lst, num) : 0;
        if (size == 2)
            tmp->x > tmp->next->x ? sa(*lst, num) : 0;
        if (size == 3)
        {
            if (tmp->x > tmp->next->x)
            {
                if ((tmp->x < tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                    sa(*lst, num);
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    ra(lst, num);
                    sa(*lst, num);
                    rra(lst, num);
                    sa(*lst, num);
                    ra(lst, num);
                    sa(*lst, num);
                    rra(lst, num);
                }
                else if ((tmp->x > tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
                {
                    sa(*lst, num);
                    ra(lst, num);
                    sa(*lst, num);
                    rra(lst, num);
                }
            }
            else if (tmp->x < tmp->next->x)
            {
                if ((tmp->x > tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    ra(lst, num);
                    sa(*lst, num);
                    rra(lst, num);
                    sa(*lst, num);
                }
                else if ((tmp->x < tmp->next->next->x) && (tmp->next->x > tmp->next->next->x))
                {
                    ra(lst, num);
                    sa(*lst, num);
                    rra(lst, num);
                }
            }
        }
    }
}

int checkkol(t_lst **lst_a, t_num **num)
{
    int i;
    t_lst *tmp;

    i = 0;
    tmp = *lst_a;
    while (tmp != NULL)
    {
        if (tmp->x < (*num)->mid)
            i++;
        tmp = tmp->next;
    }
    return (i);
}

int  begin_sort(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
/*    t_lst *tmp;
    int wow;
    int skiko;
    int i;
    int k;

    k = 0;
    i = 0;
    wow = checkkol(lst_a, num);
    skiko = wow;
    tmp = *lst_a;
    while (tmp != NULL && wow > 0)
    {
        if (tmp->x < (*num)->mid)
        {
            pb(lst_a, lst_b, num);
            tmp = tmp->next;
            (*num)->start++;
            wow--;
        }
        else
        {
            tmp = tmp->next;
            ra(lst_a, num);
            i++;
        }
        k++;
    }
    size = size - k;
    if (size < i && i > 2 && size > 1)
    {
        while (size > 0)
        {
            ra(lst_a, num);
            size--;
        }
    }
    else if (size >= i || size < 2)
    {
        while (i > 0)
        {
            rra(lst_a, num);
            i--;
        }
    }*/
    t_lst *tmp;
    int wow;
    int skiko;
    int i;


    i = 0;
    skiko = 0;
    wow = size;
    tmp = *lst_a;
    while (tmp != NULL && wow > 0)
    {
        if (tmp->x < (*num)->mid)
        {
            pb(lst_a, lst_b, num);
            tmp = tmp->next;
            (*num)->start++;
            skiko++;
            wow--;
        }
        else
        {
            tmp = tmp->next;
            ra(lst_a, num);
            wow--;
            i++;
        }
    }
    while (i > 0)
    {
        rra(lst_a, num);
        i--;
    }
    (*num)->end = (*num)->len - (*num)->start;
    return (skiko);
}

void	sort_int_tab(int *tab, int size)
{
    int	i;
    int	k;
    int	res;

    i = 0;
    k = 0;
    while (i < size)
    {
        while (k < size)
        {
            if (tab[i] < tab[k])
            {
                res = tab[i];
                tab[i] = tab[k];
                tab[k] = res;
            }
            k++;
        }
        k = 0;
        i++;
    }
}

int itismid(t_lst **lst_a, int size)
{
    int *num;
    int k;
    t_lst *tmp;
    int res;

    k = 0;
    tmp = *lst_a;
    num = (int *)malloc(sizeof(int) * size + 1);
    ft_bzero(num, (size_t)size + 1);
    while (k < size && tmp != NULL)
    {
        num[k] = tmp->x;
        tmp = tmp->next;
        k++;
    }
    sort_int_tab(num, size);
    k = size / 2;
    res = num[k];
    free(num);
    return (res);
}

int  findmid(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    (*num)->mid = itismid(lst_a, size);
    return (begin_sort(lst_a, lst_b, num, size));
}


void return_bina(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    while (size > 0)
    {
        pb(lst_a, lst_b, num);
        (*num)->end++;
        size--;
    }
}

void return_binb(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    while (size > 0)
    {
        pa(lst_a, lst_b, num);
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
        sort_lessfor(lst_a, size, num);
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
            pa(lst_a, lst_b, num);
            tmp = tmp->next;
            (*num)->start++;
            skiko++;
            size--;
        }
        else
        {
            tmp = tmp->next;
            rb(lst_b, num);
            size--;
            i++;
        }
    }
    while (i > 0)
    {
        rrb(lst_b, num);
        i--;
    }
    sort_lessfor(lst_a, skiko, num);
    return (skiko);
}



void  findmid_b_n(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    size  = size / 2;
    (*num)->mid = itismid_b(lst_b, size);
    if ((checkmid(num, lst_b, size) == 1))
        findmid_b_n(lst_a, lst_b, num, size);
    (*num)->first_b = 0;
}


int itismid_b(t_lst **lst_b, int size)
{
    int *num;
    int k;
    t_lst *tmp;
    int res;

    k = 0;
    tmp = *lst_b;
    num = (int *)malloc(sizeof(int) * size + 1);
    ft_bzero(num, (size_t)size + 1);
    while (k < size && tmp != NULL)
    {
        num[k] = tmp->x;
        tmp = tmp->next;
        k++;
    }
    sort_int_tab(num, size);
    k = size / 2;
    res = num[k];
    free(num);
    return (res);
}


int  findmid_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size)
{
    (*num)->mid = itismid_b(lst_b, size);
    if ((checkmid(num, lst_b, size) == 1))
        findmid_b_n(lst_a, lst_b, num, size);
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
        sort_lessfor_b(lst_b, size, num);
}

t_lst *start_sort(t_lst *lst_a, t_lst *lst_b, t_num *num)
{
    if (num->len > 4)
        sort_a(&lst_a, &lst_b, &num, num->len);
    else if (num->len < 4)
        sort_lessfor_a(&lst_a, num->len, &num);
    write(1, "\n", 1);
    putout(lst_a, lst_b);
    return (lst_a);
}

