//
// Created by Mykola Ponomarov on 10.03.17.
//

#include "swap.h"

int checklstsize(t_lst **lst_b)
{
    t_lst *tmp;
    int i;

    i = 0;
    tmp = *lst_b;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

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
    num->first_b = 0;
    num->lenop = 0;
    num->skira = 0;
    num->pro = 0;
    num->size = 0;
    num->newsize = 0;
    num->com = createlst();
    return (num);
}

t_lst *neednextlst(t_lst *lst, int com)
{
    t_lst *head;

    head = lst;
    while (lst->next != NULL)
        lst = lst->next;
    lst->x = com;
    lst->next = createlst();
    lst = head;
    return (lst);
}

int lenlst(t_lst **lst)
{
    int i;
    t_lst *tmp;

    tmp = *lst;
    i = 0;
    while (tmp->next != NULL)
    {
        printf("\ncl: %d", tmp->x);
        i++;
        tmp = tmp->next;
    }
    return (i);
}


void lstdel(t_lst **lst)
{
    t_lst *a;
    t_lst *b;

    a = (*lst)->next->next;
    b = (*lst)->next;
    (*lst)->next = (*lst)->next->next->next;
    free(a);
    free(b);
}

t_lst *cleanlist(t_lst **head)
{
    t_lst *lst;
    int k;

    k = 0;
    lst = *head;
    while (lst->next != NULL)
    {
        if ((lst->next->x == 1 && lst->next->next->x == 7) || (lst->next->x == 7 && lst->next->next->x == 1))
        {
            lstdel(&lst);
            k += 2;
        }
        if ((lst->next->x == 2 && lst->next->next->x == 8) || (lst->next->x == 8 && lst->next->next->x == 2))
        {
            lstdel(&lst);
            k += 2;
        }
        if ((lst->next->x == 3 && lst->next->next->x == 4) || (lst->next->x == 4 && lst->next->next->x == 3))
        {
            lstdel(&lst);
            k += 2;
        }
        if ((lst->next->x == 5 && lst->next->next->x == 6) || (lst->next->x == 6 && lst->next->next->x == 5))
        {
            lstdel(&lst);
            k += 2;
        }
        lst = lst->next;
    }
    if (k > 0)
        cleanlist(head);
    return (*head);
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
    num->com =  cleanlist(&(num->com));
    printf("\n\nskiko: %d", num->lenop);
    printf("\n\nlstlen: %d", lenlst(&(num->com)));
}