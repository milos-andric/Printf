/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   functions.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 17:03:46 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 11:29:57 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/functions.h"

int		ft_printf(const char *ptr, ...)
{
	va_list	parameter;
	size_t	written;
	char	*str;
	t_flag	flag;

	str = (char *)ptr;
	ft_initialize_flag(&flag);
	va_start(parameter, ptr);
	written = 0;
	while (*str != 0)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			written++;
			str++;
		}
		else
			str = ft_print_var(&flag, parameter, str, &written);
	}
	va_end(parameter);
	return (written);
}
