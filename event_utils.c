#include "fractol.h"

int close_handel(t_fractol *fractol)
{
    mlx_destroy_image(fractol->cnx_wind, fractol->imag);
    mlx_destroy_window(fractol->cnx_wind, fractol->new_window);
    mlx_destroy_display(fractol->cnx_wind);
    free(fractol->cnx_wind);
    exit(EXIT_SUCCESS);
}

int key_handel(int keysym, t_fractol * fractol)
{
    if (keysym == XK_Escape || keysym == 120)
        close_handel(fractol);
    else if (keysym == XK_Left)
        fractol->shift_x += 0.5;
    else if (keysym == XK_Right)
        fractol->shift_x -= 0.5;
    else if (keysym == XK_Up)
        fractol->shift_y -= 0.5;
    else if (keysym == XK_Down)
        fractol->shift_y += 0.5;
    else if (keysym == 97)
        fractol->iteration += 10;
    else if (keysym == 98)
        fractol->iteration -= 10;
    fractol_render(fractol);
    return 0;
}