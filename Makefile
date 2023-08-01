NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
MLX_FLAGS = -Imlx -Lmlx/ -lmlx -framework OpenGL -framework AppKit

SRC_DIR = src/
SRC = main.c get_map.c shape_checker.c window_handler.c loop_handler.c movement.c content_checker.c path_checker.c
OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

BONUS_NAME = bonus
BONUS_SRC_DIR = src/bonus/
BONUS_SRC = bonus.c bonus_content_checker.c bonus_movement.c bonus_shape_checker.c bonus_window_handler.c bonus_get_map.c bonus_loop_handler.c bonus_path_checker.c
BONUS_OBJ_DIR = objs/
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRC:.c=.o))

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

all: libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) libft/*.o
	@ echo "So_long compiled"

bonus: libft $(BONUS_OBJ)
	@$(CC) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) $(MLX_FLAGS) libft/*.o
	@ echo "Bonus compiled"

libft:
	@make -C libft/

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
	@make -C libft/ clean

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re