/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 14:43:44 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 11:35:10 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/functions.h"

int				ft_zero_find(char *str, t_flag *flag)
{
	if (*str == '0')
	{
		if (flag->minus == 0)
			flag->zero = 1;
		return (1);
	}
	return (0);
}

int				ft_point_find(char *str, t_flag *flag)
{
	if (*str == '.')
	{
		flag->point = 1;
		return (1);
	}
	return (0);
}

int				ft_minus_find(char *str, t_flag *flag)
{
	if (*str == '-')
	{
		flag->minus = 1;
		flag->zero = 0;
		return (1);
	}
	return (0);
}

int				ft_width_find(char *str, t_flag *flag, va_list parameter)
{
	int i;
	int result;

	i = 0;
	if ((i = ft_star_val(str, flag, parameter)))
		return (i);
	if (ft_isdigit(str[i]) && (str[i] != '0'))
	{
		result = ft_atoi(str + i);
		flag->width = result;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int				ft_prec_find(char *str, t_flag *flag, va_list parameter)
{
	int i;
	int result;

	i = 0;
	if (str[i] == '*')
	{
		flag->precision = va_arg(parameter, int);
		return (1);
	}
	if (ft_isdigit(str[i]))
	{
		result = ft_atoi(str + i);
		flag->precision = result;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}
