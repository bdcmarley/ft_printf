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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_tab
{
	int less;
	int zero;
	int dot;
	int star;
	int digit;
	int flag;
}				t_tab;

int				ft_printf(char *sentence, ...);

void			fn_setter(int (*(*fner)[8])(t_tab *, va_list));
t_tab			ini_flags(void);
int				recup_nbr(char *sen, int *i);
int				verif_flags(char s);
int				verif_prec(char s);
int				ft_abs(int nb);
char			*ft_strcpy(char *dest, char *src);
char			*delchar(char *x, int a, int b);
void			itoa_isnegative(int *n, int *negative);

void			set_dot(t_tab *f, char *sen, int *i);
void			set_star(t_tab *f, va_list args);
void			set_digit(t_tab *f, char *sen, int *i);

int				ft_control(char *res, t_tab *f);
int				fn_padd_l(t_tab *f, char *r);
int				fn_padd_r(t_tab *f, char *r);

int				fn_c(t_tab *flags, va_list args);
int				fn_s(t_tab *flags, va_list args);
int				fn_p(t_tab *flags, va_list args);
int				fn_d(t_tab *flags, va_list args);
int				fn_u(t_tab *flags, va_list args);
int				fn_x(t_tab *flags, va_list args);
int				fn_xx(t_tab *flags, va_list args);
int				fn_percent(t_tab *f, va_list args);

int				ft_putchar(char c);
void			ft_putc(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);

#endif
