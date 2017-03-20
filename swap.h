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
    t_lst *ost;
    t_lst *per;
}               t_num;

void    push_swap(int len, char **strs);
void    sa(t_lst *lst_a);
void    sb(t_lst *lst_b);
void    ss(t_lst *lst_a, t_lst *lst_b);
t_lst   *createlst(void);
void    pb(t_lst **lst_a, t_lst **lst_b);
void    pa(t_lst **lst_a, t_lst **lst_b);
void    rra(t_lst **lst_a);
void    rrb(t_lst **lst_b);
void    rrr(t_lst *lst_a, t_lst *lst_b);
void    ra(t_lst **lst_a);
void    rb(t_lst **lst_b);
void    rr(t_lst *lst_a, t_lst *lst_b);
void    start_sort(t_lst *lst_a, t_lst *lst_b, t_num *num);
void    putout(t_lst *lst_a, t_lst *lst_b);
void    sort_lessfor(t_lst **lst_a);

#endif
