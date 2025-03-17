/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:17:12 by acben-ka          #+#    #+#             */
/*   Updated: 2025/03/17 09:53:45 by acben-ka         ###   ########.fr       */
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
# define BLUE		0x0000FF
# define CYAN		0x00FFFF
# define PURPLE		0x800080
# define VIOLET		0x8A2BE2

# define WIDTH		1000
# define HEIGHT		1000
# define HYPOTENUSE	4.0

typedef struct complex
{
	float	x;
	float	y;
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
	float		julia_x;
	float		julia_y;
	float		shift_x;
	float		shift_y;
	float		zoom;
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
	float	tmp_real;
}		t_function;

char	*ft_strchr(const char *str, int c);
char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *s);
int		close_handel(t_fractol *fractol);
int		key_handel(int keysym, t_fractol *fractol);
int		mouse_handel(int button, int x, int y, t_fractol *fractol);
int		close_handel_julia(t_fractol *fractol);
int		key_handel_julia(int keysym, t_fractol *fractol);
int		mouse_handel_julia(int button, int x, int y, t_fractol *fractol);
void	print_error(void);
void	check_for_alphabetic(char *s);
void	data_init(t_fractol *fractol);
void	*ft_calloc(size_t count, size_t size);
void	error_and_exit(void);
void	fractol_mandelbrot(t_fractol *fractol);
void	img_pix_put(t_fractol *fractol, int x, int y, int color);
void	fractol_rend_mandelbrot(t_fractol *fractol);
void	event_mandelbrot(t_fractol *fractol);
void	free_and_exit(t_fractol *fractol, int number);
void	fractol_init_julia(t_fractol *fractol);
void	fractol_rend_julia(t_fractol *fractol);
void	initialization_imaginaire(t_fractol *fractol);
void	event_julia(t_fractol *fractol);
float	map(float num, float new_min, float new_max, float old_max);
float	ft_atof(char *s);

#endif
