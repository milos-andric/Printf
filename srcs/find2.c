/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 14:48:10 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 11:28:42 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/functions.h"

int				ft_type_find(char *str, t_flag *flag)
{
	char *types;
	char *car;

	types = ft_strdup("cspdiuxX%");
	if ((car = ft_strchr(types, *str)))
	{
		flag->type = *car;
		free(types);
		return (1);
	}
	free(types);
	return (0);
}

int				ft_star_val(char *str, t_flag *flag, va_list parameter)
{
	int var;

	if (*str == '*')
	{
		var = va_arg(parameter, int);
		if (var < 0)
		{
			flag->minus = 1;
			flag->zero = 0;
			var = -var;
		}
		flag->width = var;
		return (1);
	}
	return (0);
}
