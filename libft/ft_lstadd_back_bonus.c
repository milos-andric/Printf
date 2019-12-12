/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back_bonus.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 13:44:28 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 16:44:25 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *temp;

	if (!*alst)
		*alst = new;
	else
	{
		temp = ft_lstlast(*alst);
		temp->next = new;
	}
}
