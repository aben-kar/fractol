#include "fractol.h"

int	count_word(char const *s1, char sp)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	check = 1;
	while (s1[i])
	{
		if (s1[i] != sp && check == 1)
		{
			count += 1;
			check = 0;
		}
		else if (s1[i] == sp)
			check = 1;
		i++;
	}
	return (count);
}

char	*ft_strsdup(char const *s, int *j, char sp)
{
	t_function	v;

	v.i = *j;
	while (s[*j] != sp && s[*j])
		(*j)++;
	v.result = (char *)malloc((*j - v.i + 1) * sizeof(char));
	if (!v.result)
		return (NULL);
	v.k = 0;
	while (v.k < *j - v.i)
	{
		v.result[v.k] = s[v.i + v.k];
		v.k++;
	}
	v.result[v.k] = '\0';
	return (v.result);
}

void	ft_free(char **prr)
{
	int	i;

	i = 0;
	while (prr && prr[i])
	{
		free(prr[i]);
		i++;
	}
	if (prr)
		free(prr);
}

char	**ft_split(char const *s, char c)
{
	t_function	v;

	v.i = 0;
	v.j = -1;
	v.len_word = count_word(s, c);
	if (!s || !v.len_word)
		return (NULL);
	v.prr = (char **)ft_calloc((v.len_word + 1), sizeof(char *));
	if (!v.prr)
		return (NULL);
	while (++v.j < v.len_word)
	{
		while (s[v.i] == c && s[v.i])
			v.i++;
		if (s[v.i])
		{
			v.prr[v.j] = ft_strsdup(s, &v.i, c);
			if (!v.prr[v.j])
			{
				ft_free(v.prr);
				return (NULL);
			}
		}
	}
	return (v.prr);
}
