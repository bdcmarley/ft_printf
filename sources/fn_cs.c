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

char	*concat(char *r, t_tab *f)
{
	char	*s;
	int		i;

	i = -1;
	if ((*f).zero == 0 && (*f).digit > 0)
		(*f).zero = (*f).digit;
	s = (char*)malloc(sizeof(char) * (*f).zero + 1);
	while (++i < (*f).zero)
		s[i] = r[i];
	return (s);
}

int		fn_c(t_tab *flags, va_list args)
{
	char	*r;
	int		i;

	i = 0;
	r = malloc(sizeof(char) * 1);
	r[0] = va_arg(args, int);
	if (!r[0])
		r[0] = '\0';
	i = ft_control(r, flags);
	free(r);
	return (i);
}

int		fn_s(t_tab *flags, va_list args)
{
	char	*r;
	int		i;

	i = 0;
	r = va_arg(args, char *);
	if (!r && (*flags).zero > ft_strlen("(null)"))
		r = "(null)";
	if (!r && (*flags).dot > 0)
		r = "";
	if ((*flags).dot > 0)
		r = concat(r, flags);
	i = ft_control(r, flags);
	return (i);
}
