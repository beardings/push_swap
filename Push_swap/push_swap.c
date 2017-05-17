/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 20:33:01 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/14 20:46:34 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define STR() i = 1, lst_b = NULL, lst_a = createlst()

void		lenlst_v2(t_lst *tmp)
{
	if (tmp->x == 1)
		ft_printf("%s\n", "ra");
	else if (tmp->x == 2)
		ft_printf("%s\n", "rb");
	else if (tmp->x == 3)
		ft_printf("%s\n", "pa");
	else if (tmp->x == 4)
		ft_printf("%s\n", "pb");
	else if (tmp->x == 5)
		ft_printf("%s\n", "sa");
	else if (tmp->x == 6)
		ft_printf("%s\n", "sb");
	else if (tmp->x == 7)
		ft_printf("%s\n", "rra");
	else if (tmp->x == 8)
		ft_printf("%s\n", "rrb");
	else if (tmp->x == 9)
		ft_printf("%s\n", "rr");
	else if (tmp->x == 10)
		ft_printf("%s\n", "ss");
	else if (tmp->x == 9)
		ft_printf("%s\n", "rrr");
}

int			lenlst(t_lst **lst)
{
	int		i;
	t_lst	*tmp;

	tmp = *lst;
	i = 0;
	while (tmp != NULL)
	{
		lenlst_v2(tmp);
		if (tmp->x != 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void		input(int i, int len, char **strs, t_lst **lst_a)
{
	while (i < len)
	{
		(*lst_a)->next = createlst();
		inlst(strs[i], (*lst_a)->next);
		*lst_a = (*lst_a)->next;
		i++;
	}
}

int			bla(char **strs, int len)
{
	if (!(check_inp(strs, len)))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!(check_doub(strs, len)))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

void		push_swap(int len, char **strs)
{
	t_lst	*lst_a;
	t_lst	*lst_b;
	t_lst	*head;
	t_num	*num;
	int		i;

	if (!(bla(strs, len)))
		return ;
	num = createnum(len);
	STR();
	inlst(strs[i], lst_a);
	i++;
	head = lst_a;
	input(i, len, strs, &lst_a);
	lst_a = head;
	if ((check_sort(&lst_a)))
	{
		ft_del_list(&(num->com));
		ft_del_list(&(lst_a));
		free(num);
		return ;
	}
	start_sort(lst_a, lst_b, num);
	ft_del_list(&(num->com));
}
