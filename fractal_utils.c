#include "fractol.h"

void    error_message(void)
{
    printf("Please check your input again, make sure it matches one of these options:\n");
    printf("  - \"Mandelbrot\"\n");
    printf("  - \"Julia <number> <number>\"\n");
    printf("For better experience, we recommend you to enter a number between -2 and 2.\n");
}
