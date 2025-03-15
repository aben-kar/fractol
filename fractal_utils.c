#include "fractol.h"

void error_message(void) {
    printf("Please check your input again, make sure it matches one of these options:\n");
    printf("  - \"Mandelbrot\"\n");
    printf("  - \"Julia <number> <number>\"\n");
    printf("For better experience, we recommend you to enter a number between -2 and 2.\n");
    exit(1);
}

void data_init(t_fractol *fractol)
{
    fractol->escape_value = 4; // 2 ^ 2
    fractol->iteration = 42;
    fractol->shift_x = 0.0;
    fractol->shift_y = 0.0;
}

void event_init(t_fractol *fractol)
{
    mlx_hook(fractol->new_window, 02, 1L<<0, key_handel, fractol);
    // mlx_hook(fractol->new_window, 04, 1L<<2, mouse_handel, fractol);
    mlx_hook(fractol->new_window, 17, 1L<<17, close_handel, fractol);
}