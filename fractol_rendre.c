#include "fractol.h"

void handele_pixel(int x, int y, t_fractol *fractol)
{
    t_complex z;
    t_complex c;
    int i = 0;
    int color;

    z.x = 0.0;
    z.y = 0.0;

    c.x = (map(x, -2, +2, 0, WIDTH) * fractol->zoom) + fractol->shift_x;
    c.y = (map(y, +2, -2, 0, HEIGHT) * fractol->zoom) + fractol->shift_y;

    while (i < fractol->iteration) //42
    {

        // Genaral formule
        // Z = Z^2 + C
        double tmp_real;
        tmp_real = (z.x * z.x) - (z.y * z.y);
        z.y = 2 * z.x * z.y;
        z.x = tmp_real;

        //Addinng the c value
        z.x += c.x;
        z.y += c.y;

        if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
        {
            color = map(i, BLACK, WHITE, 0, fractol->iteration);
            // color = (i * 15) << 16 | (i * 15) << 8 | (i * 8);
            my_pixel_put(x, y, fractol, color);
            return;
        }
        i++;
    }
    my_pixel_put(x, y, fractol, WHITE);
}

void fractol_render(t_fractol *fractol)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handele_pixel(x, y, fractol);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->cnx_wind, fractol->new_window, fractol->imag, 0, 0);
}