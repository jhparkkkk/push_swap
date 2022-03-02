/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:52:50 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/02 12:03:15 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*box;

	i = 0;
	box = lst;
	while (box)
	{
		box = box->next;
		i++;
	}
	return (i);
}

int	ft_lstsize(t_list_int *lst)
{
	int		i;
	t_list	*box;

	i = 0;
	box = lst;
	while (box)
	{
		box = box->next;
		i++;
	}
	return (i);
}
