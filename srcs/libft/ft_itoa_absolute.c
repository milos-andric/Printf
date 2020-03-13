/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 15:32:24 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 13:05:27 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoaalloc(long long nbr, int i)
{
	char *ptr;

	if (nbr != 0)
	{
		if (!(ptr = malloc((i + 1) * sizeof(char))))
			return (NULL);
		ptr[i] = '\0';
	}
	else
	{
		if (!(ptr = malloc((2) * sizeof(char))))
			return (NULL);
		ptr[1] = '\0';
		ptr[0] = '0';
	}
	return (ptr);
}

static void		ft_fill(int i, long long nbr,
						int is_neg, char *ptr)
{
	while (i != 0)
	{
		ptr[i - 1] = (nbr % 10 + '0');
		nbr -= nbr % 10;
		nbr /= 10;
		i--;
		if (is_neg && (i == 1))
		{
			i--;
			ptr[i] = '-';
		}
	}
}

char			*ft_itoa_absolute(long long nbr)
{
	int				i;
	long long		cache;
	char			*ptr;
	long long		unbr;

	i = 0;
	cache = nbr;
	unbr = nbr < 0 ? -nbr : nbr;
	while (cache != 0)
	{
		cache /= 10;
		i++;
	}
	if (!(ptr = ft_itoaalloc(unbr, i)))
		return (NULL);
	ft_fill(i, unbr, 0, ptr);
	return (ptr);
}
