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

char	*ft_itoa_hexa(long unsigned int value)
{
	char				*str;
	int					size;
	long unsigned int	tmp;
	char				*tab;

	size = 0;
	tab = "0123456789abcdef";
	tmp = value;
	while (tmp /= 16)
		size++;
	size = size + 3;
	str = (char *)malloc(sizeof(char) * size + 3);
	str[0] = '0';
	str[1] = 'x';
	str[size] = '\0';
	while (size > 2)
	{
		str[size - 1] = tab[ft_abs(value % 16)];
		size--;
		value /= 16;
	}
	return (str);
}

int		fn_percent(t_tab *f, va_list args)
{
	(void)*f;
	(void)args;
	return (ft_putchar('%'));
}

int		fn_p(t_tab *flags, va_list args)
{
	long unsigned int	d;
	int					i;

	i = 0;
	d = va_arg(args, long unsigned int);
	if (!d)
	{
		ft_putstr("(nil)");
		return (ft_strlen("(nil)"));
	}
	i = ft_control(ft_itoa_hexa(d), flags);
	return (i);
}
