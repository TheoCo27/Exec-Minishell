# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theog <theog@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 17:29:12 by tcohen            #+#    #+#              #
#    Updated: 2024/10/01 00:29:46 by theog            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

SRCS = srcs/main.c
INCLUDES = ./srcs -I ./libft

LIBFT = libft.a
LIB_DIR = ./libft
OBJ_DIR = obj
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

CFLAGS =  -Wall -Wextra -Werror -g3

NAME = hey_doc

all: $(LIBFT) $(NAME)

# Crée le dossier obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile chaque .o dans le dossier obj
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME) libft/libft.a

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

cleanbis:
	rm -f $(OBJS)
	make clean -C ./libft

go: re cleanbis
	clear

.PHONY: all clean fclean re cleanbis go
