#include "fractol.h"

void error_message(void) {
    printf("Please check your input again, make sure it matches one of these options:\n");
    printf("  - \"Mandelbrot\"\n");
    printf("  - \"Julia <number> <number>\"\n");
    printf("For better experience, we recommend you to enter a number between -2 and 2.\n");
    exit(1); // Exit after displaying the error
}

void data_init(t_fractol *fractol)
{
    fractol->escape_value = 4; // 2 ^ 2
    fractol->iteration = 42;
}