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

void    push_swap(int len, char **strs);
#endif
