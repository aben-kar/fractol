#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
    if (s1 == NULL  || s2 == NULL || n <= 0)
        	return (0);
	int	i;

	i = 0;
	while (s1[i] == s2[i] && n > 0 && s1[i] && s2[i])
	{
		i++;
		--n;
	}
	if (n == 0)
    	return (0);
	return (s1[i] - s2[i]);
}

int  main(int ac, char **av)
{
	t_fractol fractol;
    if ((ac == 2 && ft_strncmp(av[1], "Mandelbrot", 11) == 0))
	{
		fractol.name = av[1];
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.cnx_wind);
	}

	else if ((ac == 4 && ft_strncmp(av[1], "Julia", 6) == 0))
	{
		fractol.julia_x = ft_atof(av[2]);
		fractol.julia_y = ft_atof(av[3]);
		fractol.name = av[1];
		fractol_init_julia(&fractol);
		fractol_render_julia(&fractol);
		mlx_loop(fractol.cnx_wind);
	}
    else
        error_message();

}