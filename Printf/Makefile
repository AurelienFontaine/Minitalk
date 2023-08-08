# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:41:43 by afontain          #+#    #+#              #
#    Updated: 2022/11/23 18:24:37 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

cc = gcc
RM = rm -f
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c \
	ft_print_char_str_nbr.c \
	ft_printHexa.c \
	ft_printunsigned.c \
	ft_printptr.c \
	ft_itoa.c 
	
OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	 $(AR) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY:	all clean fclean re bonus
