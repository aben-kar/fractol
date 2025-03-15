#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define WIDTH 800
#define HEIGHT 800

#define BLACK       0x000000  // Black
#define WHITE       0xFFFFFF  // White
#define RED         0xFF0000  // Red
#define GREEN       0x00FF00  // Green
#define BLUE        0x0000FF  // Blue
#define YELLOW      0xFFFF00  // Yellow
#define CYAN        0x00FFFF  // Cyan
#define MAGENTA     0xFF00FF  // Magenta
#define ORANGE      0xFFA500  // Orange
#define PINK        0xFF69B4  // Pink
#define PURPLE      0x800080  // Purple
#define NEON_GREEN  0x39FF14  // Neon Green
#define TURQUOISE   0x40E0D0  // Turquoise
#define VIOLET      0x8A2BE2  // Violet
#define PSYCHEDELIC 0x7F00FF  // Psychedelic Purple
#define RAINBOW     0xFF1493  // Deep Pink, can be used for rainbow effects

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
    double escape_value;
    int iteration;
    double shift_x;
    double shift_y;
    double zoom;
} t_fractol;

void fractol_init(t_fractol *fractol);
void    error_message(void);
double map(double num, double new_min, double new_max, double old_min, double old_max);
void data_init(t_fractol *fractol);
void my_pixel_put(int x, int y, t_fractol *fractol, int color);
void fractol_render(t_fractol *fractol);
void event_init(t_fractol *fractol);
int key_handel(int keysym, t_fractol * fractol);
int close_handel(t_fractol *fractol);
int mouse_handel(int button, int x, int y, t_fractol *fractol);


#endif

