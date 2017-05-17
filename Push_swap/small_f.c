/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:38:52 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:40:01 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			checklstsize(t_lst **lst_b)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = *lst_b;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_lst		*inlst(char *str, t_lst *list)
{
	if (str == '\0')
	{
		list = NULL;
		return (list);
	}
	list->x = ft_atoi(str);
	return (list);
}

t_lst		*createlst(void)
{
	t_lst	*list;

	list = (t_lst *)malloc(sizeof(t_lst));
	list->x = '\0';
	list->next = NULL;
	return (list);
}

t_num		*createnum(int len)
{
	t_num	*num;

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
	num->com->next = NULL;
	num->com->x = 0;
	return (num);
}

void		neednextlst(t_lst **lst, int com)
{
	t_lst	*head;

	head = *lst;
	while (head->next != NULL)
		head = head->next;
	head->x = com;
	head->next = createlst();
	head->next->x = 0;
	head->next->next = NULL;
}
