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

t_tab	ini_flags(void)
{
	t_tab	flags;

	flags.less = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.star = 0;
	flags.digit = 0;
	flags.flag = -1;
	return (flags);
}

void	fn_setter(int (*(*fner)[8])(t_tab *, va_list))
{
	(*fner)[0] = &fn_c;
	(*fner)[1] = &fn_s;
	(*fner)[2] = &fn_p;
	(*fner)[3] = &fn_d;
	(*fner)[4] = &fn_d;
	(*fner)[5] = &fn_u;
	(*fner)[6] = &fn_x;
	(*fner)[7] = &fn_xx;
	(*fner)[8] = &fn_percent;
}

void	set_dot(t_tab *f, char *sen, int *i)
{
	if ((*f).zero > 0 && ft_isdigit(sen[*i + 1]))
		(*f).digit = (*f).zero;
	(*f).dot = 1;
}

void	set_star(t_tab *f, va_list args)
{
	(*f).star = 1;
	if ((*f).zero > 0 || (*f).dot > 0)
		(*f).zero = va_arg(args, int);
	else
		(*f).digit = va_arg(args, int);
}

void	set_digit(t_tab *f, char *sen, int *i)
{
	if ((*f).zero > 0 || (*f).dot > 0)
		(*f).zero = recup_nbr(sen, i);
	else
		(*f).digit = recup_nbr(sen, i);
}
