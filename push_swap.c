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
    list->x = 0;
    list->next = NULL;
    return (list);
}

void push_swap(int len, char **strs)
{
    t_lst *lst_a;
    t_lst *head;
    int i;

    i = 1;
    lst_a = createlst();
    inlst(strs[i], lst_a);
    i++;
    while (i < len)
    {
        head = createlst();
        inlst(strs[i], head);
        head->next = lst_a;
        lst_a = head;
        i++;
    }
    i = 1;
    printf("list A");
    while (lst_a != NULL)
    {
        printf("\n     %d", lst_a->x);
        lst_a = lst_a->next;
        i++;
    }
}