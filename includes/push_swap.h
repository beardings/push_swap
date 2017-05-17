/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:23:17 by mponomar          #+#    #+#             */
/*   Updated: 2017/05/15 18:38:51 by mponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/header/libft.h"
# include "../libft/header/ft_printf.h"
# include <limits.h>
# include "../libft/header/get_next_line.h"

typedef struct		s_lst
{
	int				x;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_num
{
	int				mid;
	int				len;
	int				end;
	int				start;
	int				lenop;
	int				first_b;
	int				skira;
	int				pro;
	int				size;
	int				newsize;
	t_lst			*com;
}					t_num;

typedef struct		s_ch
{
	int				flag_v;
	int				flag_c;
	int				flag_k;
	int				skiko;
	int				fin;
	int				len;
}					t_ch;

void				push_swap(int len, char **strs);
void				sa(t_lst *lst_a, t_num **num, int i);
void				sb(t_lst *lst_b, t_num **num, int i);
void				ss(t_lst **lst_a, t_lst **lst_b, t_num **num, int i);
t_lst				*createlst(void);
void				pb(t_lst **lst_a, t_lst **lst_b, t_num **num, int i);
void				pa(t_lst **lst_a, t_lst **lst_b, t_num **num, int i);
void				rra(t_lst **lst_a, t_num **num, int i);
void				rrb(t_lst **lst_b, t_num **num, int i);
void				rrr(t_lst **lst_a, t_lst **lst_b, t_num **num, int i);
void				ra(t_lst **lst_a, t_num **num, int i);
void				rb(t_lst **lst_b, t_num **num, int i);
void				rr(t_lst **lst_a, t_lst **lst_b, t_num **num, int i);
void				start_sort(t_lst *lst_a, t_lst *lst_b, t_num *num);
void				putout(t_lst **lst_a, t_lst **lst_b);
void				sort_lessfor(t_lst **lst_a, int size, t_num **num);
void				sort_b(t_lst **lst_a, t_lst **lst_b, t_num **num, int size);
void				sort_a(t_lst **lst_a, t_lst **lst_b, t_num **num, int size);
int					checklstsize(t_lst **lst_b);
int					itismid_b(t_lst **lst_b, int size);
void				neednextlst(t_lst **lst, int com);
int					lenlst(t_lst **lst);
void				checkitsort(t_lst **lst_a);
void				enotherclean(t_lst **lst);
void				cleanlist(t_lst **head);
int					lenlst(t_lst **lst);
void				cleanlistnext(t_lst **lst);
void				sort_lessfor_b(t_lst **lst, int size, t_num **num);
void				sort_lessfor(t_lst **lst, int size, t_num **num);
void				sort_lessfor_a(t_lst **lst, int size, t_num **num);
void				sort_int_tab(int *tab, int size);
void				ft_del_list(t_lst **head);
void				lstdelone(t_lst **lst);
void				lstdel(t_lst **lst);
int					checker(int c, char **v);
t_lst				*inlst(char *str, t_lst *list);
void				put_outnew(t_lst **lst_a, t_lst **lst_b);
int					check_int(char **v, t_ch **che_l);
int					check_maxint(char *str);
int					check_value(char *str);
t_num				*createnum(int len);
int					check_sort(t_lst **lst_a);
int					check_inp(char **v, int len);
int					checkkol(t_lst **lst_a, t_num **num);
int					lenlstnew(t_lst **lst);
void				return_binb(t_lst **lst_a, t_lst **lst_b, t_num **num,
								int size);
void				return_bina(t_lst **lst_a, t_lst **lst_b, t_num **num,
								int size);
int					checkkolnew(t_lst **lst_b, t_num **num);
int					findmid_b(t_lst **lst_a, t_lst **lst_b, t_num **num,
								int size);
int					begin_sort_b(t_lst **lst_a, t_lst **lst_b, t_num **num,
									int size);
int					checkmid(t_num **num, t_lst **lst_b, int size);
void				findmid_b_n(t_lst **lst_a, t_lst **lst_b, t_num **num,
								int size);
int					begin_sort(t_lst **lst_a, t_lst **lst_b, t_num **num,
								int size);
int					itismid(t_lst **lst_a, int size);
int					findmid(t_lst **lst_a, t_lst **lst_b, t_num **num,
								int size);
int					check_flag(char **v, t_ch **che_l);
int					check_value(char *str);
int					check_double(char **v, t_ch **che_l);
int					itsort(t_lst **lst_a, t_lst **lst_b, int i, t_ch **che_l);
int					input_com(t_lst **lst_a, t_lst **lst_b, t_ch **che_l);
int					check_doub(char **v, int len);
void				put_out(t_lst **lst_a, t_lst **lst_b);
void				pb_c(t_lst **lst_a, t_lst **lst_b);
void				pa_c(t_lst **lst_a, t_lst **lst_b);
void				ra_c(t_lst **lst_a);
void				rb_c(t_lst **lst_b);
void				rr_c(t_lst **lst_a, t_lst **lst_b);
void				rra_c(t_lst **lst_a);
void				rrb_c(t_lst **lst_b);
void				rrr_c(t_lst **lst_a, t_lst **lst_b);
void				sa_c(t_lst *lst_a);
void				sb_c(t_lst *lst_b);
void				ss_c(t_lst **lst_a, t_lst **lst_b);
t_lst				*create_lst(void);
void				del_list(t_lst **head);
t_lst				*in_lst(char *str, t_lst *list);

#endif
