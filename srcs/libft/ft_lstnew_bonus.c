/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mandric <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 14:31:50 by mandric      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 14:31:55 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (0);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
