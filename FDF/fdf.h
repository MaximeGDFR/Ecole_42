/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodefro <mgodefro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/12 15:52:06 by mgodefro         ###   ########.fr       */
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
# define PLUS_KEY // Zoom
# define G_KEY 103 // Gradients
# define H_KEY 104 // Menu help
# define MINUS_KEY // Dezoom
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
	int	***matrix;
	int	z_min;
	int	z_max;
	int	x_max;
	int	y_max;
	int	color_mode;
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
/* check_map.c */
int		get_height(char *filename);
int		get_width(char *filename);
void	get_z_min_max(char *line, t_map *map);
void	fill_matrix(int **row, char *line, int width);
void	check_map(char *filename, t_map *map);
/* color.c */
void	earth_mode_color(t_point *point, t_env *env);
/* controls.c */
/* draw_map.c */
void	draw_pixel(t_point point, t_env *env);
void	update_coordinates(t_algorithm *bresenham, int *x, int *y);
void	draw_line_bresenham(t_env *env, t_point p1, t_point p2);
void	draw_lines(t_env *env, int x, int y);
void	draw_map(t_env *env);
/* draw_menu.c */
void	init_menu(t_menu *menu);
void	write_menu(t_menu *menu);
/* init_program.c */
t_env	*init_env(char *filename);
t_cam	*init_cam(t_env *env);
t_map	*init_map(void);
/* menu_infos.c */
void	display_projection_infos(t_menu *menu, int *current_line);
void	display_map_infos(t_menu *menu, int *current_line);
void	display_fdf_keyboards(t_menu *menu, int *current_line);
void	display_fdf_mouse(t_menu *menu, int *current_line);
/* mouse.c */
int		mouse_down(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
void	mouse_up(int button, int x, int y, void *param);
void	mouse_zoom(int button, t_env *env);
void	handle_mouse(t_env *env);
/* rotation_cam.c */
void	rotate_x(int *y, int *z, double x_angle);
void	rotate_y(int *x, int *z, double y_angle);
void	rotate_z(int *x, int *y, double z_angle);
t_point	projection(int x, int y, t_env *env);
/* utilitary_functions.c */
int		check_file_format(char *filename);
void	check_open_file(int fd, char *filename);
int		get_sign(int value);
int		get_position(t_menu *menu, int line_num);



#endif
