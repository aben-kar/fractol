#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	size_t	i;

    if (s1 == NULL  || s2 == NULL || n <= 0)
        return (0);
	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int  main(int ac, char **av)
{
    if ((ac == 2 && ft_strncmp(av[1], "Mandelbrot", 10)) || (ac == 4 && ft_strmcmp(av[1], "Julia", 5)))
        write (1, "1\n", 2);
    else
        write (2, "Error\n", 6);

}