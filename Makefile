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

all: libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) libft/*.o

libft:
	@make -C libft/

clean:
	@$(RM) $(OBJ)
	@make -C libft/ clean

fclean: clean
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re