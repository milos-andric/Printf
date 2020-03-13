/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 14:38:45 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 11:32:35 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/functions.h"

void			ft_format_d(va_list parameter, t_flag *flag)
{
	int	var;

	var = va_arg(parameter, int);
	if (var < 0)
		flag->is_neg = 1;
	flag->res = ft_itoa_absolute(var);
	if (flag->point && (((flag->precision == -1) && !(var))
				|| (!(flag->precision) && !(var))))
		flag->res = ft_strdup_free("", flag->res);
	ft_add_prec(flag);
	ft_add_zero(flag);
	if (flag->is_neg != 0)
		flag->res = ft_join_free2("-", flag->res);
	ft_add_width(flag);
	ft_add_minus(flag);
	flag->len += ft_strlen(flag->res);
}

void			ft_format_s(va_list parameter, t_flag *flag)
{
	char *temp;

	if (flag->point && (flag->precision == -1))
		flag->res = ft_strdup("");
	else if (!(flag->res = ft_strdup(va_arg(parameter, char*))))
		flag->res = ft_strdup("(null)");
	temp = flag->res;
	if (flag->point && (flag->precision >= 0))
	{
		flag->res = ft_substr(flag->res, 0, flag->precision);
		free(temp);
	}
	ft_add_width(flag);
	ft_add_minus(flag);
	flag->len += ft_strlen(flag->res);
}

void			ft_format_c(va_list parameter, t_flag *flag)
{
	char var;

	var = va_arg(parameter, int);
	flag->res = ft_calloc(2, sizeof(char));
	flag->res[0] = var;
	if ((var == 0) && (flag->minus))
	{
		ft_putchar_fd(var, 1);
		flag->len++;
	}
	else if ((var == 0) && !(flag->minus))
		flag->is_null = 1;
	ft_add_width(flag);
	ft_add_minus(flag);
	flag->len += ft_strlen(flag->res);
}

void			ft_format_u(va_list parameter, t_flag *flag)
{
	unsigned int	var;

	var = va_arg(parameter, unsigned int);
	flag->res = ft_itoa_absolute(var);
	if (flag->point && (((flag->precision == -1) && !(var))
				|| (!(flag->precision) && !(var))))
		flag->res = ft_strdup_free("", flag->res);
	ft_add_prec(flag);
	ft_add_zero(flag);
	ft_add_width(flag);
	ft_add_minus(flag);
	flag->len += ft_strlen(flag->res);
}

void			ft_format_p(va_list parameter, t_flag *flag)
{
	void *p;

	p = va_arg(parameter, void *);
	if (flag->point && (((flag->precision == -1) && !(p))
				|| (!(flag->precision) && !(p))))
		p = ft_strdup_free("", p);
	else
		p = ft_itoa_base_ul((unsigned long)p, "0123456789abcdef");
	flag->res = ft_join_free2("0x", p);
	ft_add_width(flag);
	ft_add_minus(flag);
	flag->len += ft_strlen(flag->res);
}
