/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:40:53 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/04 17:15:20 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	check_julia(t_data *data)
{
	t_julia	values[7];

	values[0].cr = 0;
	values[0].ci = 0.8;
	values[1].cr = 0.37;
	values[1].ci = 0.1;
	values[2].cr = 0.355;
	values[2].ci = 0.355;
	values[3].cr = -0.54;
	values[3].ci = 0.54;
	values[4].cr = -0.4;
	values[4].ci = -0.59;
	values[5].cr = 0.34;
	values[5].ci = -0.05;
	values[6].cr = 0.355534;
	values[6].ci = -0.337292;
	if (!data->julia_argv)
	{
		data->julia_ci = values[data->value].ci;
		data->julia_cr = values[data->value].cr;
	}
}

int	julia(double zr, double zi, double cr, double ci)
{
	int		iter;
	double	temp;
	double	log_zn;
	double	nu;

	iter = 0;
	while (zr * zr + zi * zi <= 4 && iter < MAX_ITER)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	if (iter < MAX_ITER)
	{
		log_zn = log(zr * zr + zi * zi) / 2.0;
		nu = log(log_zn / log(2.0)) / log(2.0);
		return (iter + 1 - nu);
	}
	return (iter);
}

void	draw_julia(t_data *data)
{
	int		iter;
	int		color;
	char	*dst;
	int		y;
	int		x;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			data->julia_zr = map(x, WIDTH, data->x_min, data->x_max);
			data->julia_zi = map(y, HEIGHT, data->y_min, data->y_max);
			iter = julia(data->julia_zr, data->julia_zi, data->julia_cr,
					data->julia_ci);
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
