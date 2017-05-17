/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:10:59 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 18:39:58 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst		*create_lst(void)
{
	t_lst	*list;

	list = (t_lst *)malloc(sizeof(t_lst));
	list->x = '\0';
	list->next = NULL;
	return (list);
}

void		del_list(t_lst **head)
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

t_lst		*in_lst(char *str, t_lst *list)
{
	if (str == '\0')
	{
		list = NULL;
		return (list);
	}
	list->x = ft_atoi(str);
	return (list);
}
