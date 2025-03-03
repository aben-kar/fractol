#include "fractol.h"

// int	ft_strncmp(char *s1, char *s2, int n)
// {
// 	int	i;

// 	i = 0;
//     // if (s1 == NULL  || s2 == NULL || n <= 0)
//     //     return (0);
// 	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
// 		i++;
// 	if (i == n)
// 		return (0);
// 	return (s1[i] - s2[i]);
// }

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

int  main(int ac, char **av)
{
    if ((ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10)) || (ac == 2 && !ft_strncmp(av[1], "Julia", 5)))
	{
		// write (1, "ana\n", 4);
        write (1, "1\n", 2);
	}
    else
        write (2, "Error\n", 6);

}