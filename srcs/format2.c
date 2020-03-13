/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 14:40:03 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 13:28:20 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/functions.h"

void			ft_format_pct(t_flag *flag)
{
	flag->res = ft_strdup("%");
	ft_add_width(flag);
	ft_add_zero(flag);
	ft_add_minus(flag);
	flag->len += ft_strlen(flag->res);
}

void			ft_format_x(va_list parameter, t_flag *flag)
{
	unsigned long	var;
	char			*temp;

	var = va_arg(parameter, unsigned int);
	if (flag->type == 'x')
		flag->res = ft_itoa_base(var, "0123456789abcdef");
	else
		flag->res = ft_itoa_base(var, "0123456789ABCDEF");
	temp = flag->res;
	if (flag->point && (((flag->precision == -1) && !(var))
				|| (!(flag->precision) && !(var))))
		flag->res = ft_strdup_free("", flag->res);
	ft_add_prec(flag);
	ft_add_zero(flag);
	ft_add_width(flag);
	ft_add_minus(flag);
	flag->len += ft_strlen(flag->res);
}
