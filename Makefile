NAME 	= cub3D

LIBDIR	= $(PWD)/lib

ifeq ($(OS), darwin)
	MLXDIR = minilibx_mac
	LDFLAGS += -framework OpenGL -framework AppKit
else
	MLXDIR = minilibx_linux
	LDFLAGS += -lXext -lX11 -lbsd
endif

LIBFT	= $(LIBDIR)/libft.a
MLX		= $(LIBDIR)/libmlx.a

CFILES = main.c mlx.c render.c hooks.c player.c map.c
SRC		= $(addprefix src/, $(CFILES))
OBJ		= $(SRC:%.c=%.o)

INCLUDE	= -Iinclude -I$(MLXDIR) -Ilibft

LDFLAGS	+= -L$(LIBDIR) -lm -lmlx -lft

CFLAGS	= -Wall -Wextra -Werror $(INCLUDE) -g -fsanitize=address


all: $(LIBDIR) $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR):
	mkdir $(LIBDIR)

$(LIBFT):
	make -C libft all && mv libft/libft.a $(LIBDIR)

$(MLX):
	make -C $(MLXDIR) all && mv $(MLXDIR)/libmlx.a $(LIBDIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
