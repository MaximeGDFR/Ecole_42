/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/13 17:02:49 by maximegdfr       ###   ########.fr       */
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
# define ENTER 65293 // Center map
# define BACKSPACE 65288 // Reset
# define I_KEY 105 // Infos
# define PLUS_KEY 21 // Zoom in
# define P_KEY 112 // Zoom in
# define M_KEY 109 // Zoom out
# define G_KEY 103 // Gradients
# define H_KEY 104 // Menu help
# define MINUS_KEY 15 // Zoom out
# define C_KEY 99 // Colors
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_WHEEL_UP 3
# define MOUSE_WHEEL_DOWN 4

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
	INDIGO = 0x4B0082,
	PURPLE = 0x8A2BE2
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
	int	height;
	int	width;
	int	**matrix;
	int	z_min;
	int	z_max;
	int	x_max;
	int	y_max;
	int	color_mode;
	int	current_view;
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

typedef struct s_mouse
{
	int	button;
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
}	t_mouse;

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
	t_map	*map;
	t_cam	*cam;
	t_mouse	*mouse;
	t_point	**points;
	t_menu	*menu;
}	t_env;

/* Functions */
/* change_color.c*/
void	apply_color_mode(t_point *point, t_env *env);
void	apply_uni_color(t_point *point, t_env *env);
void	apply_specific_color(t_point *point, t_env *env);
/* change_projection.c */
void	change_projection(t_point *point, t_env *env);
t_point	**allocate_projected_points(t_env *env);
t_point	**apply_projection(t_env *env);
void	free_projected_points(t_point **projected_points, int height);
/* check_map.c */
int		get_height(char *filename);
int		get_width(char *filename);
void	allocate_matrix(t_map *map);
void	fill_matrix(t_env *env, char *line, int y);
//void	get_z_min_max(t_map *map);
void	check_map(char *filename, t_env *env);
/* close.c */
int		quit_program(t_env *env);
void	handle_error(char *msg_err, int syst_funct);
/* colors_specifics.c */
void	earth_mode_color(t_point *point, t_env *env);
/* controls.c */
void	reset(t_env *env);
void	handle_zoom(int keycode, t_env *env);
void	handle_moves(int keycode, t_env *env);
void	handle_keyboards(int keycode, t_env *env);
int		keyboards_controls(int keycode, t_env *env);
void	hook_controls(t_env *env);
/* draw_map.c */
void	draw_pixel(t_point point, t_env *env);
void	update_coordinates(t_algorithm *bresenham, int *x, int *y);
void	draw_line_bresenham(t_env *env, t_point p1, t_point p2);
void	draw_lines(int x1, int x2, int y1, int y2, t_env *env);
void	draw_map(t_env *env);
/* draw_menu.c */
void	init_menu(t_menu *menu);
void	write_menu(t_menu *menu);
/* init_program.c */
//t_env	*init_env(char *filename);
//t_cam	*init_cam(t_env *env);
//t_map	*init_map(void);

t_env *init_env(char *filename);
t_map *init_map(void);
t_cam *init_cam(t_env *env, char *filename);
t_mouse *init_mouse(void);


/* menu_infos.c */
void	display_projection_infos(t_menu *menu, int *current_line);
void	display_map_infos(t_menu *menu, int *current_line);
void	display_fdf_keyboards(t_menu *menu, int *current_line);
void	display_fdf_mouse(t_menu *menu, int *current_line);
/* mouse.c */
int		mouse_down(int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		mouse_up(int x, int y, void *param);
void	mouse_zoom(t_env *env);
int		handle_mouse(t_env *env);
/* projection_2d.c */
void	projection_front(t_point *point, t_env *env);
void	projection_top(t_point *point, t_env *env);
void	projection_right(t_point *point, t_env *env);
void	projection_left(t_point *point, t_env *env);
/* projection_3d.c */
void	projection_iso(t_point *point, t_env *env);
void	projection_perspective(t_point *point, float d);
void	projection_oblique(t_point *point, float angle, float reduction);
/* rotation_cam.c */
void	rotate_x(int *y, int *z, double x_angle);
void	rotate_y(int *x, int *z, double y_angle);
void	rotate_z(int *x, int *y, double z_angle);
void	apply_camera_transformation(t_point *point, t_env *env);
t_point	projection(int x, int y, t_env *env);
/* utility_functions.c */
int		check_file_format(char *filename);
int		get_sign(int value);
int		get_position(t_menu *menu, int line_num);
int		ft_min(int a, int b);
int		ft_abs(int value);
void	free_values(char **values);

#endif