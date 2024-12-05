/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:28:14 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/04 16:51:07 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_assign(t_data *data, int x, int y, double zoom)
{
	data->curs_real = map(x, WIDTH, data->x_min, data->x_max);
	data->curs_imag = map(y, HEIGHT, data->y_min, data->y_max);
	data->x_min = data->curs_real - (data->curs_real - data->x_min) * zoom;
	data->x_max = data->curs_real + (data->x_max - data->curs_real) * zoom;
	data->y_min = data->curs_imag - (data->curs_imag - data->y_min) * zoom;
	data->y_max = data->curs_imag + (data->y_max - data->curs_imag) * zoom;
}

int	zoom(int button, int x, int y, t_data *data)
{
	double	zoom_factor;

	zoom_factor = 0.0;
	if (button == 1 && data->fractol_type == 1)
	{
		data->julia_argv = 0;
		if (data->value < 6)
			data->value++;
		else
			data->value = 0;
		call_draw(data);
	}
	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	zoom_assign(data, x, y, zoom_factor);
	call_draw(data);
	return (0);
}
