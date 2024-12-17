NAME = cub3D
CC = cc
GNL = libs/get_next_line/

FREE_RES = free_arr.c free_data.c free_meta.c free_mlx.c free_ln_err.c

LOOP = draw_frame.c draw_vertical_line.c exit_game.c game_init.c \
        get_delta_time.c hooks_init.c on_key_pressed.c  
            
PARSER = check_map.c fill_wall.c meta_init.c parse_dir.c parse_map.c \
            parser.c flood_fill.c

PLAYER = init_player.c move.c rotate.c set_direction.c set_fov.c \
        update_direction.c

RAYCAST = delta_len.c find_wall.c get_line_inds.c get_vectors_cos_angle.c \
		ray_hit_len.c raycast.c 

UTILS = print_error.c ft_isspace.c ft_split_ntrim.c safe_malloc.c check_color.c  \
		ft_strcmp.c

SRC = srcs/main.c \
    srcs/debug/debug.c \
    $(addprefix srcs/free_res/, $(FREE_RES)) \
    $(addprefix srcs/loop/, $(LOOP)) \
    $(addprefix srcs/parser/, $(PARSER)) \
    $(addprefix srcs/player/, $(PLAYER)) \
    $(addprefix srcs/raycast/, $(RAYCAST)) \
    $(addprefix srcs/utils/, $(UTILS)) \
    $(GNL)get_next_line.c \
    $(GNL)get_next_line_utils.c \

OBJ = ${SRC:.c=.o}

LIBFT_PATH	= libs/libft
LIBFT_NAME	= libft.a
LIBS = -L$(LIBFT_PATH) -lft

FLAGS = -Wall -Wextra -Werror 

ifeq ($(shell uname), Darwin) 
	MLXPATH = libs/mlx_mac
	MINILIBX = $(MLXPATH)/libmlx.a 
	LIBS += -L$(MLXPATH) -lmlx -framework OpenGL -framework AppKit
else
	MLXPATH = libs/mlx_linux
	MINILIBX = $(MLXPATH)/libmlx_Linux.a 
	LIBS += -L$(MLXPATH) -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm 
endif

INCS = -I$(MLXPATH) -I./incs/

all: $(NAME)

bonus: $(NAME)

$(NAME): ${LIBFT_PATH}/${LIBFT_NAME} $(MINILIBX) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

$(MINILIBX):
	make -C $(MLXPATH)

%.o: %.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@   

clean:
	rm -f $(OBJ)
	cd $(LIBFT_PATH) && make clean

fclean: clean 
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	make clean -C $(MLXPATH)

re: fclean all 

PHONY: all clean fclean re fclean_linux, re_linux