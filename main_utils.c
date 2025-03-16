#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
    if (!s1 || !s2)
        return (0);
    
    int i;

    i = 0;
    while (n > 0 && s1[i] == s2[i] && s1[i] && s2[i])
    {
        i++;
        n--;
    }
    if (n == 0)
        return (0);
    return (s1[i] - s2[i]);
}

void print_error(void)
{
    printf("Please check your input again, make sure it matches one of these options:\n");
    printf("  - \"Mandelbrot\"\n");
    printf("  - \"Julia or Julia <number> <number>\"\n");
    printf("For better experience, we recommend you to enter a number between -2 and 2.\n");
    exit(1);
}

void data_init(t_fractol *fractol)
{
    fractol->iteration = 42;
    fractol->shift_x = 0.0;
    fractol->shift_y = 0.0;
    fractol->zoom = 1.0;
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if ((char)c == *str)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			i;

	if (size != 0 && (count > SIZE_MAX / size))
		return (NULL);
	s = (unsigned char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
