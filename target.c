/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:36 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/01 13:14:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	spy_content(t_toolbox *box, t_moves *menu)
{
	t_list_int	*spy;
	int		spy_pos;

	spy = box->list_b;
	spy_pos = menu->rb;
	while (spy_pos > 0)
	{
		spy = spy->next;
		spy_pos--;
	}
	return (spy->content);
}

int	find_target(t_toolbox *box, t_moves *menu)
{
	t_list_int	*target;
	int		spy;
	int		scanning;
	int		distance;
	int		i;

	if (box->list_b == NULL)
		return (0);
	target = box->list_a;
	spy = spy_content(box, menu);
	scanning = 0;
	i = 0;
	distance = ft_find_max(box) - spy;
	while (target)
	{
		if (spy > ft_find_max(box) && target->content == ft_find_min(box))
			return (i);
		if (target->content > spy && target->content - spy <= distance)
		{
			distance = target->content - spy;
			scanning = i;
		}
		target = target->next;
        i++;
	}
	return (scanning);
}
