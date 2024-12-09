/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:06:08 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/09 17:27:43 by maximegdfr       ###   ########.fr       */
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
# define M_KEY 109 // Dezoom
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

typedef struct s_menu
{
	char	*title;
	char	*command_a;
	char	*command_b;
	char	*command_c;
	char	*command_d;
	char	*command_e;
	char	*command_f;
	char	*command_g;
	char	*command_h;
	char	*command_i;
	char	*command_j;
	char	*command_k;
	char	*command_l;
	char	*command_m;
	char	*command_n;
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
}	t_data;


t_map	*load_map(char *filename);

	int		check_file_format(char *filename);
void set_map(t_map *map);


void print_bounds(t_map *map);

		t_menu	*init_menu(void);
		t_colors	*init_colors(void);
		void	calculate_scale(t_map *map);
		int		get_height(char *filename);
		int		get_width(char *filename);
		void	get_z_min_max(char *line, t_map *map);
		void	fill_row(t_map *map, char *line, int y);
		void	fill_matrix(char *filename, t_map *map);

void	allocate_matrix(t_map *map);



void	update_map_limits(t_map *map, int x, int y);

void	init_data(t_data *data, char *filename);


void	change_projection(t_point *point, t_map *map);
void apply_projection(t_map *map);



void	free_map(t_map *map);
int		close_window(t_data *data);

void	reset_map(t_data *data, int menu_opened);

/* Map Functions */
void	menu_background(void *mlx, void *win);
void	open_menu(void *mlx, void *win, t_menu *menu);
int		get_text_width(const char *text);

int		display_command(void *mlx, void *win, char *command, int y);


void	apply_center(t_map *map);



int		get_sign(int value);
void	update_coordinates(t_bresenham *bresenham, int *x, int *y);
void draw_line_bresenham(t_data *data, t_point p1, t_point p2);

void	center_map(t_map *map);
void	draw_lines(t_data *data, t_map *map, int x, int y);
void	draw_map(t_data *data, t_map *map);
void	geometric_center(t_map *map);
int calculate_gradient(t_point p1, t_point p2, int current_step, int total_steps);

/* Views Functions */
void	change_view(t_map *map);

void	redraw_map(t_data *data, int menu_opened);
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


int	handle_moves(int keycode, void *param);
int	handle_map(int keycode, void *param);
int	handle_scale(int keycode, void *param);
int	handle_bonus(int keycode, void *param);
int	handle_controls(int keycode, void *param);

/* Colors Functions */
int		calculate_color(int z, t_map *map);
int		interpolate_color(int start, int end, double percentage);
int		modify_color(int color, char component, int new_value);
int		inverted_color(int color);
void change_gradients(t_data *data, int keycode);
void change_colors(t_data *data, int keycode);
void apply_single_color_to_drawing(t_data *data);

void	change_map(t_data *data, int menu_opened);


/* Others Functions */

int		ft_abs(int value);
void	handle_error(char *msg_err, int syst_funct);
void	free_values(char **values);

#endif