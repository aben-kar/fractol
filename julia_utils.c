/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:13:05 by acben-ka          #+#    #+#             */
/*   Updated: 2025/03/17 09:51:55 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	parse_integer_part(char *s, int *i)
{
	float	ret;

	ret = 0.0;
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	return (ret);
}

float	parse_decimal_part(char *s, int *i)
{
	float	decimal_part;
	int		decimal_place;

	decimal_part = 0.0;
	decimal_place = 1;
	if (s[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(s[*i]))
		{
			decimal_part = decimal_part * 10 + (s[*i] - '0');
			decimal_place *= 10;
			(*i)++;
		}
	}
	return (decimal_part / decimal_place);
}

float	ft_atof(char *s)
{
	float	ret;
	int		sign;
	int		i;

	ret = 0.0;
	sign = 1;
	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(s[i]))
		print_error();
	check_for_alphabetic(s);
	ret = parse_integer_part(s, &i);
	ret += parse_decimal_part(s, &i);
	if (s[i] != '\0')
		print_error();
	return (ret * sign);
}

void	event_julia(t_fractol *fractol)
{
	mlx_hook(fractol->cree_wind, 02, 1L << 0, key_handel_julia, fractol);
	mlx_hook(fractol->cree_wind, 04, 1L << 2, mouse_handel_julia, fractol);
	mlx_hook(fractol->cree_wind, 17, 1L << 17, close_handel_julia, fractol);
}

void	initialization_imaginaire(t_fractol *fractol)
{
	fractol->julia_x = -0.8;
	fractol->julia_y = 0.156;
}
