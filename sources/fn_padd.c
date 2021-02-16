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

int		putzero(char **r)
{
	int i;

	i = 0;
	if ((*r)[0] == '-')
	{
		ft_putchar('-');
		*r = delchar(*r, 1, 1);
		i++;
	}
	ft_putchar('0');
	return (i);
}

int		fn_padd_r(t_tab *f, char *r)
{
	int		count;

	count = 0;
	if (r[0] == '-' && (*f).dot > 0 && (*f).zero > ft_strlen(r))
		(*f).digit--;
	if ((*f).flag > 1)
	{
		while (((*f).zero - ft_strlen(r)) > 0)
		{
			if ((*f).flag > 1)
				count += putzero(&r);
			(*f).zero--;
			(*f).digit--;
			count++;
		}
	}
	ft_putstr(r);
	while (((*f).digit - ft_strlen(r)) > 0)
	{
		ft_putchar(' ');
		count++;
		(*f).digit--;
	}
	return (count + ft_strlen(r));
}

int		fn_padd_l(t_tab *f, char *r)
{
	int size;
	int count;

	size = ft_strlen(r);
	count = 0;
	if (r[0] == '-' && (*f).dot > 0)
		(*f).zero++;
	if (((*f).zero >= (*f).digit) && (*f).flag > 1)
		(*f).digit = (*f).zero;
	while (((*f).digit - size) > 0)
	{
		if ((((*f).digit - size) <= ((*f).zero - size)) && (*f).flag > 1)
			count += putzero(&r);
		else
			ft_putchar(' ');
		count++;
		(*f).digit--;
	}
	ft_putstr(r);
	return (count + ft_strlen(r));
}
