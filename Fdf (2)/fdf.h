/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/11 21:34:39 by maximegdfr       ###   ########.fr       */
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
# define MENU_PADDING 10
# define MENU_WIDTH 150
# define MENU_HEIGHT 500

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
# define P_KEY 112 // Zoom
# define G_KEY 103 // Gradients
# define H_KEY 104 // Menu help
# define M_KEY 109 // Dezoom
# define C_KEY 99 // Colors
# define R_KEY 114 // Rotation
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

/* Views */
# define SCALE 0.75
# define DIMETRIC_ANGLE_X 45.0
# define DIMETRIC_ANGLE_Y 30.0
# define OBLIQUE_REDUCTION 0.5
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/* Colors */
# define RED	0xFF0000
# define ORANGE	0xFFA500
# define YELLOW	0xFFFF00
# define GREEN	0x008000
# define BLUE	0x0000FF
# define INDIGO	0x4B0082
# define PURPLE	0x8A2BE2
# define WHITE	0xFFFFFF
# define BLACK	0x000000

/* Gradients */
# define SUNSET_START			0xFF4500
# define SUNSET_END				0x8B0000
# define OCEAN_START			0x000080
# define OCEAN_END				0x00BFFF
# define FOREST_START			0x228B22
# define FOREST_END				0x006400
# define FIRE_START				0xFF4500
# define FIRE_END				0xFF6347
# define MORNINGSKY_START		0x87CEEB
# define MORNINGSKY_END			0x1E90FF
# define PURPLEHORIZON_START	0x8A2BE2
# define PURPLEHORIZON_END		0x4B0082
# define PINKOCEAN_START		0xFF69B4
# define PINKOCEAN_END			0xBA55D3
# define GREYHORIZON_START		0xA9A9A9
# define GREYHORIZON_END		0x696969

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

/* Structurs */
typedef enum e_view
{
	FRONT_VIEW = 1,
	BACK_VIEW,
	TOP_VIEW,
	UNDER_VIEW,
	RIGHT_VIEW,
	LEFT_VIEW,
	ISO_VIEW,
	PERSPECTIVE_VIEW,
	OBLIQUE_VIEW,
	DIMETRIC_VIEW,
	TRIMETRIC_VIEW
}	t_view;

typedef enum e_colors
{
	SOLID_WHITE = 1,
	SOLID_RED,
	SOLID_ORANGE,
	SOLID_YELLOW,
	SOLID_GREEN,
	SOLID_BLUE,
	SOLID_INDIGO,
	SOLID_PURPLE,
	SUNSET_GRADIENT,
	OCEAN_GRADIENT,
	FOREST_GRADIENT,
	FIRE_GRADIENT,
	MORNINGSKY_GRADIENT,
	PURPLEHORIZON_GRADIENT,
	PINKOCEAN_GRADIENT,
	GREYHORIZON_GRADIENT
}	t_colors;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_bresenham
{
	int	err;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_bresenham;

typedef struct s_image
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
	t_point		**points;
	t_bresenham	bresenham;
	t_colors	color_mode;
	t_point		point;
	int			width;
	int			height;
	int			current_view;
	double		zoom;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		scale;
	int			x_min;
	int			x_max;
	int			y_min;
	int			y_max;
	int			z_min;
	int			z_max;
	int			x_offset;
	int			y_offset;
	int			drawing_width;
	int			drawing_height;
	int			x_center_offset;
	int			y_center_offset;
	float		x_center;
	float		y_center;
	float		win_width_center;
	float		win_height_center;
	int			tile_size;
}	t_env;

/* Functions */
/* ajust_map.c */
void	calculate_scale(t_env *env);
void	center_map(t_env *env);
void	apply_center(t_env *env);
void	update_map_limits(t_env *env, int x, int y);
/* change_map.c */
void	redraw_map(t_env *env);
void	change_map(t_env *env);
void	reset_map(t_env *env);
void	clear_image(t_env *env);
/* controls.c */
int		handle_bonus(int keycode, t_env *env);
int		handle_moves(int keycode, t_env *env);
int		handle_map(int keycode, t_env *env);
int		handle_scale(int keycode, t_env *env);
int		key_controls(int keycode, t_env *env);
/* draw_map.c */
void	update_coordinates(t_bresenham *bresenham, int *x, int *y);
void	put_pixel(t_point points, t_env *env);
void	draw_line_bresenham(t_env *env, t_point p1, t_point p2);
void	draw_lines(t_env *env, int x, int y);
void	draw_map(t_env *env);
/* exit_program.c */
int		close_window(t_env *env);
void	handle_error(char *msg_err, int syst_funct);
/* initialize_program.c */
void	init_program(t_env *env, char *filename);
void	init_point_bresenham(t_point *point, t_bresenham *bresenham);
void	init_image(t_image *image);
void	init_env_first(t_env *env, char *filename);
void	init_env_second(t_env *env);
/* load_map.c */
void	allocate_matrix(t_env *env);
void	fill_matrix(char *filename, t_env *env);
void	fill_row(t_env *env, char *line, int y);
/* menu.c */
/* mouse.c */
/* projection_2d.c*/
void	project_front(t_point *point, t_env *env);
void	projection_back(t_point *point, t_env *env);
void	projection_top(t_point *point, t_env *env);
void	projection_under(t_point *point, t_env *env);
void	project_right(t_point *point, t_env *env);
/* projection_3d.c */
void	projection_iso(t_point *point, t_env *env);
void	projection_perspective(t_point *point, float d);
void	projection_oblique(t_point *point, float angle, float reduction);
void	projection_dimetric(t_point *point);
void	projection_trimetric(t_point *point, float alpha,
			float beta, float gamma);
/* projection_utils.c */
void	clip_point(t_point *point);
void	change_projection(t_point *point, t_env *env);
void	change_view(t_env *env);
void	apply_projection(t_env *env);
void	project_left(t_point *point, t_env *env);
/* read_map.c */
int		check_file_format(char *filename);
int		get_height(char *filename);
int		get_width(char *filename);
void	get_z_min_max(char *line, t_env *env);
/* utils.c */
int		get_sign(int value);
int		ft_abs(int value);
void	free_points(t_env *env);
void	*free_lines(int fd);
void	free_values(char **values);
/*
int		interpolate_color(int start_color, int end_color, float ratio);
int		calculate_color(int z, t_env *env, t_colors color_mode);
void	get_gradient_colors(t_env *env, int *start_color, int *end_color);
*/
int calculate_color(int z, t_env *env, int color_mode);

#endif
