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

void putout(t_lst **lst_a, t_lst **lst_b)
{
    t_lst *lst_aa;
    t_lst *lst_bb;

    lst_aa = *lst_a;
    lst_bb = *lst_b;
    while (lst_aa != NULL || lst_bb != NULL)
    {
        lst_aa != NULL ? printf("%d", lst_aa->x) : printf("  ");
        lst_bb != NULL ? printf("    %d", lst_bb->x) : 0;
        lst_bb != NULL ? lst_bb = lst_bb->next : 0;
        lst_aa != NULL ? lst_aa = lst_aa->next : 0;
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
            printf("\n%s", "ra");
        else if (tmp->x == 2)
            printf("\n%s", "rb");
        else if (tmp->x == 3)
            printf("\n%s", "pa");
        else if (tmp->x == 4)
            printf("\n%s", "pb");
        else if (tmp->x == 5)
            printf("\n%s", "sa");
        else if (tmp->x == 6)
            printf("\n%s", "sb");
        else if (tmp->x == 7)
            printf("\n%s", "rra");
        else if (tmp->x == 8)
            printf("\n%s", "rrb");
        else if (tmp->x == 9)
            printf("\n%s", "rr");
        else if (tmp->x == 10)
            printf("\n%s", "ss");
        else if (tmp->x == 9)
            printf("\n%s", "rrr");
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


t_lst *enotherclean(t_lst **lst)
{
    t_lst *wow;
    int k;

    wow = *lst;
    k = 0;
    while (wow->next != NULL)
    {
        if ((wow->next->x == 1 && wow->next->next->x == 2) || (wow->next->x == 2 && wow->next->next->x == 1))
        {
            lstdelone(&wow);
            wow->next->x = 9;
            k++;
        }
        else if ((wow->next->x == 5 && wow->next->next->x == 6) || (wow->next->x == 6 && wow->next->next->x == 5))
        {
            lstdelone(&wow);
            wow->next->x = 10;
            k++;
        }
        else if ((wow->next->x == 7 && wow->next->next->x == 8) || (wow->next->x == 8 && wow->next->next->x == 7))
        {
            lstdelone(&wow);
            wow->next->x = 11;
            k++;
        }
        wow = wow->next;
    }
    if (k > 0)
        enotherclean(lst);
    return (*lst);
}

t_lst *cleanlistnext(t_lst **lst)
{
    t_lst *wow;
    int k;

    wow = *lst;
    k = 0;
    while (wow->next->next->next != NULL)
    {
        if (wow->next->x == 1 && wow->next->next->x == 4 && wow->next->next->next->x == 7)
        {
            lstdelone(&wow);
            wow->next->x = 5;
            wow->next->next->x = 4;
            k++;
        }
        else if (wow->next->x == 7 && wow->next->next->x == 5 && wow->next->next->next->x == 4)
        {
            lstdelone(&wow);
            wow->next->x = 4;
            wow->next->next->x = 7;
            k++;
        }
        else if (wow->next->x == 5 && wow->next->next->x == 1 && wow->next->next->next->x == 4)
        {
            lstdelone(&wow);
            wow->next->x = 4;
            wow->next->next->x = 1;
            k++;

        }
        else if (wow->next->x == 2 && wow->next->next->x == 3 && wow->next->next->next->x == 8)
        {
            lstdelone(&wow);
            wow->next->x = 6;
            wow->next->next->x = 3;
            k++;
        }
        else if (wow->next->x == 8 && wow->next->next->x == 6 && wow->next->next->next->x == 3)
        {
            lstdelone(&wow);
            wow->next->x = 3;
            wow->next->next->x = 8;
            k++;
        }
        else if (wow->next->x == 6 && wow->next->next->x == 2 && wow->next->next->next->x == 3)
        {
            lstdelone(&wow);
            wow->next->x = 3;
            wow->next->next->x = 2;
            k++;

        }
        wow = wow->next;
    }
    if (k > 0)
        cleanlistnext(lst);
    return (*lst);
}

void checkitsort(t_lst **lst_a)
{
    t_lst *tmp;

    if (*lst_a != NULL) {

        tmp = *lst_a;
        while (tmp->next != NULL) {
            if (tmp->x < tmp->next->x)
                tmp = tmp->next;
            else {
                printf("\n\nsad: KO");
                printf("\n %d", tmp->x);
                printf("\n %d", tmp->next->x);
                break;
            }
        }
        if (tmp->next == NULL)
            printf("\n\nit is sort: OK");
    }
}

void checknew(t_lst **lst_a, t_lst **lst_b, t_lst **head, t_num **num)
{
    t_lst *wow;
    int i;

    i = 0;
    wow = *head;
    while (wow != NULL)
    {
        if (wow->x == 1)
            ra(lst_a, num, 2);
        else if (wow->x == 2)
            rb(lst_b, num, 2);
        else if (wow->x == 3)
            pa(lst_a, lst_b, num, 2);
        else if (wow->x == 4)
            pb(lst_a, lst_b, num, 2);
        else if (wow->x == 5)
            sa(*lst_a, num, 2);
        else if (wow->x == 6)
            sb(*lst_b, num, 2);
        else if (wow->x == 7)
            rra(lst_a, num, 2);
        else if (wow->x == 8)
            rrb(lst_b, num, 2);
        else if (wow->x == 9)
            rr(*lst_a, *lst_b, num, 2);
        else if (wow->x == 10)
            ss(*lst_a, *lst_b, num, 2);
        else if (wow->x == 11)
            rrr(lst_a, lst_b, num, 2);
        wow = wow->next;
        i++;
    }
    (*num)->lenop = i;
}

void checker(t_num *num, t_lst *head, char **strs, int len)
{
    t_lst *lst_a;
    t_lst *lst_b;
    t_lst *wow;
    int i;

    i = 1;
    lst_b = NULL;
    lst_a = createlst();
    inlst(strs[i], lst_a);
    i++;
    wow = lst_a;
    while (i < len)
    {
        lst_a->next = createlst();
        inlst(strs[i], lst_a->next);
        lst_a = lst_a->next;
        i++;
    }
    lst_a = wow;
    checknew(&lst_a, &lst_b, &head, &num);
    write(1, "\n", 1);
    free(lst_b);
    lst_b = NULL;
    putout(&lst_a, &lst_b);
    checkitsort(&lst_a);
    printf("\nskiko2: %d\n", num->lenop - 1);
    free(lst_a);
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
    head = num->com;
    checker(num, head, strs, len);
    free(lst_a);
    free(num);
}