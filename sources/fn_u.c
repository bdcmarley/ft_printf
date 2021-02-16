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

char	*ft_itoa_u(unsigned int n)
{
	unsigned int	tmpn;
	int				len;
	char			*str;

	if (n == 4294967295)
		return ("4294967295");
	tmpn = n;
	len = 2;
	while (tmpn /= 10)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int		fn_u(t_tab *flags, va_list args)
{
	char	*d;
	int		i;

	d = ft_itoa_u(va_arg(args, unsigned int));
	i = 0;
	i = ft_control(d, flags);
	return (i);
}
