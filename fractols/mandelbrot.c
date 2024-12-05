/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:38:59 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/04 14:03:48 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(double real, double imag)
{
	double	zr;
	double	zi;
	int		iter;
	double	temp;
	double	nu;

	zr = 0;
	zi = 0;
	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < MAX_ITER)
	{
		temp = zr * zr - zi * zi + real;
		zi = 2 * zr * zi + imag;
		zr = temp;
		iter++;
	}
	if (iter < MAX_ITER)
	{
		nu = log((log(zr * zr + zi * zi) / 2.0) / log(2.0)) / log(2.0);
		return (iter + 1 - nu);
	}
	return (iter);
}

void	draw_mandelbrot(t_data *data, int iter, int color)
{
	double			real;
	double			imag;
	char			*dst;
	int				y;
	int				x;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			real = map(x, WIDTH, data->x_min, data->x_max);
			imag = map(y, HEIGHT, data->y_min, data->y_max);
			iter = mandelbrot(real, imag);
			color = get_color(iter, data, data->color_scheme);
			if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			{
				dst = data->addr + (y * data->line_length + x * (data->bpp
							/ 8));
				*(unsigned int *)dst = color;
			}
		}
	}
}
