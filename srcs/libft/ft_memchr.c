/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:10:15 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 10:57:47 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		car;
	const unsigned char	*s1;

	s1 = (unsigned char *)s;
	car = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	while (n > 0)
	{
		if (*s1 == car)
			return ((void *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
