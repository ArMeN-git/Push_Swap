# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 11:30:29 by fngoc             #+#    #+#              #
#    Updated: 2021/06/09 20:27:05 by argrigor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = push_swap

MAKE = make

CLEAN = clean

FCLEAN = fclean

SRC =	main.c \
		fill.c \
		fix.c \
		from_a_to_b.c \
		from_b_to_a.c \
		ft_atoi_modified.c \
		indexing.c \
		keep.c \
		operations.c \
		solve.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra

OPTIONOBJ = -o

DEL = rm -rf

GREEN ='\033[1;32m'

WHITE ='\033[0;37m'

YELLOW ='\033[1;33m'

CYAN ='\033[1;36m'

MAGENTA ='\033[1;35m'

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAG) $(OBJ) $(OPTIONOBJ) $(NAME)
	@echo $(GREEN)"Start!"${WHITE}

clean:
	@$(DEL) $(OBJ)
	@echo $(YELLOW)"All obj files are cleared."

fclean: clean
	@$(DEL) $(NAME)
	@echo $(MAGENTA)"Binary file is cleared."

re: fclean all
