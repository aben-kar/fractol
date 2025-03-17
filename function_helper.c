/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 04:13:38 by acben-ka          #+#    #+#             */
/*   Updated: 2025/03/17 09:52:58 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	rs;
	int	sign;

	i = 0;
	rs = 0;
	sign = 1;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		rs = rs * 10 + (s[i] - 48);
		i++;
	}
	return (rs * sign);
}

int	ft_isdigit(int c)
{
	while (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void	check_for_alphabetic(char *s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		if (ft_isalpha(s[j]))
		{
			print_error();
		}
		j++;
	}
}
