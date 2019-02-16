# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 15:46:50 by vkhomenk          #+#    #+#              #
#    Updated: 2019/02/05 20:30:03 by vkhomenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libftprintf.a
SRC_DIR			:= src/
INC_DIR 		:= inc/
OBJ_DIR 		:= obj/
LIB_DIR			:= lib/

SRC				:= ft_printf.c
OBJ				:= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR		:= $(LIB_DIR)libft/
LIBFT_INC		:= $(LIBFT_DIR)includes/
LIBFT			:= $(LIBFT_DIR)libft.a	

LIBFT_FLAGS 	:= -lft -L $(LIBFT_DIR)
CC_FLAGS		:= -Wall -Wextra
LINK_FLAGS		:= $(LIBFT_FLAGS)
HEADER_FLAGS	:= -I $(INC_DIR) -I $(LIBFT_INC)
CC				:= clang

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	$(CC) $(CC_FLAGS) -o main.o -c $(SRC_DIR)main.c $(HEADER_FLAGS)
	$(CC) $(CC_FLAGS) -o ft_printf main.o -lftprintf -L .
	rm main.o

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CC_FLAGS) -o $@ -c $< $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -f ft_printf

re: fclean all


.PHONY: all clean fclean re
