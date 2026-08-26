NAME        := minirt
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -Iinclude -Ilibft
LDLIBS      := -lm

SRC_DIR     := src
OBJ_DIR     := obj
SRC         := $(SRC_DIR)/main.c \
	$(SRC_DIR)/exec/canva.c \
	$(SRC_DIR)/exec/color.c \
	$(SRC_DIR)/exec/comps.c \
	$(SRC_DIR)/exec/get_next_line.c \
	$(SRC_DIR)/exec/get_next_line_utils.c \
	$(SRC_DIR)/exec/intersection.c \
	$(SRC_DIR)/exec/intersections.c \
	$(SRC_DIR)/exec/material.c \
	$(SRC_DIR)/exec/matrix.c \
	$(SRC_DIR)/exec/op_color.c \
	$(SRC_DIR)/exec/op_matrix.c \
	$(SRC_DIR)/exec/op_transformation.c \
	$(SRC_DIR)/exec/op_tuples.c \
	$(SRC_DIR)/exec/ray.c \
	$(SRC_DIR)/exec/tuple.c \
	$(SRC_DIR)/parsing/amblight.c \
	$(SRC_DIR)/parsing/camera.c \
	$(SRC_DIR)/parsing/cylinder.c \
	$(SRC_DIR)/parsing/light.c \
	$(SRC_DIR)/parsing/pars_utils.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/parsing/plane.c \
	$(SRC_DIR)/parsing/shape.c \
	$(SRC_DIR)/parsing/sphere.c \
	$(SRC_DIR)/parsing/world.c
OBJ         := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP         := $(OBJ:.o=.d)
CORE_OBJ    := $(filter-out $(OBJ_DIR)/main.o,$(OBJ))

TEST_NAME   := test_minirt
TEST_DIR    := tests
TEST_SRC    := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ    := $(TEST_SRC:$(TEST_DIR)/%.c=$(OBJ_DIR)/tests/%.o)
TEST_DEP    := $(TEST_OBJ:.o=.d)
TEST_LIBS   := -lcriterion

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/tests/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) CC="$(CC)"

tests: $(CORE_OBJ) $(TEST_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CORE_OBJ) $(TEST_OBJ) $(LIBFT) \
		$(LDLIBS) $(TEST_LIBS) -o $(TEST_NAME)
	./$(TEST_NAME)

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(TEST_NAME)
	$(RM) canva.ppm
	$(MAKE) -C $(LIBFT_DIR) clean CC="$(CC)"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean CC="$(CC)"

re: fclean all

-include $(DEP) $(TEST_DEP)

.PHONY: all clean fclean re tests
