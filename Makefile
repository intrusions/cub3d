SRCS		=	./cub3d.c \
				./srcs/parsing/start_parsing.c \
				./srcs/parsing/parse_name_and_get_file.c \
				./srcs/utils/errors.c \
				./srcs/utils/get_next_line.c \
				./srcs/utils/get_next_line_utils.c \

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -g3 -I./includes

NAME		= 	cub3d
	
MLX			= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus