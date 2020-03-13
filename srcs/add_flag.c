/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_flag.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/16 14:41:23 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 13:28:12 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/functions.h"

void			ft_add_width(t_flag *flag)
{
	int		number;
	int		len;
	char	*temp;

	temp = flag->res;
	if (flag->width && (!(flag->minus) && !(flag->zero)))
	{
		len = (flag->type != 'c') ? ft_strlen(flag->res) : 1;
		number = (flag->width - len);
		if (number > 0)
		{
			flag->res = ft_join_free1(ft_strnfill(' ', number), flag->res);
			free(temp);
		}
	}
}

void			ft_add_minus(t_flag *flag)
{
	int		number;
	int		len;
	char	*temp;

	temp = flag->res;
	if (flag->minus)
	{
		if (flag->type != 'c')
			len = ft_strlen(flag->res);
		else
			len = 1;
		number = (flag->width - len);
		if (number > 0)
		{
			flag->res = ft_join_free2(flag->res, ft_strnfill(' ', number));
			free(temp);
		}
	}
}

void			ft_add_zero(t_flag *flag)
{
	int	number;
	int	len;

	if (flag->zero)
	{
		if (flag->type != 'c')
			len = ft_strlen(flag->res) + flag->is_neg;
		else
			len = 1;
		number = (flag->width - len);
		if ((number > 0) && (!(flag->point) || (flag->type == '%')))
			flag->res = ft_join_free2(ft_strnfill('0', number), flag->res);
		else if (number > 0 && (flag->point))
			flag->res = ft_join_free2(ft_strnfill(' ', number), flag->res);
	}
}

void			ft_add_prec(t_flag *flag)
{
	int		diff;
	char	*temp;

	temp = flag->res;
	diff = 0;
	if (flag->point && flag->zero)
		flag->zero = 0;
	if (flag->point)
		diff = (flag->precision - ft_strlen(flag->res));
	else if (flag->zero && !(flag->point))
		diff = (flag->width - ft_strlen(flag->res)) - flag->is_neg;
	if (diff > 0)
	{
		flag->res = ft_join_free1(ft_strnfill('0', diff), flag->res);
		free(temp);
	}
}
