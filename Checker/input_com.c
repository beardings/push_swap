/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_com.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 22:06:28 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 20:02:08 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			bababum(t_lst **lst_a, t_lst **lst_b, char *line)
{
	if (!(ft_strcmp(line, "ra")))
		ra_c(lst_a);
	else if (!(ft_strcmp(line, "rb")))
		rb_c(lst_b);
	else if (!(ft_strcmp(line, "pa")))
		pa_c(lst_a, lst_b);
	else if (!(ft_strcmp(line, "pb")))
		pb_c(lst_a, lst_b);
	else if (!(ft_strcmp(line, "sa")))
		sa_c(*lst_a);
	else if (!(ft_strcmp(line, "sb")))
		sb_c(*lst_b);
	else if (!(ft_strcmp(line, "rra")))
		rra_c(lst_a);
	else if (!(ft_strcmp(line, "rrb")))
		rrb_c(lst_b);
	else if (!(ft_strcmp(line, "rr")))
		rr_c(lst_a, lst_b);
	else if (!(ft_strcmp(line, "ss")))
		ss_c(lst_a, lst_b);
	else if (!(ft_strcmp(line, "rrr")))
		rrr_c(lst_a, lst_b);
	else
		return (0);
	return (1);
}

int			input_com(t_lst **lst_a, t_lst **lst_b, t_ch **che_l)
{
	char	*line;

	line = NULL;
	while ((get_next_line(0, &line)) > 0)
	{
		if ((bababum(lst_a, lst_b, line)) == 0)
		{
			ft_strdel(&line);
			return (0);
		}
		(*che_l)->skiko++;
		(*che_l)->flag_v == 1 ? write(1, "\n", 1) : 0;
		if ((*che_l)->flag_v == 1)
		{
			(*che_l)->flag_c != 1 ? put_out(lst_a, lst_b) : 0;
			(*che_l)->flag_c == 1 ? put_outnew(lst_a, lst_b) : 0;
		}
		ft_strdel(&line);
	}
	free(line);
	if ((itsort(lst_a, lst_b, 1, che_l)))
		return (1);
	else
		return (2);
}
