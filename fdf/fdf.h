/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/07 15:31:32 by maximegdfr       ###   ########.fr       */
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

/* Hook */
# define UP 65362 // Mouve up
# define DOWN 65364 // Mouve down
# define LEFT 65361 // Mouve left
# define RIGHT 65363 // Mouve right
# define ESC 65307 // Close
# define SPACE 32 // Change view
# define ENTER 65293 // Center map
# define BACKSPACE 65288 // Reset
# define A_KEY 113
# define Z_KEY 119
# define E_KEY 101
# define R_KEY 114
# define T_KEY 116
# define Y_KEY 121
# define U_KEY 117
# define I_KEY 105 // Inversion color
# define O_KEY 111
# define P_KEY 112 // Zoom
# define Q_KEY 97
# define S_KEY 115
# define D_KEY 100
# define F_KEY 102
# define G_KEY 103
# define H_KEY 104 // Menu help
# define J_KEY 106
# define K_KEY 107
# define L_KEY 108
# define M_KEY 59 // Dezoom
# define W_KEY 122
# define X_KEY 120
# define C_KEY 99
# define V_KEY 118
# define B_KEY 98
# define N_KEY 110
# define H_KEY 104 
# define R_KEY 114 // Rotation
# define V_KEY 118
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 53

/* Views */
# define SCALE 0.5
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
	int		z_min;
	int		z_max;
	int		x_offset;
	int		y_offset;
	t_point	geometric_center;
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
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_data;

/* Main Functions */
void	free_map(t_map *map);
int		close_window(t_data *data);
t_map	*load_map(char *filename);
void	reset_map(t_data *data);

/* Map Functions */
void	calculate_scale(t_map *map);
void	calculate_projected_bounds(t_map *map, int *x_min, int *x_max, int *y_min, int *y_max);
int		get_height(char *filename);
int		get_width(char *filename);
void	get_z_min_max(char *line, t_map *map);
t_map	*init_map(char *filename);
void	fill_row(t_map *map, char *line, int y);
void	fill_matrix(char *filename, t_map *map);
int		get_sign(int value);
void	update_coordinates(t_bresenham *bresenham, int *x, int *y);
void	draw_line_bresenham(t_data *data, t_point p1, t_point p2, int color);
void	center_map(t_map *map);
void	draw_lines(t_data *data, t_map *map, int x, int y);
void	draw_map(t_data *data, t_map *map);
void	geometric_center(t_map *map);

/* Views Functions */
void	change_view(t_map *map);
void	apply_projection(t_point *point, t_map *map);
void	redraw_map(t_data *data);
void	projection_top(t_point *point, t_map *map);
void	projection_under(t_point *point, t_map *map);
void	project_right(t_point *point, t_map *map);
void	project_left(t_point *point, t_map *map);
void	project_front(t_point *point, t_map *map);
void	projection_back(t_point *point, t_map *map);
void	projection_iso(t_point *point, t_map *map);
void	projection_perspective(t_point *point, float d);
void	projection_oblique(t_point *point, float angle, float reduction);
void	projection_dimetric(t_point *point);
void	projection_trimetric(t_point *point, float alpha, float beta,
			float gamma);

/* Colors Functions */
int		calculate_color(int z, t_map *map);
int		interpolate_color(int start, int end, double percentage);
int		modify_color(int color, char component, int new_value);
int		inverted_color(int color);

/* Control Functions */
int		handle_controls(int keycode, void *param);

/* Others Functions */
int		check_file_format(char *filename);
int		ft_abs(int value);
void	handle_error(char *msg_err, int syst_funct);
void	free_values(char **values);

#endif