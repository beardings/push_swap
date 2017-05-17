/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lessfor_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:40:45 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/13 19:49:52 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define ORONE() (tmp->next->x < tmp->next->next->x)
#define ORTWO() (tmp->next->x > tmp->next->next->x)

void	sort_nn(t_lst **lst, t_num **num, t_lst *tmp)
{
	if ((tmp->x > tmp->next->next->x) && (tmp->next->x < tmp->next->next->x))
	{
		rb(lst, num, 1);
		sb(*lst, num, 1);
		rrb(lst, num, 1);
	}
	else if ((tmp->x < tmp->next->next->x) && ORTWO())
		rrb(lst, num, 1);
	else if ((tmp->x < tmp->next->next->x) && ORONE())
	{
		rb(lst, num, 1);
		sb(*lst, num, 1);
		rrb(lst, num, 1);
		sb(*lst, num, 1);
	}
}

void	sort_n(t_lst **lst, t_num **num, t_lst *tmp)
{
	if (tmp->x < tmp->next->x)
	{
		if ((tmp->x < tmp->next->next->x) && ORONE())
		{
			sb(*lst, num, 1);
			rb(lst, num, 1);
			sb(*lst, num, 1);
			rrb(lst, num, 1);
			sb(*lst, num, 1);
		}
		else if ((tmp->x > tmp->next->next->x) && ORTWO())
			sb(*lst, num, 1);
		else if ((tmp->x < tmp->next->next->x) && ORTWO())
		{
			sb(*lst, num, 1);
			rb(lst, num, 1);
			sb(*lst, num, 1);
			rrb(lst, num, 1);
		}
	}
	else if (tmp->x > tmp->next->x)
		sort_nn(lst, num, tmp);
}

void	sort_lessfor_b(t_lst **lst, int size, t_num **num)
{
	t_lst *tmp;

	tmp = *lst;
	if (tmp != NULL)
	{
		if (size == 2)
			if (tmp->x < tmp->next->x)
				sb(*lst, num, 1);
		if (size == 3)
			sort_n(lst, num, tmp);
	}
}
