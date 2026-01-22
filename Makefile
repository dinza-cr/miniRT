# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 19:00:11 by dinza-cr          #+#    #+#              #
#    Updated: 2026/01/22 11:25:36 by dinza-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = minirt
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
LDLIBS  = -lm

MLX_DIR  = minilibx-linux
MLX_LIB  = -L$(MLX_DIR) -lmlx -lX11 -lXext
INCLUDES = -I$(MLX_DIR) -I.

SRC      = $(wildcard *.c)

OBJ      = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDLIBS) -o $(NAME) $(MLX_LIB) $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all