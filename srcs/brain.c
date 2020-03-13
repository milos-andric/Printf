/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brain.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 14:50:03 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 12:40:04 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/functions.h"

void			ft_initialize_flag(t_flag *flag)
{
	flag->type = 0;
	flag->width = 0;
	flag->zero = 0;
	flag->point = 0;
	flag->minus = 0;
	flag->precision = -1;
	flag->is_neg = 0;
	flag->is_null = 0;
	flag->len = 0;
}

char			*ft_fetch_variable(char *str, t_flag *flag, va_list parameter)
{
	str++;
	while (*str == '0' || *str == '-' || *str == '+')
	{
		str += ft_zero_find(str, flag);
		str += ft_minus_find(str, flag);
		str += (*str == '+');
	}
	str += ft_width_find(str, flag, parameter);
	str += ft_point_find(str, flag);
	str += ft_prec_find(str, flag, parameter);
	str += ft_type_find(str, flag);
	ft_parsing(flag, parameter);
	return (str);
}

void			ft_parsing(t_flag *flag, va_list parameter)
{
	if (flag->type == 'c')
		ft_format_c(parameter, flag);
	else if (flag->type == 's')
		ft_format_s(parameter, flag);
	else if (flag->type == 'p')
		ft_format_p(parameter, flag);
	else if ((flag->type == 'd') || (flag->type == 'i'))
		ft_format_d(parameter, flag);
	else if (flag->type == 'u')
		ft_format_u(parameter, flag);
	else if (flag->type == 'x')
		ft_format_x(parameter, flag);
	else if (flag->type == 'X')
		ft_format_x(parameter, flag);
	else if (flag->type == '%')
		ft_format_pct(flag);
	else
		flag->res = ft_strdup("");
}

char			*ft_print_var(t_flag *flag, va_list param, char *str, size_t *w)
{
	str = ft_fetch_variable(str, flag, param);
	ft_putstr_fd(flag->res, 1);
	if (flag->is_null)
		ft_putchar_fd(0, 1);
	*w += flag->len + flag->is_null;
	free(flag->res);
	ft_initialize_flag(flag);
	return (str);
}
