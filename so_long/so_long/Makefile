NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx_opengl_20191021/
MLX = $(MLX_DIR)/libmlx.a

SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/

HEADER = $(SRC_DIR)so_long.h
HEADER_BONUS = $(SRC_BONUS_DIR)so_long_bonus.h

SRC_FILES = main.c \
				map_validation.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				check_map.c \
				start_game.c \
				draw.c \
				movement.c \
				movement1.c \

SRC_BONUS_FILES = main_bonus.c \
				map_validation_bonus.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				check_map_bonus.c \
				start_game_bonus.c \
				draw_bonus.c \
				movement_bonus.c \
				movement1_bonus.c \
				animation_bonus.c \

OBJ = $(patsubst %.c, %.o, $(addprefix $(SRC_DIR), $(SRC_FILES)))
OBJ_BONUS = $(patsubst %.c, %.o, $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES)))

all: $(LIBFT) $(MLX) $(NAME)

bonus: $(LIBFT) $(MLX)
			@make OBJ="$(OBJ_BONUS)" \
			SRC_DIR="$(SRC_BONUS_DIR)" \
			SRC_FILES="$(SRC_BONUS_FILES)" \
			HEADER="$(HEADER_BONUS)" all

$(NAME): $(OBJ) ${HEADER}
				$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $@

$(SRC_DIR)%.o: $(SRC_DIR).c
					$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT):
			make -C $(LIBFT_DIR)

$(MLX):
			make -C $(MLX_DIR)


clean:
			$(RM) $(OBJ) $(OBJ_BONUS)
			make -C $(MLX_DIR) clean
			make -C $(LIBFT_DIR) clean

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
