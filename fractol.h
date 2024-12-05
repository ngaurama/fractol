/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:39:26 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/05 18:26:51 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 60

typedef struct s_julia
{
	double			cr;
	double			ci;
}					t_julia;

typedef struct s_atof
{
	int				sign;
	double			result;
	double			fraction_part;
	double			fraction_divisor;
	int				is_fraction;
	int				has_dot;
}					t_atof;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*win;
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	int				color_scheme;
	int				colors[9];
	double			julia_cr;
	double			julia_ci;
	double			julia_zr;
	double			julia_zi;
	double			ship_c_re;
	double			ship_c_im;
	double			ship_z_re;
	double			ship_z_im;
	int				red;
	int				green;
	int				blue;
	double			red_coeff1;
	double			red_coeff2;
	double			green_coeff1;
	double			green_coeff2;
	double			blue_coeff1;
	double			blue_coeff2;
	unsigned long	seed;
	int				value;
	double			zoom_factor;
	double			curs_real;
	double			curs_imag;
	int				julia_argv;
	int				fractol_type;
}					t_data;

/* ************************************************************************** */
/*                 FRACTAL FUNCTIONS (Julia, Mandelbrot, Ship)                */
/* ************************************************************************** */

// Julia
void				check_julia(t_data *data);
int					julia(double zr, double zi, double cr, double ci);
void				draw_julia(t_data *data);

// Mandelbrot
int					mandelbrot(double real, double imag);
void				draw_mandelbrot(t_data *data, int iter, int color);

// Burning Ship
void				ship_helper(t_data *data, int x, int y);
void				ship_helper_second(t_data *data, double *temp_re);
void				draw_burning_ship(t_data *data, int iter, int color);

/* ************************************************************************** */
/*                     HELPER FUNCTIONS (Color, Events)                       */
/* ************************************************************************** */

// Color
void				rand_col_1(t_data *data);
void				rand_col_2(t_data *data);
void				rand_col_3(t_data *data);
int					get_color(double iter, t_data *data, int color_scheme);

// Event controls
int					close_x(t_data *data);
void				assign_first_color(t_data *data);
int					color_switch(int key, t_data *data);
int					arrow_move(int key, t_data *data);

// Atof
double				ft_atof(char *str);
double				ft_atof_helper(char *str, t_atof *atof);
int					ft_strcasecmp(const char *s1, const char *s2);

// Helpers
int					full_control(int key, t_data *data);
double				map(double value, double max, double new_min,
						double new_max);
void				live_redraw(t_data *data, int key);
void				redraw(t_data *data);
void				call_draw(t_data *data);

// Randomizer
unsigned long		rand_num(t_data *data);
int					rand_range(int min, int max, t_data *data);

// Zoom
void				zoom_assign(t_data *data, int x, int y, double zoom);
int					zoom(int button, int x, int y, t_data *data);

/* ************************************************************************** */
/*                    MAIN FUNCTIONS (Initialization, Call)                   */
/* ************************************************************************** */

// Fractol (main)
void				data_init(t_data *data);
void				call_func(t_data *data);
int					check_args(int argc, char **argv, t_data *data);
int					print_format(int try);

#endif