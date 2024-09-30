NAME 	= cub3D
UNAME_S := $(shell uname -s)

LIBDIR	= $(PWD)/lib

ifeq ($(UNAME_S), Darwin)
	MLXDIR = minilibx_mac
	LDFLAGS += -framework OpenGL -framework AppKit
else
	MLXDIR = minilibx_linux
	LDFLAGS += -lXext -lX11 -lbsd
endif

LIBFT	= $(LIBDIR)/libft.a
MLX		= $(LIBDIR)/libmlx.a

CFILES	= mlx.c render.c hooks.c player.c map.c t_pos.c
MAIN	?= src/main.c
SRC		:= $(addprefix src/, $(CFILES)) $(MAIN)
OBJ		:= $(SRC:%.c=%.o)

INCLUDE	= -Iinclude -I$(MLXDIR) -Ilibft

LDFLAGS	+= -L$(LIBDIR) -lm -lmlx -lft

CFLAGS	+= -Wall -Wextra -Werror $(INCLUDE) 

all: $(LIBDIR) $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(LIBFT):
	make -C libft all && mv libft/libft.a $(LIBDIR)

$(MLX):
	make -C $(MLXDIR) all && mv $(MLXDIR)/libmlx.a $(LIBDIR)

debug: CFLAGS += -g -fsanitize=address -fsanitize=undefined
debug: all 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test debug
