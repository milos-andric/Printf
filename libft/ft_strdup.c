/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 13:29:25 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 19:01:39 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strcpy_custom(char *dst, const char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
}

char			*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	len = (ft_strlen(s1));
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcpy_custom(ptr, s1);
	return (ptr);
}
