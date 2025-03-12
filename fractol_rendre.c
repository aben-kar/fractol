#include "fractol.h"

void handele_pixel(int x, int y, t_fractol *fractol)
{
    t_complex z;
    t_complex c;
    int i = 0;
    int color;

    z.x = 0.0;
    z.y = 0.0;

    c.x = map(x, -2, +2, 0, WIDTH);
    c.y = map(y, +2, -2, 0, HEIGHT);

    while (i < fractol->iteration)
    {
        z = sum_complex(square_complex(z), c);

        if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
        {
            color = map(i, BLACK, WHITE, 0, fractol->iteration);
            my_pixel_put(x, y, fractol, color);
            return;
        }
        ++i;
    }
    my_pixel_put(x, y, fractol, PINK);
}

void fractol_render(t_fractol *fractol)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handele_pixel(x, y, fractol);
        }
    }
    mlx_put_image_to_window(fractol->cnx_wind, fractol->new_window, fractol->imag, 0, 0);
}