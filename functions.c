/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   functions.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 17:03:46 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 12:30:02 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "functions.h"

void			initialize_flag(t_flag *flag)
{
	flag->type = 0;
	flag->width = 0;
	flag->zero = 0;
	flag->point = 0;
	flag->minus = 0;
	flag->star = 0;
	flag->s_val = 0;
}

int				zero_find(char *str, t_flag *flag)
{
	if(*str == '0')
	{ 
		if (flag->minus == 0)
			flag->zero = 1;
		return (1);
	}
	return(0);
}

int				point_find(char *str, t_flag *flag)
{
	if(*str == '.')
	{
		flag->point = 1;
		return (1);
	}
	return(0);
}

int				minus_find(char *str, t_flag *flag)
{
	if(*str == '-')
	{
		flag->minus = 1;
		flag->zero = 0;
		return (1);
	}
	return(0);
}
/*
int				star_find(char *str, t_flag *flag)
{
	if(*str == '*')
	{
		
	}
	return(i);
}
*/
int		width_find(char *str, t_flag *flag)
{
	int i;
	int result;

	i = 0;
	if(ft_isdigit(str[i]) && (str[i] != '0'))
	{
		result = ft_atoi(str + i);
		flag->width = result;
		while (ft_isdigit(str[i]))
			i++;
	}
	return(i);
}

int		type_find(char *str, t_flag *flag)
{
	char *types = "cspdiuxX%";
	char *car;

	if((car = ft_strchr(types, *str)))
	{
		flag->type = *car;
		return (1);
	}
	return (0);
}

int		star_val(char *str, t_flag *flag, va_list parameter)
{
	if(*str == '*')
	{
		flag->width = va_arg(parameter, int);
		printf("%d", flag->width);
		return (1);
	}
	return (0);
}

char 	*print_variable(char *str, t_flag *flag, va_list parameter)
{
			str++;
			while(*str == '0' || *str == '-')
			{
				str += zero_find(str, flag);
				str += minus_find(str, flag);
			}
			str += width_find(str, flag);
			str += star_val(str, flag, parameter);
			str += point_find(str, flag);
			str += type_find(str, flag);
			return (str);
}

void	print_s(t_flag *flag)
{
		printf("type : %c\nwidth : %d\nzero : %d\npoint : %d\nminus : %d\n",
							flag->type, flag->width, flag->zero, flag->point, flag->minus);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	parameter;
	size_t	written;
//	char	current_c;
	char	*str;
	t_flag	flag;

	str = (char *)ptr;
	initialize_flag(&flag);
	va_start(parameter, ptr);
	written = 0;
	while (*str != 0)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);;
			written++;
			str++;
		}
		else
		{
			str = print_variable(str, &flag, parameter);
			print_s(&flag);
			initialize_flag(&flag);
		}
	}
	va_end(parameter);
	return (written);
}
