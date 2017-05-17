/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_fv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:40:33 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:41:10 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		lstdel(t_lst **lst)
{
	t_lst	*a;
	t_lst	*b;

	a = (*lst)->next->next;
	b = (*lst)->next;
	(*lst)->next = (*lst)->next->next->next;
	free(a);
	free(b);
}

void		lstdelone(t_lst **lst)
{
	t_lst	*a;

	a = (*lst)->next->next;
	(*lst)->next->next = (*lst)->next->next->next;
	free(a);
}

void		ft_del_list(t_lst **head)
{
	t_lst	*wow;
	t_lst	*pop;

	wow = *head;
	while (wow)
	{
		pop = wow;
		wow = wow->next;
		ft_bzero(pop, sizeof(pop));
		free(pop);
	}
	*head = NULL;
	return ;
}

int			check_inp(char **v, int len)
{
	int		i;

	i = 1;
	while (i < len)
	{
		if ((check_value(v[i])))
		{
			if ((check_maxint(v[i])))
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	if (i == len)
		return (1);
	else
		return (0);
}

int			check_sort(t_lst **lst_a)
{
	t_lst	*tmp;

	tmp = *lst_a;
	while (tmp->next != NULL)
	{
		if (tmp->x < tmp->next->x)
			tmp = tmp->next;
		else
			return (0);
	}
	if (tmp->next == NULL)
		return (1);
	else
		return (0);
}
