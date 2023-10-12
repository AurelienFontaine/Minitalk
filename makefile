# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:51:01 by afontain          #+#    #+#              #
#    Updated: 2023/10/12 09:47:52 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	server

BONUS		=	client

INCLUDE_DIR = include/


CLIENT		=	./srcs/client.c \
				./srcs/utils.c \
				
SERVER 		=   ./srcs/server.c \
				./srcs/utils.c \

PRINTF = $(PRINTF_DIR)libftprintf.a

PRINTF_DIR  = ./printf/

OBJS		=	${SERVER:%.c=%.o}

OBJS_BONUS	=	${CLIENT:%.c=%.o}

CC			=	gcc

RM			=	rm -rf

GREEN		=	\033[1;32m

DEFAULT		=	\033[0m

CFLAGS		=	-Wall -Werror -Wextra -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

	make -C $(PRINTF_DIR)
		
$(NAME):	${OBJS}
		
		${CC} ${CFLAGS} ${OBJS} $(PRINTF) -o ${NAME}
		

$(BONUS):	${OBJS_BONUS}
		
		${CC} ${CFLAGS} ${OBJS_BONUS} $(PRINTF) -o ${BONUS}
		

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
		make fclean -C $(PRINTF_DIR)
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re bonus
