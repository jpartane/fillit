# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlaukkan <tlaukkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/14 11:36:53 by jpartane          #+#    #+#              #
#    Updated: 2020/01/16 17:29:24 by jpartane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fillit

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc -g
CC_FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/ 

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fillit.h

SRC_NAME = fillit.c map.c validate.c solver.c identify.c shapes.c

all: $(NAME)

$(NAME): $(OBJ)
		@echo
		@make -C $(LFT_PATH)
		@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft
		@echo "$(OKC)FILLIT:\t\tFillit ready$(NOC)"
		@echo "======"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $< -I ./libft
		@echo -n =

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "$(WAC)FILLIT:\t\tRemoving OBJ path: ./obj/$(NOC)"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -f $(NAME)
		@echo "$(WAC)FILLIT:\t\tRemoving fillit executable$(NOC)"

re: fclean all
