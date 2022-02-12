/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:25:07 by jeepark           #+#    #+#             */
/*   Updated: 2022/02/10 16:04:07 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*box;

	if (!lst)
		return ;
	while (*lst)
	{
		box = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = box;
	}
	*lst = NULL;
}

void	ft_lstclear_int(t_list_int **lst, void (*del)(int))
{
	t_list_int	*box;

	if (!lst)
		return ;
	while (*lst)
	{
		box = (*lst)->next;
		ft_lstdelone_int(*lst, del);
		*lst = box;
	}
	*lst = NULL;
}

