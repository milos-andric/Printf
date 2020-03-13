/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 16:47:52 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 11:50:55 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list **tmp;

	tmp = NULL;
	if (*lst)
	{
		tmp = lst;
		while (*tmp)
		{
			*tmp = (*tmp)->next;
			ft_lstdelone(*tmp, del);
			*tmp = (*tmp)->next;
		}
		*tmp = NULL;
	}
	*lst = NULL;
}
