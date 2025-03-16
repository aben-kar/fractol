#include "fractol.h"

void fractol_init_julia(t_fractol *fractol)
{
    fractol->cnx_wind = mlx_init();
    if (!fractol->cnx_wind)
        error_and_exit();
    fractol->cree_wind = mlx_new_window(fractol->cnx_wind, WIDTH, HEIGHT, fractol->name);
    if (!fractol->cree_wind)
    {
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
        error_and_exit();
    }
    fractol->cree_img = mlx_new_image(fractol->cnx_wind, WIDTH, HEIGHT);
    if (!fractol->cree_img)
    {
        mlx_destroy_window(fractol->cnx_wind, fractol->cree_wind);
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
        error_and_exit();
    }
    fractol->addr = mlx_get_data_addr(fractol->cree_img, &fractol->bpp, &fractol->len_line, 
                                        &fractol->endian);
    if (!fractol->addr)
    {
        mlx_destroy_image(fractol->cnx_wind, fractol->cree_img);
        mlx_destroy_window(fractol->cnx_wind, fractol->cree_wind);
        mlx_destroy_display(fractol->cnx_wind);
        free(fractol->cnx_wind);
        error_and_exit();
    }
    event_julia(fractol);
    data_init(fractol);
}

void handel_pixel_julia(int x, int y, t_fractol *fractol)
{
    t_complex z;
    t_complex c;
    int i;
    int color;
    double tmp_real;

    z.x = (map(x, -2, 2, WIDTH) * fractol->zoom) + fractol->shift_x;
    z.y = (map(y, 2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
    c.x = fractol->julia_x;
    c.y = fractol->julia_y;
    i = 0;
    while (i < fractol->iteration)
    {
        tmp_real = (z.x * z.x) - (z.y * z.y);
        z.y = 2 * z.x * z.y;
        z.x = tmp_real;
        z.x += c.x;
        z.y += c.y;
        if (((z.x *z.x) + (z.y * z.y)) > HYPOTENUSE)
        {
            color = map(i, BLACK, WHITE, fractol->iteration);
            img_pix_put(fractol, x, y, color);
            return;
        }
        i++;
    }
    img_pix_put(fractol, x, y, BLACK);
}

void fractol_rend_julia(t_fractol *fractol)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handel_pixel_julia(x, y, fractol);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->cnx_wind, fractol->cree_wind, fractol->cree_img, 0, 0);
}
