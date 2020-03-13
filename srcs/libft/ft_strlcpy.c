/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:13:18 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 12:12:00 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (size != 0)
	{
		while (src[i] && (--size > 0))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		while (src[i])
			i++;
		return (i);
	}
	else
		return (ft_strlen(src));
}
