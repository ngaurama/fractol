/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:49:56 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/05 17:36:56 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_atof_helper(char *str, t_atof *atof)
{
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (atof->is_fraction)
			{
				atof->fraction_part = atof->fraction_part * 10 + (*str - '0');
				atof->fraction_divisor *= 10;
			}
			else
				atof->result = atof->result * 10 + (*str - '0');
		}
		else if (*str == '.')
		{
			if (atof->has_dot)
				return (2147483648);
			atof->has_dot = 1;
			atof->is_fraction = 1;
		}
		else
			return (2147483648);
		str++;
	}
	atof->result += atof->fraction_part / atof->fraction_divisor;
	return (atof->result);
}

double	ft_atof(char *str)
{
	t_atof	atof;

	atof.sign = 1;
	if (*str == '-')
	{
		atof.sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	atof.result = 0.0;
	atof.fraction_part = 0.0;
	atof.fraction_divisor = 1.0;
	atof.is_fraction = 0;
	atof.has_dot = 0;
	atof.result = ft_atof_helper(str, &atof);
	if (atof.result == 2147483648)
		return (2147483648);
	return (atof.sign * atof.result);
}

int	ft_strcasecmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (ft_tolower((unsigned char)*s1) != ft_tolower((unsigned char)*s2))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
