#include "fractol.h"

void malloc_error()
{
    perror("Problems with malloc");
    exit (1);
}

void fractol_init(t_fractol *fractol)
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
    event_init(fractol);
    data_init(fractol);
}
