# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 19:00:11 by dinza-cr          #+#    #+#              #
#    Updated: 2026/02/12 16:04:11 by dinza-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is a minimal set of ANSI/VT100 color codes
_END=$'\033[0m
_BOLD=$'\033[1m
_UNDER=$'\033[4m
_REV=$'\033[7m

# Colors
_GREY=$'\033[30m
_RED=$'\033[31m
_GREEN=$'\033[32m
_YELLOW=$'\033[33m
_BLUE=$'\033[34m
_PURPLE=$'\033[35m
_CYAN=$'\033[36m
_WHITE=$'\033[37m

################################################################################
#                                VARIABLES									   #
################################################################################

NAME			= 	minirt
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
CPPFLAGS		=	-Iinc -Ilibft -Iminilibx-linux
LDLIBS			=	-lm
RM				= 	rm -rf

SRC_DIRS_CORE	=	Exec/Canva Exec/Color Exec/gnl Exec/Matrix Exec/Tuples Parsing Parsing/Amblight Parsing/Camera Parsing/Cylinder Parsing/Light Parsing/Plane Parsing/Scene Parsing/Sphere
SRC_CORE		=	$(foreach d,$(SRC_DIRS_CORE),$(wildcard $(d)/*.c)) ## TEMPORARY

SRC_DIRS_MAIN	=	main
SRC_MAIN		=	$(foreach d,$(SRC_DIRS_MAIN),$(wildcard $(d)/*.c)) ##TEMPORARY

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
#                              	TEST VARIABLES					   		   	   #
################################################################################

CR_HEADER_PATH	=	-I${HOME}/Criterion/include/criterion
CR_LIB_PATH		=	-Wl,-rpath=${HOME}/Criterion/build/src -L${HOME}/Criterion/build/src
T_FLAGS			=	-lcriterion
T_NAME			= 	test_minirt
TESTS_DIRS		=	tests
T_SRCS			=	$(foreach d,$(TESTS_DIRS),$(wildcard $(d)/*.c)) ## TEMPORARY
T_OBJECTS 		=	$(subst /,/build/,${T_SRCS:.c=.o})
T_CC			=	gcc $(CR_HEADER_PATH) $(CFLAGS)
T_LD			=	gcc $(CR_HEADER_PATH) $(CR_LIB_PATH) $(CFLAGS)

################################################################################
#                                TEST RULES								       #
################################################################################

$(T_OBJECTS): $(subst .o,.c,$(subst /build/,/,$@))
	@mkdir -p $(dir $@)
	@$(T_CC) $(CPPFLAGS) -c $(subst .o,.c,$(subst /build/,/,$@)) -o $@

tests: tclean $(LIBFT) $(MLX_LIB) $(OBJ) $(T_OBJECTS)
	@echo "${_UNDER}${_RED}Creating binary for Tests${_END}"
	@$(T_LD) -o $(T_NAME) $(OBJ_CORE) $(T_OBJECTS) $(LIBFT) $(LDFLAGS) $(LDLIBS) -lmlx -lX11 -lXext $(T_FLAGS)
	@./$(T_NAME)

tclean:
	$(RM) tests/build ${T_NAME}

################################################################################
#                               	CLEANUP								       #
################################################################################

clean: tclean
	$(RM) $(O_DIR)
	$(RM) tests/build
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re:	fclean all

-include $(DEP)

.PHONY:	all clean fclean re tests tclean