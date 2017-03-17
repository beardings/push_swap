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

void putout(t_lst *lst_a, t_lst *lst_b)
{
    while (lst_a != NULL || lst_b != NULL)
    {
        lst_a != NULL ? printf("%d", lst_a->x) : printf("  ");
        lst_b != NULL ? printf("    %d", lst_b->x) : 0;
        lst_b != NULL ? lst_b = lst_b->next : 0;
        lst_a != NULL ? lst_a = lst_a->next : 0;
        printf("\n");
    }
    printf("__   __\n");
    printf(" a    b");

}

t_num *createnum(int len)
{
    t_num *num;

    num = (t_num *)malloc(sizeof(t_num));
    num->mid = 0;
    num->len = len - 1;
    num->start = 0;
    num->end = 0;
    num->ost = NULL;
    return (num);
}

void push_swap(int len, char **strs)
{
    t_lst *lst_a;
    t_lst *lst_b;
    t_lst *head;
    t_num *num;
    int i;

    num = createnum(len);
    i = 1;
    lst_b = NULL;
    lst_a = createlst();
    inlst(strs[i], lst_a);
    i++;
    head = lst_a;
    while (i < len)
    {
        lst_a->next = createlst();
        inlst(strs[i], lst_a->next);
        lst_a = lst_a->next;
        i++;
    }
    lst_a = head;
    start_sort(lst_a, lst_b, num);
}