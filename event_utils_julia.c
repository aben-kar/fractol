#include "fractol.h"

int close_handel_julia(t_fractol *fractol)
{
    mlx_destroy_image(fractol->cnx_wind, fractol->cree_img);
    mlx_destroy_window(fractol->cnx_wind, fractol->cree_wind);
    mlx_destroy_display(fractol->cnx_wind);
    free(fractol->cnx_wind);
    exit(EXIT_SUCCESS);
}

int key_handel_julia(int keysym, t_fractol *fractol)
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
    else if (keysym == 97)
        fractol->iteration += 10;
    else if (keysym == 98)
        fractol->iteration -= 10;
    fractol_rend_julia(fractol);
    return 0;
}

int mouse_handel_julia(int button, int x, int y, t_fractol *fractol)
{
    (void) x;
    (void) y;
    if (button == Button5)
        fractol->zoom *= 0.95;
    else if (button == Button4)
        fractol->zoom *= 1.05;
    fractol_rend_julia(fractol);
    return 0;
}