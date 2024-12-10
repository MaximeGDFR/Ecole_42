/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/10 15:46:58 by maximegdfr       ###   ########.fr       */
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
# define MENU_WIDTH 900
# define MENU_HEIGHT 1800

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
# define VIOLET	0x8A2BE2

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

typedef enum e_view
{
	FRONT_VIEW = 1,
	BACK_VIEW = 2,
	TOP_VIEW = 3,
	UNDER_VIEW = 4,
	RIGHT_VIEW = 5,
	LEFT_VIEW = 6,
	ISO_VIEW = 7,
	PERSPECTIVE_VIEW = 8,
	OBLIQUE_VIEW = 9,
	DIMETRIC_VIEW = 10,
	TRIMETRIC_VIEW = 11
}	t_view;

typedef struct s_bitmap
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_bitmap;

typedef struct s_menu
{
	char	*instructions[14];
}	t_menu;

typedef struct s_colors
{
	int	color_1;
	int	color_2;
	int	cycle;
	int	use_gradient;
}	t_colors;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		height;
	int		width;
	int		tile_size;
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	int		drawing_width;
	int		drawing_height;
	int		z_min;
	int		z_max;
	int		x_offset;
	int		y_offset;
	int		x_center_offset;
	int		y_center_offset;
	float	x_center;
	float	y_center;
	float	window_width_center;
	float	window_height_center;
	float	scale;
	t_view	current_view;
}	t_map;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

typedef struct s_mouse
{
	int	button;
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
}	t_mouse;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_menu		*menu;
	t_colors	*colors;
	int			menu_opened;
	t_bitmap	bitmap;
}	t_data;

/* Valids Functions */
void		start_program(t_data *data, char *filename);
t_map		*load_map(char *filename);
int			check_file_format(char *filename);
void		set_map(t_map *map);
void		init_data(t_data *data, char *filename);
int			get_height(char *filename);
int			get_width(char *filename);
void		allocate_matrix(t_map *map);
void		fill_matrix(char *filename, t_map *map);
void		fill_row(t_map *map, char *line, int y);
void		get_z_min_max(char *line, t_map *map);
void		calculate_scale(t_map *map);
void		change_projection(t_point *point, t_map *map);
void		change_view(t_map *map);
void		center_map(t_map *map);
void		apply_center(t_map *map);
void		apply_projection(t_map *map);
void		update_map_limits(t_map *map, int x, int y);
int			get_sign(int value);
void		update_coordinates(t_bresenham *bresenham, int *x, int *y);
void		draw_line_bresenham(t_data *data, t_point p1, t_point p2);
void		draw_line_bitmap(t_data *data, t_map *map, int x, int y);
void		draw_map(t_data *data, t_map *map);
void		projection_top(t_point *point, t_map *map);
void		projection_under(t_point *point, t_map *map);
void		project_right(t_point *point, t_map *map);
void		project_left(t_point *point, t_map *map);
void		project_front(t_point *point, t_map *map);
void		projection_back(t_point *point, t_map *map);
void		projection_iso(t_point *point, t_map *map);
void		projection_perspective(t_point *point, float d);
void		projection_oblique(t_point *point, float angle, float reduction);
void		projection_dimetric(t_point *point);
void		projection_trimetric(t_point *point, float alpha, float beta,
				float gamma);
void		redraw_map(t_data *data, int menu_opened);
void		reset_map(t_data *data, int menu_opened);
void		change_map(t_data *data, int menu_opened);
int			handle_moves(int keycode, void *param);
int			handle_map(int keycode, void *param);
int			handle_scale(int keycode, void *param);
int			handle_bonus(int keycode, void *param);
int			handle_controls(int keycode, void *param);
int			ft_abs(int value);
void		handle_error(char *msg_err, int syst_funct);
void		free_values(char **values);
void		free_map(t_map *map);
void		*free_lines(int fd);
int			close_window(t_data *data);

void		init_bitmap(t_data *data, int width, int height);
void		draw_pixel(t_bitmap *bitmap, int x, int y, int color);
void		draw_line_bresenham(t_data *data, t_point p1, t_point p2);
void		draw_line_bitmap(t_data *data, t_map *map, int x, int y);
void		draw_map(t_data *data, t_map *map);




t_colors	*init_colors(void);
int			calculate_gradient(t_point p1, t_point p2, int current_step,
				int total_steps);
int			calculate_color(int z, t_map *map);
int			interpolate_color(int start, int end, double percentage);
int			modify_color(int color, char component, int new_value);
int			inverted_color(int color);
void		change_gradients(t_data *data, int keycode);
void		change_colors(t_data *data, int keycode);
void		apply_single_color_to_drawing(t_data *data);

#endif