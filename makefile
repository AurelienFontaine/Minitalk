# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:51:01 by afontain          #+#    #+#              #
#    Updated: 2023/10/03 18:22:48 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	client

BONUS		=	server

SRCS_DIR	= srcs/

INCLUDE_DIR = include/

PRINTF_DIR  = ./Printf/

Server		=	${SRCS_DIR}server.c \
				${SRCS_DIR}utils.c \
				# ${INCLUDE_DIR}

PRINTF = $(PRINTF_DIR)libftprintf.a

# SRCS_BONUS	=

OBJS		=	${SRCS:%.c=%.o}

OBJS_BONUS	=	${SRCS_BONUS:%.c=%.o}

CC			=	gcc

RM			=	rm -rf

GREEN		=	\033[1;32m

DEFAULT		=	\033[0m

CFLAGS		=	-Wall -Werror -Wextra -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		make -C $(PRINTF_DIR)
		${CC} ${CFLAGS} ${OBJS} $(PRINTF) -o ${NAME}

$(BONUS):	${OBJS_BONUS}
		${CC} ${CFLAGS} ${OBJS_BONUS} -o ${BONUS}

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR) :
	@ mkdir -p $@
	@ mkdir -p objs/BONUS
	
all:		${NAME}

bonus:	${BONUS}

clean:		
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}
		make fclean -C $(PRINTF_DIR)

fclean:		clean
		${RM} ${NAME}
		${RM} ${BONUS}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re bonus
