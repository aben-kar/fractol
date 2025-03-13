#include "fractol.h"

double map(double num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

// t_complex sum_complex(t_complex z1, t_complex z2)
// {
//     t_complex result;

//     result.x = z1.x + z2.x;
//     result.y = z1.y + z2.y;
//     return (result);
// }

// t_complex square_complex(t_complex z)
// {
//     t_complex result;
//     result.x = (z.x * z.x) - (z.y * z.y);
//     result.y = 2 * z.x * z.y;
//     return(result);
// }

// void my_pixel_put(int x, int y, void *img, int color)
// {
//     int ofsset;

//     t_fractol *fractol = (t_fractol *)img; 
//     ofsset = (y * fractol->line_pixel) + (x * (fractol->bpp / 8));
//     *(unsigned int *)(fractol->addr + ofsset) = color;
// }

void my_pixel_put(int x, int y, t_fractol *fractol, int color)
{
    int offset;

    offset = (y * fractol->line_pixel) + (x * (fractol->bpp / 8));
    *(unsigned int *)(fractol->addr + offset) = color;
}