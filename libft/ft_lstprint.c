/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:34:21 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/02 12:16:48 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list_int *list)
{
	t_list_int	*tmp;

	tmp = list;
	while (tmp->next != NULL)
	{
		ft_putstr_fd(tmp->content, 1);
		tmp = tmp->next;
	}
	ft_putstr_fd(tmp->content, 1);
}
