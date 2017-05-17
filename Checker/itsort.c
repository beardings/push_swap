/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itsort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 21:53:50 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 18:55:21 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		one(t_ch **che_l)
{
	if ((*che_l)->flag_c != 1)
		ft_printf("OK\n");
	else
		ft_printf("\033[0;32mOK\033[0m\n");
	if ((*che_l)->flag_k == 1)
	{
		(*che_l)->flag_c != 1 ? ft_printf("Operations: ") : 0;
		(*che_l)->flag_c == 1 ? ft_printf("\033[0;34mOperations: \033[0m") : 0;
	}
	if ((*che_l)->flag_k == 1)
	{
		(*che_l)->flag_c != 1 ? ft_printf("%d\n", (*che_l)->skiko) : 0;
		if ((*che_l)->flag_c == 1)
			ft_printf("\033[0;34m%d\033[0m\n", (*che_l)->skiko);
	}
}

void		two(t_ch **che_l, int i)
{
	i == 1 && (*che_l)->flag_v == 1 ? ft_printf("\n") : 0;
	i == 1 && (*che_l)->flag_c != 1 ? ft_printf("KO\n") : 0;
	i == 1 && (*che_l)->flag_c == 1 ? ft_printf("\033[0;31mKO\033[0m\n") : 0;
}

void		second(t_ch **che_l)
{
	(*che_l)->flag_v == 1 ? ft_printf("\n") : 0;
	(*che_l)->flag_c != 1 ? ft_printf("KO\n") : 0;
	(*che_l)->flag_c == 1 ? ft_printf("\033[0;31mKO\033[0m\n") : 0;
}

int			sooort(t_lst *tmp, t_ch **che_l, int i)
{
	while (tmp->next != NULL)
	{
		if (tmp->x < tmp->next->x)
			tmp = tmp->next;
		else
		{
			two(che_l, i);
			return (0);
		}
	}
	if (tmp->next == NULL)
	{
		one(che_l);
		return (1);
	}
	else
		return (0);
}

int			itsort(t_lst **lst_a, t_lst **lst_b, int i, t_ch **che_l)
{
	t_lst	*tmp;

	if (*lst_b != NULL)
	{
		second(che_l);
		return (0);
	}
	if (*lst_a != NULL)
	{
		tmp = *lst_a;
		if ((sooort(tmp, che_l, i) == 1))
			return (1);
		else
			return (0);
	}
	return (0);
}
