# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: botilia <botilia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 15:59:18 by botilia           #+#    #+#              #
#    Updated: 2021/12/29 11:14:49 by botilia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
NAME3 = client_bonus
NAME4 = server_bonus
FLAGS = -Wall -Werror -Wextra

ONE = client.c 
TWO = server.c 
THREE = client_bonus.c 
FOUR = server_bonus.c 


OBJ = $(patsubst %.c,%.o,$(ONE))
OBJ_T = $(patsubst %.c,%.o,$(TWO))
OBJ_B = $(patsubst %.c,%.o,$(THREE))
OBJ_T_B = $(patsubst %.c,%.o,$(FOUR))


HEADER = minitalk.h

all: $(NAME1) $(NAME2)

$(NAME1) : $(OBJ) $(HEADER)
	cc $(FLAGS) $(ONE) -o $(NAME1)

$(NAME2) : $(OBJ_T) $(HEADER)
	cc $(FLAGS) $(TWO) -o $(NAME2)
	
bonus: $(NAME3) $(NAME4)

$(NAME3) : $(OBJ_B) $(HEADER)
	cc $(FLAGS) $(THREE) -o $(NAME3)

$(NAME4) : $(OBJ_T_B) $(HEADER)
	cc $(FLAGS) $(FOUR) -o $(NAME4)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re: fclean all

.PHONY: all clean fclean re bonus