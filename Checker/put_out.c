/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:56:25 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 17:57:58 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		put_outnew(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*lst_aa;
	t_lst	*lst_bb;

	lst_aa = *lst_a;
	lst_bb = *lst_b;
	while (lst_aa != NULL || lst_bb != NULL)
	{
		if (lst_aa != NULL)
			ft_printf("\033[0;35m%d\033[0m", lst_aa->x);
		else
			ft_printf("  ");
		lst_bb != NULL ? ft_printf("     \033[0;36m%d\033[0m", lst_bb->x) : 0;
		lst_bb != NULL ? lst_bb = lst_bb->next : 0;
		lst_aa != NULL ? lst_aa = lst_aa->next : 0;
		ft_printf("\n");
	}
	ft_printf("\033[0;35m___\033[0m   \033[0;36m___\033[0m\n");
	ft_printf(" \033[0;35m%c\033[0m     \033[0;36m%c\033[0m\n", 'a', 'b');
}

void		put_out(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*lst_aa;
	t_lst	*lst_bb;

	lst_aa = *lst_a;
	lst_bb = *lst_b;
	while (lst_aa != NULL || lst_bb != NULL)
	{
		lst_aa != NULL ? ft_printf("%d", lst_aa->x) : ft_printf("  ");
		lst_bb != NULL ? ft_printf("    %d", lst_bb->x) : 0;
		lst_bb != NULL ? lst_bb = lst_bb->next : 0;
		lst_aa != NULL ? lst_aa = lst_aa->next : 0;
		ft_printf("\n");
	}
	ft_printf("___   ___\n");
	ft_printf(" a     b\n");
}
