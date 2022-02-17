# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 15:58:39 by anajmi            #+#    #+#              #
#    Updated: 2022/02/17 17:07:22 by anajmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SRCLIENT = ./src/client.c

SERVER = server
SRSERVER = ./src/server.c

NAME = $(CLIENT) $(SERVER)

BCLIENT = client_bonus
SRBCLIENT = ./bonus/client_bonus.c

BSERVER = server_bonus
SRBSERVER = ./bonus/server_bonus.c

BNAME = $(BCLIENT) $(BSERVER)

FILES = 	\
		./utils/ft_atoi.c		\
		./utils/ft_putchar.c	\
		./utils/ft_putendl.c	\
		./utils/ft_putnbr.c		\
		./utils/ft_putstr.c

OBJ = $(FILES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(SRCLIENT) $(OBJ) -o $(CLIENT)
	gcc $(SRSERVER) $(OBJ) -o $(SERVER)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) $(BNAME)

re : fclean all

bonus : $(BNAME) 

$(BNAME) : $(OBJ)
	gcc $(SRBCLIENT) $(OBJ) -o $(BCLIENT)
	gcc $(SRBSERVER) $(OBJ) -o $(BSERVER)

.PHONY : all clean fclean re bonus