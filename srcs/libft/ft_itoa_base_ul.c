/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 15:32:24 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 16:32:40 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoaalloc(unsigned long nbr, int i)
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

static void		ft_fill(int i, unsigned long nbr
							, char *ptr, char *base)
{
	while (i != 0)
	{
		ptr[i - 1] = (base[(nbr % ft_strlen(base))]);
		nbr -= nbr % ft_strlen(base);
		nbr /= ft_strlen(base);
		i--;
	}
}

char			*ft_itoa_base_ul(unsigned long nbr, char *base)
{
	int				i;
	unsigned long	cache;
	char			*ptr;

	i = 0;
	cache = nbr;
	while (cache != 0)
	{
		cache /= ft_strlen(base);
		i++;
	}
	if (!(ptr = ft_itoaalloc(nbr, i)))
		return (NULL);
	ft_fill(i, nbr, ptr, base);
	return (ptr);
}
