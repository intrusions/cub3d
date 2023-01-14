/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:07:04 by pducos            #+#    #+#             */
/*   Updated: 2023/01/09 18:11:15 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ========================================================================= //
//                                   Library                                 //
// ========================================================================= //

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

// ========================================================================= //
//                                   Define                                  //
// ========================================================================= //

// global
# define PROG_NAME       "cub3D"
# define DESC_FILE_MAX      8192
# define MAX_MAP_SIZE       4096
# define RGB_CEIL_ID           0
# define RGB_FLOOR_ID          1

// configuration
# define WINDOW_X           1280
# define WINDOW_Y            720
# define MINIMAP_X           300
# define MINIMAP_Y           170
# define RENDER_X            (WINDOW_X - MINIMAP_X + 10)
# define RENDER_Y            (WINDOW_Y)
# define SPEED               128
# define SENSITIVITY       0.005
# define CUBE_SIZE            14

// colors
# define RENDER_BG_RGB       0x808080
# define MENU_BG_RGB         0x34302F
# define MINIMAP_SPACE_RGB   0x828282
# define MINIMAP_BG_RGB      0x3a3a3a
# define MINIMAP_GUIDES_RGB  0x9A1818
# define V_WALL_RGB          0x7F3335
# define H_WALL_RGB          0x99585C

// keys
# define KEY_W	       119
# define KEY_A	        97
# define KEY_S	       115
# define KEY_D	       100
# define KEY_ESC     65307
# define KEY_UP	     65362
# define KEY_DOWN    65364
# define KEY_LEFT    65361
# define KEY_RIGHT   65363
// parsing errors
# define E_INVALID_NO        0x1
# define E_INVALID_SO        0x2
# define E_INVALID_WE        0x4
# define E_INVALID_EA        0x8
# define E_INVALID_C        0x10
# define E_INVALID_F        0x20
# define E_MAP_EMPTY        0x40
# define E_PLAYER_NUM       0x80
# define E_NO_PLAYERS      0x100
# define E_INVALID_CHAR    0x200
# define E_DESC_TOO_LARGE  0x400
# define E_MAP_TOO_LARGE   0x800
# define E_OPEN_MAP       0x1000
# define E_RGB_FIELD_C    0x2000
# define E_RGB_FIELD_F    0x4000
# define E_NO_404         0x8000
# define E_SO_404         0x10000
# define E_EA_404         0x20000
# define E_WE_404         0x40000

// game errors
# define E_MLX_INIT     0x1
# define E_MLX_WIN      0x2
# define E_IMG_INIT     0x4

// ========================================================================= //
//                                 Structure                                 //
// ========================================================================= //

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct	s_floatxy
{
	float	x;
	float	y;
}	t_floatxy;

typedef struct	s_intxy
{
	int	x;
	int	y;
}	t_intxy;

typedef struct s_player {
	t_intxy	pos;
	char	val;
}	t_player;

typedef struct s_img {
	int		width;
	int		height;
	void	*img;
	int		*data;
}	t_img;

typedef struct s_keys {
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
	bool	shift;
	bool	space;
}	t_keys;

typedef struct	s_display {
	struct {
		t_img	minimap;
		t_img	map;
		t_intxy	loc;
	}	minimap;
	t_img		screen;
	t_img		menu;
	struct {
		float	x;
		float	y;
		float	a;
	}	player;
}	t_display;

typedef struct	s_ray {
	t_floatxy	pos;
	t_floatxy	dir;
	t_floatxy	delta;
	t_floatxy	len;
	t_intxy		map;
	t_intxy		step;
	float		line_len;
	float		current_angle;
	float		wall_x;
	int			side;
}	t_ray;

typedef struct	s_gui {
	uint32_t	error;
	void		*mlx;
	void		*win;
	t_display	display;
}	t_gui;

typedef struct	s_texture {
	char	*name;
	t_img	image;
}	t_texture;


typedef struct s_self {
	char		*filename;
	uint32_t	error;
	struct	s_scene {
		struct s_wall {
			t_texture	no;
			t_texture	so;
			t_texture	we;
			t_texture	ea;
		}	wall;
		t_rgb	ceil;
		t_rgb	floor;
	}	scene;
	struct s_map {
		char		**line;
		int			*line_size;
		int			max;
		size_t		size;
		t_player	cur_p;
	}	map;
	t_gui	mlx;
	t_keys	keys;
}	t_self;

// ========================================================================= //
//                                  Parsing                                  //
// ========================================================================= //

bool	cub3d_parser(t_self *self, char *file_name);
void	parse_line(unsigned char *line, t_self *self);
bool	parse_rgb(t_self *self, const char *str, int type);
void	parse_map(t_self *self);
bool	is_player(char c);
bool	check_adjacent(t_self *self, int x, int y);
bool	char_ok(char c, t_self *self);
void	destroy_self(t_self *self);
void	parsing_errors(t_self *self);
void	display_map(char **map, size_t map_size);

// ========================================================================= //
//                                   Engine                                  //
// ========================================================================= //

void	wrap_mlx_init(t_gui *mlx, int x, int y, char *title);
void	start_game(t_self *self);
int		handle_keypress(long k, t_self *self);
int		handle_keyrelease(long k, t_self *self);
void	do_moving(t_self *self);
void	mlx_errors(int error);
int     quit_game(t_gui *mlx);
void	mlx_destroy(t_self *self);

bool    image_init(t_gui *mlx, t_img *img, int x, int y);
bool	texture_load(t_self *self);
void    image_reset(t_img *img, int color);
void    image_display(t_gui *mlx, t_img *img, int x, int y);
bool    minimap_init(t_self *self);
void    minimap_update(t_self *self);
bool	render_init(t_self *self);
void	render_reset(t_img *img, t_rgb *ceil, t_rgb *floor);
void	render_update(t_self *self);
bool	menu_init(t_self *self);
void	set_x_pxls(t_img *img, t_intxy pos, int n, int color);
void	engine_errors(t_self *self);

void	set_pxl(t_img *img, int x, int y, int color);

// render_math
void	compute_initial_values(t_ray *r);
void	init_ray(t_ray *r);
void	perform_dda(t_ray *r);
void	determine_line_length(t_ray *r, t_self *self);
void	draw_line_from_texture(t_ray *r, t_self *self, int i);

//
void	drawline(t_img *screen, t_img *texture, t_ray *r, int i);

// ========================================================================= //
//                                    Utils                                  //
// ========================================================================= //

void	report_error(const char *s, ...);
size_t	str_len(const char *s);
int		str_cmp(const char *a, const char *b);
char	*str_dup(const char *str);
char	*str_ndup(const char *str, size_t size);
char	**str_split(char const *s, char *sep);
int		split_elem_count(char **split);
void	free_2d(char **arr);
bool	alloc(void **ptr, size_t size);
bool	re_alloc(void **buf, size_t *cap, size_t len, size_t new_cap);
void	*mem_cpy(void *dst, const void *src, size_t n);
void	*mem_set(void *m, int c, size_t size);
char	*str_to_uint(char *str, int *result);
size_t	str_count_char(const char *str, char c);
bool	str_is_empty(unsigned char *str);
char	*str_basename(char *str);
void	str_replace(char *str, char to_replace, char by);
int		clamp(int n, int min, int max);

#endif /* cub3d.h */
