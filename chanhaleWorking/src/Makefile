NAME=cub3d
all: $(NAME)


$(NAME):
	arch -x86_64 gcc -L../mlx -lmlx -framework OpenGL -framework AppKit *.c ./*/*.c ./*/*/*.c -o $(NAME)
