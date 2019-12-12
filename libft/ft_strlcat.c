/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:51:26 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 15:54:28 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < size && dst[i] != '\0')
		i++;
	if (size - i == 0)
		return (i + ft_strlen(src));
	else
		while (src[j] != '\0' && i + j < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
	dst[i + j] = '\0';
	return (i + ft_strlen((char *)src));
}
