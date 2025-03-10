#include "fractol.h"


void fractol_init(t_fractol *fractol)
{
    fractol->cnx_wind = mlx_init();
    fractol->new_window = mlx_new_window(fractol->cnx_wind, WIDTH, HEIGHT, fractol->name);
    fractol->imag = mlx_new_image(fractol->cnx_wind, WIDTH, HEIGHT);
    // fractol->addr = mlx_get_data_addr(fractol->cnx_wind, &)
    // mlx_loop(fractol->cnx_wind);
}