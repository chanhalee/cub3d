NAME	=	cub3d

SRCS	= 	./main.c \
			util/chanhale_util/get_distance.c \
			util/chanhale_util/keep_distance_with_wall.c \
			util/chanhale_util/simple_mlx_get_data_addr.c \
			util/chanhale_util/variable_control/free_chanhale_assets.c \
			util/chanhale_util/variable_control/init_chanhale_assets.c \
			util/chanhale_util/variable_control/init_game.c \
			util/chanhale_util/variable_control/init_t_render_source.c \
			util/minhekim_util/free.c \
			util/minhekim_util/ft_calloc.c \
			util/minhekim_util/ft_memset.c \
			util/minhekim_util/ft_split.c \
			util/minhekim_util/ft_strlcpy.c \
			util/minhekim_util/get_next_line_utils.c \
			util/minhekim_util/get_next_line.c \
			util/minhekim_util/get_next_line2.c \
			util/minhekim_util/str.c \
			util/minhekim_util/string_utils.c \
			util/minhekim_util/init_img.c \
			ray_casting/ray_casting.c \
			parse/check_valid_map.c \
			parse/get_texture.c \
			parse/parse_utils.c \
			parse/parse.c \
			hooks/exit_hook.c \
			hooks/key_hook.c


OBJS	= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(SRCS)
			arch -x86_64 $(CC) $(CFLAGS) -c -o $@ $<

all:		$(NAME)

$(NAME):	$(OBJS)
			arch -x86_64 $(CC) $(CFLAGS) -L../mlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
