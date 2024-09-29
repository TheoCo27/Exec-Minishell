# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theog <theog@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/15 14:31:33 by tcohen            #+#    #+#              #
#    Updated: 2024/09/29 16:34:12 by theog            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = obj
LIBFT = $(LIBFT_DIR)/libft.a
FLAGS =  -Wall -Wextra -Werror -g3
CC = cc
SRC = main.c ft_child.c ft_path.c ft_secure.c ft_all.c ft_check.c ft_set.c \
	ft_pipe_lst.c ft_exec_one.c ft_while_cmd.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
INCLUDE = -I$(LIBFT_DIR) -I$(SRC_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

