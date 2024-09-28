NAME 	= cub3D

LIBDIR	= $(PWD)/lib

LIBFT	= $(LIBDIR)/libft.a

MLX		= $(LIBDIR)/libmlx.a

CFILES = main.c mlx.c render.c hooks.c player.c map.c

SRC		= $(addprefix src/, $(CFILES))

OBJ		= $(SRC:%.c=%.o)

INCLUDE	= -Iinclude -Iminilibx -Ilibft

LDFLAGS	= -L$(LIBDIR) -lm -lmlx -lft

CFLAGS	= -Wall -Wextra -Werror $(INCLUDE) -g -fsanitize=address

all: $(LIBDIR) $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -framework OpenGL -framework AppKit

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR):
	mkdir $(LIBDIR)

$(LIBFT):
	make -C libft all && mv libft/libft.a $(LIBDIR)

$(MLX):
	make -C minilibx all && mv minilibx/libmlx.a $(LIBDIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
