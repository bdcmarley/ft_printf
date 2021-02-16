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

#include "../include/ft_printf.h"

int		ft_control(char *res, t_tab *f)
{
	int i;

	if (((*f).flag > 1) && ((*f).star == 0)
	&& (ft_strlen(res) == 1) && (res[0] == '0') && ((*f).dot > 0))
		res = "";
	if (((*f).digit > 0 || (*f).zero > 0)
	&& ((*f).digit > ft_strlen(res) || (*f).zero > ft_strlen(res)))
	{
		if ((*f).less == 0)
			if ((*f).flag > 1 && ((*f).zero > 0 || (*f).dot > 0))
				i = fn_padd_l(f, res);
			else
				i = fn_padd_l(f, res);
		else if ((*f).less > 0)
			i = fn_padd_r(f, res);
		return (i);
	}
	ft_putstr(res);
	return (ft_strlen(res));
}

void	recup_flags(char *sen, int *i, t_tab *f, va_list args)
{
	while (sen[++*i])
	{
		if ((sen[*i] != '%' && verif_flags(sen[*i]) == -1 &&
		ft_isdigit(sen[*i]) != 1 && verif_prec(sen[*i]) != 1) || (*f).flag >= 0)
			break ;
		if (sen[*i] == '-')
			(*f).less = 1;
		else if (sen[*i] == '0' &&
		(ft_isdigit(sen[*i + 1]) || sen[*i + 1] == '*'))
			(*f).zero = 1;
		else if (sen[*i] == '.')
			set_dot(f, sen, i);
		else if (sen[*i] == '*')
			set_star(f, args);
		else if (ft_isdigit(sen[*i]))
			set_digit(f, sen, i);
		else if (verif_flags(sen[*i]) != -1)
			(*f).flag = verif_flags(sen[*i]);
		else if (sen[*i] == '%')
			(*f).flag = 8;
	}
	(*i)--;
}

void	handleur(va_list args, char *sentences, int *lensen)
{
	t_tab	flags;
	int		(*fner[8])(t_tab *, va_list);
	int		i;

	i = -1;
	fn_setter(&fner);
	while (sentences[++i])
	{
		if (!sentences[i])
			break ;
		else if (sentences[i] != '%')
			*lensen += ft_putchar(sentences[i]);
		else if (sentences[i] == '%' && sentences[i + 1])
		{
			flags = ini_flags();
			recup_flags(sentences, &i, &flags, args);
			if (flags.flag > -1)
				*lensen += ((fner)[(flags).flag](&flags, args));
			else if (sentences[i])
				*lensen += ft_putchar(sentences[i]);
		}
	}
}

int		ft_printf(char *sentences, ...)
{
	va_list		args;
	char		*sen;
	int			lensen;

	lensen = 0;
	if (!(sen = ft_strdup(sentences)))
		return (0);
	va_start(args, sentences);
	handleur(args, sen, &lensen);
	va_end(args);
	free(sen);
	return (lensen);
}
