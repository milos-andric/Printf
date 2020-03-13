/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:54:39 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 11:48:54 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char *ps1;
	const char *ps2;

	ps1 = s1;
	ps2 = s2;
	if (n > 0)
		while (n--)
			if ((unsigned char)*ps1++ != (unsigned char)*ps2++
					|| !(*ps1 || *ps2))
				return ((unsigned char)*--ps1 - (unsigned char)*--ps2);
	return (0);
}
