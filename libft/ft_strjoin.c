/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:45:44 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 16:12:14 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strcpy(char *dst, const char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ptr = (char *)(malloc((len1 + len2) * sizeof(char) + 1))))
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcpy(&(ptr[len1]), s2);
	return (ptr);
}
