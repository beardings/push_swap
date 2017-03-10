//
// Created by Mykola Ponomarov on 10.03.17.
//

#include "swap.h"

t_lst *inlst(char *str, t_lst *list)
{
    if (str == '\0')
    {
        list = NULL;
        return (list);
    }
    list->x = ft_atoi(str);
    return (list);
}

t_lst *createlst(void)
{
    t_lst *list;

    list = (t_lst *)malloc(sizeof(t_lst));
    list->x = '\0';
    list->next = NULL;
    return (list);
}

t_lst *push_swap(int len, char **strs)
{
    t_lst *lst_a;
    t_lst *lst_b;
    t_lst *head_a;
    t_lst *head_b;
    int i;

    i = 1;
    lst_b = createlst();
    lst_a = createlst();
    head_a = lst_a;
    while (i <= len)
    {
        inlst(strs[i], lst_a);
        lst_a->next = createlst();
        lst_a = lst_a->next;
        i++;
    }
    return (head_a);
}