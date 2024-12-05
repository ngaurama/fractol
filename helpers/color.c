/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:42:30 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/04 17:48:27 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	rand_col_1(t_data *data)
{
	int	div;

	if (data->fractol_type == 1)
		div = 10;
	else
		div = 15;
	data->red_coeff1 = (rand_range(-2147483647, 2147483646, data) % div) + 1;
	data->red_coeff2 = (rand_range(-2147483647, 2147483646, data) % div) + 1;
	data->green_coeff1 = (rand_range(-2147483647, 2147483646, data) % div) + 1;
	data->green_coeff2 = (rand_range(-2147483647, 2147483646, data) % div) + 1;
	data->blue_coeff1 = (rand_range(-2147483647, 2147483646, data) % div) + 1;
	data->blue_coeff2 = (rand_range(-2147483647, 2147483646, data) % div) + 1;
}

void	rand_col_2(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < 9)
		data->colors[i] = rand_range(-2147483647, 2147483646, data) % 0xFFFFFF;
}

void	rand_col_3(t_data *data)
{
	int	div;

	if (data->fractol_type == 1)
		div = 10;
	else
		div = 15;
	data->red_coeff1 = (rand_range(0, 2147483646, data) % div) + 1;
	data->red_coeff2 = (rand_range(0, 2147483646, data) % div) + 1;
	data->green_coeff1 = (rand_range(0, 2147483646, data) % div) + 1;
	data->green_coeff2 = (rand_range(0, 2147483646, data) % div) + 1;
	data->blue_coeff1 = (rand_range(0, 2147483646, data) % div) + 1;
	data->blue_coeff2 = (rand_range(0, 2147483646, data) % div) + 1;
}

// void	rand_col_3(t_data *data)
// {
// 	int				div;

// 	if (data->fractol_type == 1)
// 		div = 10;
// 	else
// 		div = 15;
// 	data->red_coeff1 = (rand() % div) + 1;
// 	data->red_coeff2 = (rand() % div) + 1;
// 	data->green_coeff1 = (rand() % div) + 1;
// 	data->green_coeff2 = (rand() % div) + 1;
// 	data->blue_coeff1 = (rand() % div) + 1;
// 	data->blue_coeff2 = (rand() % div) + 1;
// }

int	get_color(double iter, t_data *data, int color_scheme)
{
	double	t;
	int		color_index;

	t = iter / MAX_ITER;
	if ((int)iter == MAX_ITER)
		return (0x000000);
	else if (!color_scheme)
	{
		return (iter * 0x050000 + iter * 0x000500 + iter * 0x000005);
	}
	else if (color_scheme == 1)
	{
		data->red = (int)(data->red_coeff1 * (1 - t) * pow(t, data->red_coeff2)
				* 255);
		data->green = (int)(data->green_coeff1 * pow((1 - t),
					data->green_coeff2) * t * t * 255);
		data->blue = (int)(data->blue_coeff1 * pow((1 - t), data->blue_coeff2)
				* t * 255);
	}
	else if (color_scheme == 2)
	{
		color_index = (int)iter % 9;
		return (data->colors[color_index]);
	}
	return ((data->red << 16) | (data->green << 8) | data->blue);
}
