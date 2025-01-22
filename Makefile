# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvitor-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 18:36:44 by pvitor-l          #+#    #+#              #
#    Updated: 2025/01/22 19:01:00 by pvitor-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
FLAGS = -Wall -Wextra -Werror -g
CC = cc
LIB_DIR = libft
LIB = $(LIB_DIR)/libft.a

SRC = src/main.c \
      src/error.c \
      src/exec.c \
      src/pipex_functions.c 

OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJ)	$(LIB)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I includes -c $< -o $@

$(LIB):
	@make -C $(LIB_DIR)
clean:
	rm -rf $(OBJ)
	@make clean -C $(LIB_DIR)

fclean:	clean
	rm -rf $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all
