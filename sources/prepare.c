/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 08:29:19 by cmarley           #+#    #+#             */
/*   Updated: 2020/02/11 08:29:22 by cmarley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		recup_nbr(char *sen, int *i)
{
	int		x;
	int		y;
	int		z;
	char	*nbr_str;

	y = *i;
	z = 0;
	x = 0;
	while (ft_isdigit(sen[*i]))
	{
		z++;
		(*i)++;
	}
	nbr_str = (char *)malloc(sizeof(char) * (z + 1));
	while (z > 0)
	{
		nbr_str[x] = sen[y];
		z--;
		y++;
		x++;
	}
	nbr_str[x] = '\0';
	(*i)--;
	return (ft_atoi(nbr_str));
}

int		verif_flags(char s)
{
	char	*allf;
	int		i;

	i = 0;
	allf = "cspdiuxX";
	while (allf[i])
	{
		if (allf[i] == s)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*delchar(char *x, int a, int b)
{
	if ((a + b - 1) <= ft_strlen(x))
		ft_strcpy(&x[b - 1], &x[a + b - 1]);
	return (x);
}

void	itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}
