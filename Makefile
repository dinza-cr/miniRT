# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 19:00:11 by dinza-cr          #+#    #+#              #
#    Updated: 2026/03/20 17:00:55 by dinza-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                VARIABLES									   #
################################################################################

NAME			= 	miniRT
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
CPPFLAGS		=	-Iinc -Ilibft -Iminilibx-linux
LDLIBS			=	-lm
RM				= 	rm -rf

SRC_CORE		=	Exec/Canva/canva_mlx.c Exec/Canva/canva.c \
				Exec/Color/color.c Exec/Color/op_color.c \
				Exec/Comps/comps.c \
				Exec/gnl/get_next_line.c Exec/gnl/get_next_line_utils.c \
				Exec/Intersection/int_utils.c Exec/Intersection/intersection.c Exec/Intersection/intersections.c \
				Exec/Material/material.c \
				Exec/Matrix/matrix.c Exec/Matrix/op_matrix.c Exec/Matrix/op_matrix2.c Exec/Matrix/op_matrix3.c Exec/Matrix/op_matrix4.c Exec/Matrix/op_transformation.c Exec/Matrix/op_transformation2.c \
				Exec/Ray/ray.c \
				Exec/Tuples/op_tuples.c Exec/Tuples/op_tuples2.c Exec/Tuples/tuple.c \
				Parsing/pars_utils.c Parsing/parsing.c Parsing/parsing2.c \
				Parsing/Amblight/amblight.c \
				Parsing/Camera/camera.c \
				Parsing/Cylinder/cylinder.c Parsing/Cylinder/cylinder2.c Parsing/Cylinder/cylinder_utils.c \
				Parsing/Light/light.c Parsing/Light/light_utils.c \
				Parsing/Plane/plane.c \
				Parsing/Shape/shape.c \
				Parsing/Sphere/sphere.c \
				Parsing/World/world.c

SRC_MAIN		=	main/main.c

SRC				=	$(SRC_CORE) $(SRC_MAIN)

O_DIR			=	obj
OBJ_CORE		=	$(patsubst %.c,$(O_DIR)/%.o,$(SRC_CORE))
OBJ				=	$(patsubst %.c,$(O_DIR)/%.o,$(SRC))
DEP				=	$(OBJ:.o=.d)

LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a

MLX_DIR			=	minilibx-linux
MLX_LIB			=	$(MLX_DIR)/libmlx.a

LDFLAGS			=	-L$(MLX_DIR)

################################################################################
#                                MAIN RULES								       #
################################################################################

all:	$(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) $(LDLIBS) -lmlx -lXext -lX11 -o $@

$(O_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

################################################################################
#                               	CLEANUP								       #
################################################################################

clean:
	$(RM) $(O_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re:	fclean all

-include $(DEP)

.PHONY:	all clean fclean re tests tclean