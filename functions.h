/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   functions.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 17:50:03 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 10:56:41 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> // oupsi doupsy
#include "libft/libft.h"

typedef	struct	flag

{
	int type;
	int width;
	int zero;
	int point;
	int minus;
	int star;
	int s_val;
	char *res;
}				t_flag;

int				ft_isdigit(int c);
void			initialize_flag(t_flag *flag);
int				zero_find(char *str, t_flag *flag);
int				point_find(char *str, t_flag *flag);
int				minus_find(char *str, t_flag *flag);
int				star_find(char *str, t_flag *flag);
int				width_find(char *str, t_flag *flag);
char			*print_variable(char *str, t_flag *flag, va_list parameter);
int				ft_printf(const char *ptr, ...);
void			print_s(t_flag *flag);

#endif
