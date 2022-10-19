include cub3d.mk

SRCS_OBJS := $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@mkdir -vp $(dir $@)
	$(CC) $(CFLAGS) -g3 -MMD -MP -o $@ -c $< -I $(INCS_DIR)

all: $(NAME)

-include  $(SRCS_OBJS:.o=.d)

$(NAME): $(SRCS_OBJS)
	$(MAKE) -C mlx/
	$(CC) $(LBSD) $(CFLAGS) $^ -o $(NAME) $(LIB_MLX) -lm

test: all
	@bash tester/tester.sh

clean:
	rm -f $(SRCS_OBJS)

fclean: clean
	$(MAKE) clean -C mlx/
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

re: fclean all

.PHONY	: all clean fclean re
