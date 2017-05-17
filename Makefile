#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mponomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 19:59:21 by mponomar          #+#    #+#              #
#    Updated: 2017/05/15 18:36:13 by mponomar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_P = push_swap
NAME_C = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror

PUSH = Push_swap/
CHECK = Checker/
INC = includes/
LIBFT = libft/
FT_INC = $(LIBFT)/includes

P_CMP = main_p.o \
	begin_sort_b.o \
	push_swap.o \
	swap_a_b_s.o \
	push_rotate.o \
	rev_a_b_rr.o \
	start_sort.o \
	sort_lessfor_b.o \
	sort_lessfor.o \
	sort_lessfor_a.o \
	sort_int_tab.o \
	enotherclean.o \
	cleanlist.o \
	cleanlistnext.o \
	small_f.o \
	small_fv2.o \
	small_fv3.o \
	put_fnk.o \
	sort_b.o \
	sort_a.o \
	pb_pa_pp.o \
	check_doub.o \
	check_mi.o \
	check_value.o

C_CMP = main_c.o \
	checker.o \
	check_maxint.o \
	check_flag.o \
	check_double.o \
	itsort.o \
	input_com.o \
	pb_pa_ppp.o \
	swap_a_b_ss.o \
	push_rotatee.o \
	rev_a_b_rrr.o \
	put_out.o \
	cr_lst.o

all: $(NAME_P) $(NAME_C)

$(NAME_P): $(P_CMP)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME_P) -L $(LIBFT) -lft $(P_CMP)
	@echo "made" $(NAME_P)

$(NAME_C): $(C_CMP)
	@$(CC) $(FLAGS) -o $(NAME_C) -L $(LIBFT) -lft $(C_CMP)
	@echo "made" $(NAME_C)

$(P_CMP): %.o: $(PUSH)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INC) -I $(INC) $< -o $@

$(C_CMP): %.o: $(CHECK)%.c
	@$(CC) -c $(FLAGS) -I $(FT_INC) -I $(INC) $< -o $@

clean:
	@-/bin/rm -f $(P_CMP)
	@-/bin/rm -f $(C_CMP)
	@-make clean -C $(LIBFT)
	@echo "cleaned" $(NAME_P)
	@echo "cleaned" $(NAME_C)

fclean: clean
	@-/bin/rm -f $(NAME_P)
	@-/bin/rm -f $(NAME_C)
	@-make fclean -C $(LIBFT)
	@echo "fcleaned" $(NAME_P)
	@echo "fcleaned" $(NAME_C)

re: fclean all

rmf:
	rm *~
	rm \#*
	rm *.out