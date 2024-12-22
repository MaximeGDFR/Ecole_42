/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/22 17:22:22 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* Bool */
# define TRUE 1
# define FALSE 0

/* Window */
# define WIDTH 1920
# define HEIGHT 1080

/* Menu */
# define LINE_HEIGHT 20
# define TITLE_OFFSET 10
# define SECTION_SPACING 40
# define INFO_INDENT 20
# define AVG_CHAR_WIDTH 8

/* Hook */
# define UP 65362 // Mouve up
# define DOWN 65364 // Mouve down
# define LEFT 65361 // Mouve left
# define RIGHT 65363 // Mouve right
# define ESC 65307 // Close
# define SPACE 32 // Change view
# define BACKSPACE 65288 // Reset
# define PLUS 65453 // Zoom in
# define P 112 // Zoom in
# define M 109 // Zoom out
# define MINUS 65451 // Zoom out
# define C 99 // Colors
# define Z 122 // Z axis
# define CTRL 65507 // Rotations

/* Views */
# define DIMETRIC_ANGLE_X 45.0
# define DIMETRIC_ANGLE_Y 30.0
# define OBLIQUE_REDUCTION 0.5
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/* Library */
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/* Structs */
typedef enum e_view
{
	FRONT_VIEW = 1,
	TOP_VIEW,
	RIGHT_VIEW,
	LEFT_VIEW,
	ISO_VIEW,
	PERSPECTIVE_VIEW,
	OBLIQUE_VIEW
}	t_view;

typedef enum e_uni_colors
{
	WHITE = 0xFFFFFF,
	RED = 0xFF0000,
	ORANGE = 0xFFA500,
	YELLOW = 0xFFFF00,
	GREEN = 0x008000,
	BLUE = 0x0000FF,
	PURPLE = 0x8A2BE2,
	GREY = 0x808080,
}	t_uni_colors;

typedef enum e_colors // Inutile maintenant ?
{
	EARTH_MODE = 1,
	NEON_MODE,
	BOREAL_MODE,
	GREY_SHADE_MODE
}	t_colors;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
	int	reverse;
}	t_point;

typedef struct s_algorithm
{
	int	err;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_algorithm;

typedef struct s_map
{
	int		height;
	int		width;
	t_point	**matrix;
	int		z_min;
	int		z_max;
	int		x_max;
	int		y_max;
	int		centered;
	float	depth;
	int		color_mode;
	int		current_view;
}	t_map;

typedef struct s_cam
{
	int		zoom;
	int		x_offset;
	int		y_offset;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	double	z_height;
	int		iso;
}	t_cam;

typedef struct s_menu
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		pad_x;
	int		pad_y;
	int		x_center;
	int		x_left;
	int		color_background;
}	t_menu;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		steep;
	int		ctrl_pressed;
	t_map	*map;
	t_map	*original_map;
	t_cam	*cam;
	t_point	*points;
	t_menu	*menu;
}	t_env;

/* Functions */
/* change_color.c*/
void	apply_color_mode(t_env *env, t_point *point);
void	apply_uni_color(t_env *env, t_point *point);
void	apply_specific_color(t_env *env, t_point *point);
void	update_colors(t_env *env);

/* close.c */
int		quit_program(t_env *env);
void	handle_error(char *msg_err, int syst_funct);

/* colors_specifics.c */
void	earth_mode_color(t_env *env, t_point *point);
void	neon_mode_color(t_env *env, t_point *point);
void	jinx_mode_color(t_env *env, t_point *point);
void	charizard_mode_color(t_env *env, t_point *point);

/* controls.c */
void	handle_zoom(int keycode, t_env *env);
void	handle_moves(int keycode, t_env *env);
void	handle_keyboards(int keycode, t_env *env);
int		keyboards_controls(int keycode, t_env *env, t_point *point);
void	handle_rotations(int keycode, t_env *env);
int		key_release(int keycode, t_env *env);
void	handle_colors(int keycode, t_env *env, t_point *point);
void	handle_views(int keycode, t_env *env);
void	reset(t_env *env);
void	reset_values(t_env *env);

/* draw_map.c */
void	update_coordinates(t_algorithm *bresenham, int *x, int *y);
void	put_pixel(t_point *point, t_env *env);
void	draw_line_bresenham(t_env *env, t_point p1, t_point p2);
void	draw_lines(t_env *env, int x, int y);
void	draw_map(t_env *env);
void	free_projected_points(t_point **projected_points, int height);
void	change_projection(t_point *point, t_env *env);
void	center_map(t_env *env);
t_point	**allocate_projected_points(t_env *env);
t_point	**apply_projection(t_env *env);
void	calculate_depth(t_env *env);
void	apply_centered(t_env *env, t_point **projected_points);
void	projection_isometric(t_point *point, t_env *env);

/* draw_menu.c */
t_menu	*init_menu(t_env *env);
void	draw_menu(t_env *env);

/* init_program.c */
t_env	*init_environnement(char *filename);
t_point	*init_point(void);
t_map	*init_map(char *filename);
t_cam	*init_cam(t_map *map);
void	allocate_map_matrix(t_map *map);
int		get_height(char *filename);
int		count_values(char *line);
int		get_width(char *filename);
int		compare_line(int first_line_width, int current_width);
char	**read_file_to_matrix(t_map *map, char *filename, int *line_count);
void	fill_matrix(t_map *map, char **lines);
t_map	*get_values_map(t_map *map);
void	setup_hooks(t_env *env);

/* menu_infos.c */
int		display_projection_infos(t_env *env, int *current_line);
void	display_map_infos(t_env *env, int *current_line);
void	display_fdf_keyboards(t_env *env, int *current_line);

/* projection_2d.c */
void	projection_front(t_point *point, t_env *env);
void	projection_top(t_point *point, t_env *env);
void	projection_right(t_point *point, t_env *env);
void	projection_left(t_point *point, t_env *env);

/* projection_3d.c */
void	projection_iso(t_point *point, t_env *env);
void	projection_perspective(t_env *env, t_point *point, float d);
void	projection_oblique(t_env *env, t_point *point, float angle,
			float reduction);

/* reset.c */
void	save_map(t_env *env);
void	save_values_map(t_env *env);
void	reset_values(t_env *env);
void	reset(t_env *env);

/* rotation_cam.c */
void	rotate_right(t_env *env);
void	rotate_left(t_env *env);
void	rotate_up(t_env *env);
void	rotate_down(t_env *env);
void	rotate_reverse_z(t_env *env);
void	rotate_z(t_env *env);

/* utility_functions.c */
int		check_file_format(char *filename);
int		get_sign(int value);
int		get_position(t_menu *menu, int line_num);
int		ft_min(int a, int b);
int		ft_abs(int value);
void	free_values(char **values);
void	free_map(t_env *env);

#endif