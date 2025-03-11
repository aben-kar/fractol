#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "minilibx-linux/mlx.h"

#define WIDTH 800
#define HEIGHT 800

typedef struct s_complex
{
    double x;
    double y;
} t_complex;


typedef struct s_fractol
{
    char *name;
    char *addr;
    void *cnx_wind;
    void *new_window;
    void *imag;
    int bpp;
    int line_pixel;
    int endian;
} t_fractol;

void fractol_init(t_fractol *fractol);
void    error_message(void);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

#endif

