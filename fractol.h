/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:17:12 by acben-ka          #+#    #+#             */
/*   Updated: 2025/03/17 04:22:33 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define ORANGE		0xFFA500
# define PINK		0xFF69B4
# define PURPLE		0x800080
# define NEON_GREEN	0x39FF14
# define TURQUOISE	0x40E0D0
# define VIOLET		0x8A2BE2
# define PSYCHEDELIC	0x7F00FF
# define RAINBOW	0xFF1493

# define WIDTH		800
# define HEIGHT		800
# define HYPOTENUSE	4.0

typedef struct complex
{
	double	x;
	double	y;
}		t_complex;

typedef struct fractol
{
	void		*cnx_wind;
	void		*cree_wind;
	void		*cree_img;
	char		*addr;
	char		*name;
	int			bpp;
	int			len_line;
	int			endian;
	int			iteration;
	double		julia_x;
	double		julia_y;
	double		shift_x;
	double		shift_y;
	double		zoom;
}		t_fractol;

typedef struct function
{
	int		j;
	int		i;
	char	**prr;
	int		len_word;
	char	**split_args;
	int		k;
	char	*result;
	int		color;
	double	tmp_real;
}		t_function;

int		ft_strncmp(char *s1, char *s2, int n);
void	print_error(void);
void	data_init(t_fractol *fractol);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *s);
int		ft_strlen(const char *s);
void	error_and_exit(void);
void	fractol_mandelbrot(t_fractol *fractol);
double	map(double num, double new_min, double new_max, double old_max);
void	img_pix_put(t_fractol *fractol, int x, int y, int color);
void	fractol_rend_mandelbrot(t_fractol *fractol);
void	event_mandelbrot(t_fractol *fractol);
void	free_and_exit(t_fractol *fractol, int number);
void	fractol_init_julia(t_fractol *fractol);
void	fractol_rend_julia(t_fractol *fractol);
double	ft_atof(char *s);
void	event_julia(t_fractol *fractol);
void	intializtion_imaginaire(t_fractol *fractol);
int		close_handel(t_fractol *fractol);
int		key_handel(int keysym, t_fractol *fractol);
int		mouse_handel(int button, int x, int y, t_fractol *fractol);
int		close_handel_julia(t_fractol *fractol);
int		key_handel_julia(int keysym, t_fractol *fractol);
int		mouse_handel_julia(int button, int x, int y, t_fractol *fractol);

#endif
