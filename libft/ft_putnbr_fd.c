/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 16:49:29 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 12:32:16 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int unb;

	if (n < 0)
	{
		ft_putchar('-', fd);
		unb = n * -1;
	}
	else
		unb = n;
	if (unb <= 9)
	{
		ft_putchar(unb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(unb / 10, fd);
		ft_putnbr_fd(unb % 10, fd);
	}
}
