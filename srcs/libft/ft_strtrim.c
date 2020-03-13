/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 17:00:34 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 13:14:58 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		n;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	n = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (s1[n])
		n++;
	n--;
	while ((n >= 0) && ft_strchr(set, s1[n]))
		n--;
	if (!(res = ft_substr(s1, 0, n + 1)))
		return (NULL);
	return (res);
}
