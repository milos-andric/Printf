/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   functions.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 17:50:03 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 15:53:57 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"

typedef	struct	s_flag
{
	int		type;
	int		width;
	int		zero;
	int		point;
	int		minus;
	int		precision;
	int		is_neg;
	int		is_null;
	int		len;
	char	*res;
}				t_flag;

void			ft_initialize_flag(t_flag *flag);
int				ft_star_val(char *str, t_flag *flag, va_list parameter);
int				ft_zero_find(char *str, t_flag *flag);
int				ft_point_find(char *str, t_flag *flag);
int				ft_minus_find(char *str, t_flag *flag);
int				ft_star_find(char *str, t_flag *flag);
int				ft_width_find(char *str, t_flag *flag, va_list parameter);
int				ft_prec_find(char *str, t_flag *flag, va_list parameter);
int				ft_type_find(char *str, t_flag *flag);
char			*ft_fetch_variable(char *str, t_flag *flag, va_list parameter);
void			ft_format_x(va_list parameter, t_flag *flag);
void			ft_format_u(va_list parameter, t_flag *flag);
void			ft_format_c(va_list parameter, t_flag *flag);
void			ft_format_s(va_list parameter, t_flag *flag);
void			ft_format_d(va_list parameter, t_flag *flag);
void			ft_format_pct(t_flag *flag);
void			ft_format_p(va_list parameter, t_flag *flag);
void			ft_add_width(t_flag *flag);
void			ft_add_prec(t_flag *flag);
void			ft_add_minus(t_flag *flag);
void			ft_add_zero(t_flag *flag);
void			ft_parsing(t_flag *flag, va_list parameter);
char			*ft_print_var(t_flag *flag, va_list param,
		char *str, size_t *w);
int				ft_printf(const char *ptr,
				...) __attribute__((format(printf,1,2)));
#endif
