NAME		:= cub3D
CC			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -g3
LIB_MLX		:= -Lmlx -lmlx -lXext -lX11 -lm -lz
LBSD        := $(pkg-config --libs libbsd)
SRCS_DIR	:= srcs
OBJS_DIR	:= .objs
INCS_DIR	:= incs

SRCS := main.c	                            \
		\
		reader/reader.c                     \
		reader/reader_init.c                \
		reader/reader_destroy.c             \
		reader/reader_utils.c               \
		\
		parser/cub3d_parser.c               \
		parser/parse_line.c                 \
		parser/parse_rgb.c                  \
		parser/parse_map.c                  \
		parser/check_char.c                 \
		parser/display.c                    \
		parser/destroy_self.c               \
		parser/parsing_errors.c             \
		\
		engine/mlx_utils.c                  \
		engine/start_game.c                 \
		engine/quit_game.c                  \
		engine/handle_keypress.c            \
		engine/handle_keyrelease.c          \
		engine/do_moving.c                  \
		engine/mlx_errors.c                 \
		engine/image_init.c                 \
		engine/minimap_init.c               \
		engine/minimap_update.c             \
		engine/render_init.c                \
		engine/render_reset.c               \
		engine/menu_init.c                  \
		engine/texture_load.c               \
		engine/render_update.c              \
		engine/render_math.c                \
		engine/engine_errors.c              \
		engine/set_pxl.c                    \
		\
		utils/report_error.c                \
		utils/str_cmp.c                     \
		utils/str_dup.c                     \
		utils/str_ndup.c                    \
		utils/str_len.c                     \
		utils/mem_cpy.c                     \
		utils/mem_set.c                     \
		utils/mem_cmp.c                     \
		utils/alloc.c                       \
		utils/re_alloc.c                    \
		utils/free_2d.c                     \
		utils/str_split.c                   \
		utils/split_elem_count.c            \
		utils/str_to_uint.c                 \
		utils/str_count_char.c              \
		utils/str_is_empty.c                \
		utils/str_basename.c                \
		utils/str_replace.c                 \
		utils/clamp.c                       \


