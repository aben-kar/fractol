/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils_mandelbrot.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:13:50 by acben-ka          #+#    #+#             */
/*   Updated: 2025/03/17 08:36:05 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handel(t_fractol *fractol)
{
	mlx_destroy_image(fractol->cnx_wind, fractol->cree_img);
	mlx_destroy_window(fractol->cnx_wind, fractol->cree_wind);
	mlx_destroy_display(fractol->cnx_wind);
	free(fractol->cnx_wind);
	exit(EXIT_SUCCESS);
}

int	key_handel(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handel(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == XK_a)
		fractol->iteration += 10;
	else if (keysym == XK_b)
		fractol->iteration -= 10;
	fractol_rend_mandelbrot(fractol);
	return (0);
}

int	mouse_handel(int button, int x, int y, t_fractol *fractol)
{
	(void) x;
	(void) y;
	if (button == Button5)
		fractol->zoom *= 0.95;
	else if (button == Button4)
		fractol->zoom *= 1.05;
	fractol_rend_mandelbrot(fractol);
	return (0);
}
