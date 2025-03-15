#include "fractol.h"

#include <stdio.h>

double	ft_atof(const char *s)
{
	int		i;
	double	rs;
	double	sign;
	double	factor;

	i = 0;
	rs = 0.0;
	sign = 1.0;
	factor = 1.0;

	// Skip white spaces
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;

	// Handle sign correctly
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1.0;
		i++;
	}
	else if ((unsigned char)s[i] == 0xE2) // Unicode en dash (–)
	{
		i += 3; // Skip the 3-byte sequence (UTF-8 encoding)
		sign = -1.0;
	}

	// Convert integer part
	while (s[i] >= '0' && s[i] <= '9')
	{
		rs = rs * 10.0 + (s[i] - '0');
		i++;
	}

	// Handle decimal part
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			factor *= 0.1;
			rs += (s[i] - '0') * factor;
			i++;
		}
	}

	return (rs * sign);
}


void fractol_init_julia(t_fractol *fractol)
{
    fractol->cnx_wind = mlx_init();
    if (fractol->cnx_wind == NULL) {
        malloc_error();
    }
    fractol->new_window = mlx_new_window(fractol->cnx_wind, WIDTH, HEIGHT, fractol->name);
    if (fractol->new_window == NULL) {
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
        malloc_error();
    }
    fractol->imag = mlx_new_image(fractol->cnx_wind, WIDTH, HEIGHT);
    if (fractol->imag == NULL) {
        mlx_destroy_window(fractol->cnx_wind, fractol->new_window);
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
        malloc_error();
    }
    fractol->addr = mlx_get_data_addr(fractol->imag, &fractol->bpp, &fractol->line_pixel, &fractol->endian);
    if (fractol->addr == NULL)
    {
        mlx_destroy_image(fractol->cnx_wind, fractol->imag);
        mlx_destroy_window(fractol->cnx_wind, fractol->new_window);
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
        malloc_error();
    }
    // gestion deyal events
    event_init_julia(fractol);
    data_init(fractol);
}