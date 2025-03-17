#include "fractol.h"


int	main(int ac, char **av)
{
    t_fractol fractol;
    if (ac == 2 || ac == 4)
    {
        if (ac == 2 && (ft_strncmp(av[1], "Mandelbrot", 11)) == 0)
        {
            fractol.name = av[1];
            (fractol_init_mandelbrot(&fractol), fractol_rend_mandelbrot(&fractol));
            mlx_loop(fractol.cnx_wind);
        }
        else if ((ft_strncmp(av[1], "Julia", 6)) == 0)
        {
            if (ac == 2)
                intializtion_imaginaire(&fractol);
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
