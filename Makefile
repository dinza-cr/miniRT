# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 19:00:11 by dinza-cr          #+#    #+#              #
#    Updated: 2026/01/22 14:29:11 by dinza-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minirt
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -Iinc -Ilibft -Iminilibx-linux
LDLIBS		:= -lm
RM			:= rm -rf


SRC_DIRS	:= canva inc cons_dest main operations 
SRC			:= $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.c)) # TEMPORARY

O_DIR		:= obj
OBJ			:= $(patsubst %.c,$(O_DIR)/%.o,$(SRC))
DEP			:= $(OBJ:.o=.d)

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

MLX_DIR		:= minilibx-linux
MLX_LIB		:= $(MLX_DIR)/libmlx.a

LDFLAGS		:= -L$(MLX_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) $(LDLIBS) -lmlx -lXext -lX11 -o $@

$(O_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(O_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
