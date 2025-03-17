/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 03:59:17 by acben-ka          #+#    #+#             */
/*   Updated: 2025/03/17 06:04:33 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2 || ac == 4)
	{
		if (ac == 2 && (ft_strncmp(av[1], "Mandelbrot", 11)) == 0)
		{
			fractol.name = av[1];
			(fractol_mandelbrot(&fractol), fractol_rend_mandelbrot(&fractol));
			mlx_loop(fractol.cnx_wind);
		}
		else if ((ft_strncmp(av[1], "Julia", 6)) == 0)
		{
			if (ac == 2)
				initialization_imaginaire(&fractol);
			else if (ac == 4)
			{
				fractol.julia_x = ft_atof(av[2]);
				fractol.julia_y = ft_atof(av[3]);
			}
			fractol.name = av[1];
			(fractol_init_julia(&fractol), fractol_rend_julia(&fractol));
			mlx_loop(fractol.cnx_wind);
		}
	}
	print_error();
}
