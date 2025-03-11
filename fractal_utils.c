#include "fractol.h"

void    error_message(void)
{
    printf("Please check your input again, make sure it matches one of these options:\n");
    printf("  - \"Mandelbrot\"\n");
    printf("  - \"Julia <number> <number>\"\n");
    printf("For better experience, we recommend you to enter a number between -2 and 2.\n");
}

double map(double num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

void handel_pixel(int x, int y, t_fractol *fractol)
{
    t_complex z;
    t_complex c;

    z.x = 0.0;
    z.y = 0.0;

    c.x = map (x, -2, +2, 0, WIDTH);
    c.y = map (y, +2, -2, 0, HEIGHT);

    while ()
    {
        z = sum_complex(square_complex(z), c); 
    }

}