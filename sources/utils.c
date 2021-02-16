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

int		verif_prec(char s)
{
	if (s != '-' && s != '.' && s != '.' && s != '*')
		return (0);
	return (1);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int		ft_strlen(char const *str)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (str[i])
	{
		y++;
		i++;
	}
	return (y);
}
