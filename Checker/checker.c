/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:52:59 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/14 20:13:25 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		error(t_ch **che_l)
{
	if ((*che_l)->flag_c == 1)
		ft_printf("\033[0;31mError\033[0m\n");
	else
		ft_printf("Error\n");
}

int			woooooow(t_lst **lst_a, t_lst **lst_b, t_ch **che_l)
{
	if ((input_com(lst_a, lst_b, che_l)))
	{
		del_list(lst_b);
		del_list(lst_a);
		return (1);
	}
	else
	{
		error(che_l);
		del_list(lst_b);
		del_list(lst_a);
		return (0);
	}
}

int			continue_ch(char **v, t_ch **che_l)
{
	t_lst	*lst_a;
	t_lst	*lst_b;
	t_lst	*head;
	int		i;

	i = (*che_l)->fin;
	lst_b = NULL;
	lst_a = create_lst();
	in_lst(v[i], lst_a);
	i++;
	head = lst_a;
	while (i < (*che_l)->len)
	{
		lst_a->next = create_lst();
		in_lst(v[i], lst_a->next);
		lst_a = lst_a->next;
		i++;
	}
	lst_a = head;
	if ((woooooow(&lst_a, &lst_b, che_l)))
		return (1);
	else
		return (0);
}

t_ch		*createch(void)
{
	t_ch	*che_l;

	che_l = (t_ch *)malloc(sizeof(t_ch));
	che_l->flag_v = 0;
	che_l->flag_c = 0;
	che_l->flag_k = 0;
	che_l->skiko = 0;
	che_l->fin = 0;
	che_l->len = 0;
	return (che_l);
}

int			checker(int c, char **v)
{
	t_ch	*che_l;
	int		k;

	che_l = createch();
	che_l->len = c;
	k = check_flag(v, &che_l);
	if (k == -1 && che_l->fin == 0)
		return (0);
	if (k == 0 && che_l->fin == 0)
		error(&che_l);
	else
	{
		che_l->fin = k + 1;
		if ((check_int(v, &che_l)) == 1)
		{
			if ((check_double(v, &che_l)))
				continue_ch(v, &che_l);
			else
				error(&che_l);
		}
		else
			error(&che_l);
	}
	free(che_l);
	return (0);
}
