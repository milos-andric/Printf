/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 09:10:33 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 11:30:06 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pd;
	const char	*ps;

	pd = (char *)dst;
	ps = (const char *)src;
	if (!dst && !src)
		return (NULL);
	if (pd > ps)
	{
		pd += len;
		ps += len;
		while (len--)
			*--pd = *--ps;
	}
	else
		while (len--)
			*pd++ = *ps++;
	return (dst);
}
