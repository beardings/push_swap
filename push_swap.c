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
        if (tmp->x == 1)
            printf("\ncl: %s", "ra");
        else if (tmp->x == 2)
            printf("\ncl: %s", "rb");
        else if (tmp->x == 3)
            printf("\ncl: %s", "pa");
        else if (tmp->x == 4)
            printf("\ncl: %s", "pb");
        else if (tmp->x == 5)
            printf("\ncl: %s", "sa");
        else if (tmp->x == 6)
            printf("\ncl: %s", "sb");
        else if (tmp->x == 7)
            printf("\ncl: %s", "rra");
        else if (tmp->x == 8)
            printf("\ncl: %s", "rrb");
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

void lstdelone(t_lst **lst)
{
    t_lst *a;

    a = (*lst)->next->next;
    (*lst)->next->next = (*lst)->next->next->next;
    free(a);
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
        else if ((lst->next->x == 2 && lst->next->next->x == 8) || (lst->next->x == 8 && lst->next->next->x == 2))
        {
            lstdel(&lst);
            k += 2;
        }
        else if ((lst->next->x == 3 && lst->next->next->x == 4) || (lst->next->x == 4 && lst->next->next->x == 3))
        {
            lstdel(&lst);
            k += 2;
        }
        else if ((lst->next->x == 5 && lst->next->next->x == 6) || (lst->next->x == 6 && lst->next->next->x == 5))
        {
            lstdel(&lst);
            k += 2;
        }
        else if (lst->next->x == 5 && lst->next->next->x == 5)
        {
            lstdelone(&lst);
            k++;
        }
        else if (lst->next->x == 6 && lst->next->next->x == 6)
        {
            lstdelone(&lst);
            k++;
        }
        lst = lst->next;
    }
    if (k > 0)
        cleanlist(head);
    return (*head);
}

void checkitsort(t_lst **lst_a)
{
    t_lst *tmp;

    tmp = *lst_a;
    while (tmp->next != NULL)
    {
        if (tmp->x < tmp->next->x)
            tmp = tmp->next;
        else
        {
            printf("\n\nsad: KO");
            printf("\n %d", tmp->x);
            printf("\n %d", tmp->next->x);
            break ;
        }
    }
    if (tmp->next == NULL)
        printf("\n\nit is sort: OK");
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
    lst_a = start_sort(lst_a, lst_b, num);
    num->com =  cleanlist(&(num->com));
    checkitsort(&lst_a);
    printf("\nskiko: %d\n", num->lenop);
    printf("\n\nlstlen: %d", lenlst(&(num->com)));
}