/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnfill.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 12:16:01 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 12:25:25 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnfill(char character, int length)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char *)malloc((sizeof(char)) * (length + 1))))
		return (NULL);
	if (length > 0)
	{
		while (i < length)
		{
			res[i] = character;
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	else
		return (NULL);
}
