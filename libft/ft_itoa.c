/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 15:32:24 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 15:15:12 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoaalloc(unsigned int nbr, int i)
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

static void		ft_fill(int i, unsigned int nbr,
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

char			*ft_itoa(int nbr)
{
	int				i;
	int				cache;
	int				is_neg;
	char			*ptr;
	unsigned int	unbr;

	i = 0;
	cache = nbr;
	is_neg = 0;
	unbr = nbr < 0 ? -nbr : nbr;
	if (nbr < 0)
	{
		is_neg = 1;
		nbr *= -1;
	}
	while (cache != 0)
	{
		cache /= 10;
		i++;
	}
	if (!(ptr = ft_itoaalloc(unbr, i + is_neg)))
		return (NULL);
	ft_fill(i + is_neg, unbr, is_neg, ptr);
	return (ptr);
}
