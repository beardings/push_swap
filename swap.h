//
// Created by Mykola Ponomarov on 10.03.17.
//

#ifndef SWAP_H
# define SWAP_H

# include "libft/libft.h"
# include "ft_printf.h"

typedef struct      s_lst
{
    int             x;
    struct s_lst    *next;
}                   t_lst;

typedef struct s_num
{
    int mid;
    int len;
    int end;
    int start;
    int lenop;
    int first_b;
    int skira;
    int pro;
    int size;
    int newsize;
    t_lst *com;
}               t_num;

void    push_swap(int len, char **strs);
void    sa(t_lst *lst_a, t_num **num);
void    sb(t_lst *lst_b, t_num **num);
void    ss(t_lst *lst_a, t_lst *lst_b, t_num **num);
t_lst   *createlst(void);
void    pb(t_lst **lst_a, t_lst **lst_b, t_num **num);
void    pa(t_lst **lst_a, t_lst **lst_b, t_num **num);
void    rra(t_lst **lst_a, t_num **num);
void    rrb(t_lst **lst_b, t_num **num);
void    rrr(t_lst *lst_a, t_lst *lst_b, t_num **num);
void    ra(t_lst **lst_a, t_num **num);
void    rb(t_lst **lst_b, t_num **num);
void    rr(t_lst *lst_a, t_lst *lst_b, t_num **num);
t_lst   *start_sort(t_lst *lst_a, t_lst *lst_b, t_num *num);
void    putout(t_lst *lst_a, t_lst *lst_b);
void    sort_lessfor(t_lst **lst_a, int size, t_num **num);
void    sort_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size);
void    sort_a(t_lst **lst_a, t_lst **lst_b, t_num **num, int size);
int     checklstsize(t_lst **lst_b);
int     itismid_b(t_lst **lst_b, int size);
t_lst   *neednextlst(t_lst *lst, int com);
int         lenlst(t_lst **lst);

#endif
