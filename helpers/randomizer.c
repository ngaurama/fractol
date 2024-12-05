/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:27:04 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/04 16:27:31 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

unsigned long	rand_num(t_data *data)
{
	const unsigned long	a = 1664525;
	const unsigned long	c = 1013904223;
	const unsigned long	m = 4294967296;

	data->seed = (a * (data->seed) + c) % m;
	return (data->seed);
}

int	rand_range(int min, int max, t_data *data)
{
	unsigned long	range;

	range = (unsigned long)(max - min + 1);
	return ((rand_num(data) % range) + min);
}
