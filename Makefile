# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenheni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:16:31 by abenheni          #+#    #+#              #
#    Updated: 2022/11/14 17:16:33 by abenheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar cr
SRC =  ft_printf.c ft_printf_func.c ft_printf_hex.c ft_printf_utils.c ft_printf_unsigned.c ft_printf_ptr.c
OBJ = $(SRC:%.c=%.o)
all : $(NAME)
$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean : 
	$(RM) $(OBJ)
fclean : clean 
	$(RM) $(NAME)
re : fclean all
.phony : all clean fclean $(NAME)
