/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fnk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:36:06 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:37:13 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		putout(t_lst **lst_a, t_lst **lst_b)
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
