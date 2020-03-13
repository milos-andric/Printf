/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 17:15:50 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 13:55:00 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr_src = (unsigned const char *)src;
	ptr_dst = (unsigned char *)dst;
	while (n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
		n--;
	}
	return (dst);
}
