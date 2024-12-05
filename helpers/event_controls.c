/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:03:40 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/04 17:42:41 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_x(t_data *data)
{
	if (!data)
		exit(0);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_loop_end(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

void	assign_first_color(t_data *data)
{
	if (data->color_scheme == 0)
	{
		data->color_scheme = 1;
		data->color_scheme = 1;
		data->red_coeff1 = 9;
		data->red_coeff2 = 3;
		data->green_coeff1 = 15;
		data->green_coeff2 = 2;
		data->blue_coeff1 = 8.5;
		data->blue_coeff2 = 3;
	}
	else
	{
		data->color_scheme = 1;
		rand_col_1(data);
	}
}

int	color_switch(int key, t_data *data)
{
	if (key == '1')
	{
		assign_first_color(data);
		call_draw(data);
	}
	else if (key == '2')
	{
		data->color_scheme = 2;
		rand_col_2(data);
		call_draw(data);
	}
	else if (key == '3')
	{
		data->color_scheme = 1;
		rand_col_3(data);
		call_draw(data);
	}
	else if (key == 'd')
	{
		data->color_scheme = 0;
		call_draw(data);
	}
	return (0);
}

int	arrow_move(int key, t_data *data)
{
	if (key == XK_Up)
	{
		data->y_min -= ((data->y_max - data->y_min) * 0.1);
		data->y_max -= ((data->y_max - data->y_min) * 0.1);
		call_draw(data);
	}
	else if (key == XK_Down)
	{
		data->y_min += ((data->y_max - data->y_min) * 0.1);
		data->y_max += ((data->y_max - data->y_min) * 0.1);
		call_draw(data);
	}
	else if (key == XK_Left)
	{
		data->x_min -= ((data->x_max - data->x_min) * 0.1);
		data->x_max -= ((data->x_max - data->x_min) * 0.1);
		call_draw(data);
	}
	else if (key == XK_Right)
	{
		data->x_min += ((data->x_max - data->x_min) * 0.1);
		data->x_max += ((data->x_max - data->x_min) * 0.1);
		call_draw(data);
	}
	return (0);
}
