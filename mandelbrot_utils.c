#include "fractol.h"

void error_and_exit(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

double map(double num, double new_min, double new_max, double old_max)
{
    int old_min = 0;
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

void	img_pix_put(t_fractol *fractol, int x, int y, int color)
{
    char    *pos;

    pos = fractol->addr + (y * fractol->len_line + x * (fractol->bpp / 8));
    *(unsigned int *)pos = color;
}

void event_mandelbrot(t_fractol *fractol)
{
    mlx_hook(fractol->cree_wind, 02, 1L<<0, key_handel, fractol);
    mlx_hook(fractol->cree_wind, 04, 1L<<2, mouse_handel, fractol);
    mlx_hook(fractol->cree_wind, 17, 1L<<17, close_handel, fractol);
}

void free_and_exit(t_fractol *fractol, int number)
{
    if (number == 1)
    {
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
    }
    else if (number == 2)
    {
        mlx_destroy_window(fractol->cnx_wind, fractol->cree_wind);
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
    }
    else if (number == 3)
    {
        mlx_destroy_image(fractol->cnx_wind, fractol->cree_img);
        mlx_destroy_window(fractol->cnx_wind, fractol->cree_wind);
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
    }
    error_and_exit();
}
