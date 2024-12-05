/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:41:35 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/05 18:15:11 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->mlx);
		return ;
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!data->win)
	{
		free(data->win);
		return ;
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	data->x_min = -2.0;
	data->x_max = 2.0;
	data->y_min = -2.0;
	data->y_max = 2.0;
	data->color_scheme = 0;
	data->seed = 1376517;
	data->julia_ci = 0.0;
	data->julia_cr = 0.0;
	data->value = 0;
	data->julia_argv = 0;
}

void	call_func(t_data *data)
{
	call_draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_mouse_hook(data->win, zoom, data);
	mlx_key_hook(data->win, full_control, data);
	mlx_hook(data->win, 17, 0, close_x, data);
	mlx_loop(data->mlx);
}

int	print_format(int try)
{
	if (try)
		ft_printf("\n\033[1;31mERROR:\033[0m Please provide correct parameters.\n");
	ft_printf("\n\033[1;36m********************************************\n*\033[0m");
	ft_printf("\033[1;95m           Welcome to Fract'ol!           \033[0m");
	ft_printf("\033[1;36m*\n********************************************\033[0m\n");
	ft_printf("\n\033[1;33mUsage:\033[0m\n");
	ft_printf("  \033[1;32m./fractol mandelbrot\033[0m\n");
	ft_printf("  \033[1;32m./fractol julia real_value imag_value\033[0m\n");
	ft_printf("  \033[1;32m./fractol ship\033[0m\n\n");
	ft_printf("\033[1;36m---------------------------------------------\033[0m\n");
	ft_printf("\033[1;33mControls:\033[0m\n");
	ft_printf("  \033[1;32mArrow Keys:\033[0m Move around the fractal window.\n");
	ft_printf("  \033[1;32m1, 2, 3, d:\033[0m Change color themes.\n");
	ft_printf("  \033[1;32mm:\033[0m Switch to Mandelbrot set.\n");
	ft_printf("  \033[1;32mj:\033[0m Switch to Julia set.\n");
	ft_printf("  \033[1;32ms:\033[0m Switch to Burning Ship fractal.\n");
	ft_printf("\n\033[1;36m---------------------------------------------\033[0m\n");
	ft_printf("\033[1;34m  Tip:\033[0m Zoom in and out to explore further!\n");
	ft_printf("\033[1;36m*********************************************\033[0m\n");
	return (0);
}

int	check_args(int argc, char **argv, t_data *data)
{
	if ((ft_strcasecmp(argv[1], "mandelbrot") == 0 || ft_strcasecmp(argv[1],
				"m") == 0) && argc == 2)
		data->fractol_type = 0;
	else if ((ft_strcasecmp(argv[1], "julia") == 0 || ft_strcasecmp(argv[1],
				"j") == 0) && argc <= 4)
	{
		if (argc == 4)
		{
			data->fractol_type = 1;
			if (ft_atof(argv[2]) == 2147483648
				|| ft_atof(argv[3]) == 2147483648)
				return (print_format(1));
			data->julia_cr = ft_atof(argv[2]);
			data->julia_ci = ft_atof(argv[3]);
			data->julia_argv = 1;
		}
		else
			data->fractol_type = 1;
	}
	else if ((ft_strcasecmp(argv[1], "ship") == 0 || ft_strcasecmp(argv[1],
				"s") == 0) && argc == 2)
		data->fractol_type = 2;
	else
		return (print_format(1));
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		result;

	if (argc < 2)
		return (print_format(0));
	data_init(&data);
	result = check_args(argc, argv, &data);
	if (!result)
		return (0);
	call_func(&data);
	return (0);
}
