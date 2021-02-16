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

char	*ft_itoa_b(unsigned int value, char *tab)
{
	char			*str;
	int				size;
	int				flag;
	unsigned int	tmp;

	flag = 0;
	size = 0;
	tmp = value;
	while (tmp /= 16)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % 16)];
		size--;
		value /= 16;
	}
	return (str);
}

int		fn_x(t_tab *flags, va_list args)
{
	char	*d;
	int		i;

	d = ft_itoa_b(va_arg(args, unsigned int), "0123456789abcdef");
	i = 0;
	i = ft_control(d, flags);
	return (i);
}

int		fn_xx(t_tab *flags, va_list args)
{
	char	*d;
	int		i;

	d = ft_itoa_b(va_arg(args, unsigned int), "0123456789ABCDEF");
	i = 0;
	i = ft_control(d, flags);
	return (i);
}
