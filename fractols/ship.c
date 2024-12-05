/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:05:20 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/04 14:03:50 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ship_helper(t_data *data, int x, int y)
{
	data->ship_c_re = map(x, WIDTH, data->x_min, data->x_max);
	data->ship_c_im = map(y, HEIGHT, data->y_min, data->y_max);
	data->ship_z_re = 0;
	data->ship_z_im = 0;
}

void	ship_helper_second(t_data *data, double *temp_re)
{
	*temp_re = data->ship_z_re * data->ship_z_re - data->ship_z_im
		* data->ship_z_im + data->ship_c_re;
	data->ship_z_im = fabs(2 * data->ship_z_re * data->ship_z_im)
		+ data->ship_c_im;
	data->ship_z_re = fabs(*temp_re);
}

void	draw_burning_ship(t_data *data, int iter, int color)
{
	double	temp_re;
	char	*dst;
	int		y;
	int		x;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			ship_helper(data, x, y);
			iter = 0;
			while (data->ship_z_re * data->ship_z_re + data->ship_z_im
				* data->ship_z_im <= 4 && iter < MAX_ITER)
			{
				ship_helper_second(data, &temp_re);
				iter++;
			}
			color = get_color(iter, data, data->color_scheme);
			dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
			*(unsigned int *)dst = color;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
