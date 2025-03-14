#include "fractol.h"

double map(double num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}


void my_pixel_put(int x, int y, t_fractol *fractol, int color)
{
    int pos;

    pos = (y * fractol->line_pixel) + (x * (fractol->bpp / 8));
    *(unsigned int *)(fractol->addr + pos) = color;
}