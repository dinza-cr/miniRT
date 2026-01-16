# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 19:00:11 by dinza-cr          #+#    #+#              #
#    Updated: 2026/01/16 15:27:11 by dinza-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = minirt
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
LDLIBS  = -lm

SRC      = $(wildcard *.c)

OBJ      = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all