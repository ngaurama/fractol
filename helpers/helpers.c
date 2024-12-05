/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:42:00 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/04 17:31:30 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	full_control(int key, t_data *data)
{
	if (key == XK_Escape)
		close_x(data);
	else if (key == '1' || key == '2' || key == '3' || key == 'd')
		color_switch(key, data);
	else if (key == XK_Up || key == XK_Down || key == XK_Left
		|| key == XK_Right)
		arrow_move(key, data);
	else if (key == 'j' || key == 'm' || key == 's')
		live_redraw(data, key);
	return (0);
}

double	map(double value, double max, double new_min, double new_max)
{
	return (new_min + value * (new_max - new_min) / max);
}

void	live_redraw(t_data *data, int key)
{
	if (key == 'm')
	{
		data->fractol_type = 0;
		call_draw(data);
	}
	else if (key == 'j')
	{
		data->fractol_type = 1;
		call_draw(data);
	}
	else if (key == 's')
	{
		data->fractol_type = 2;
		call_draw(data);
	}
}

void	redraw(t_data *data)
{
	int	iter;
	int	color;

	iter = 0;
	color = 0;
	if (data->fractol_type == 0)
		draw_mandelbrot(data, iter, color);
	else if (data->fractol_type == 1)
	{
		data->julia_zr = 0;
		data->julia_zi = 0;
		check_julia(data);
		draw_julia(data);
	}
	else if (data->fractol_type == 2)
		draw_burning_ship(data, iter, color);
}

void	call_draw(t_data *data)
{
	redraw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
