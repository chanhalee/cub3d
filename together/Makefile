NAME	=	cub3D

SRCS	= 	src/main.c \
			src/util/chanhale_util/get_distance.c \
			src/util/chanhale_util/keep_distance_with_wall.c \
			src/util/chanhale_util/simple_mlx_get_data_addr.c \
			src/util/chanhale_util/variable_control/free_chanhale_assets.c \
			src/util/chanhale_util/variable_control/init_chanhale_assets.c \
			src/util/chanhale_util/variable_control/init_game.c \
			src/util/chanhale_util/variable_control/init_t_render_source.c \
			src/util/minhekim_util/free.c \
			src/util/minhekim_util/ft_calloc.c \
			src/util/minhekim_util/ft_memset.c \
			src/util/minhekim_util/ft_split.c \
			src/util/minhekim_util/ft_strlcpy.c \
			src/util/minhekim_util/get_next_line_utils.c \
			src/util/minhekim_util/get_next_line.c \
			src/util/minhekim_util/get_next_line2.c \
			src/util/minhekim_util/str.c \
			src/util/minhekim_util/string_utils.c \
			src/util/minhekim_util/init_img.c \
			src/util/minhekim_util/error.c \
			src/ray_casting/ray_casting.c \
			src/parse/check_valid_map.c \
			src/parse/check_texname.c \
			src/parse/get_texture.c \
			src/parse/parse_utils.c \
			src/parse/parse.c \
			src/hooks/exit_hook.c \
			src/hooks/key_hook.c


OBJS	= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(SRCS)
			$(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

bonus:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
