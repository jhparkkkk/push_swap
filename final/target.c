/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:42:36 by jeepark           #+#    #+#             */
/*   Updated: 2022/03/03 16:48:43 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <time.h>

static int	spy_content(t_toolbox *box, t_moves *menu)
{
	t_list_int	*spy;
	int			spy_pos;
	int			result;

	spy = box->list_b;
	spy_pos = menu->rb;
	result = 0;
	while (spy->next && spy_pos > 0)
	{
		result = spy->content;
		spy = spy->next;
		spy_pos--;
	}
	result = spy->content;
	return (result);
}

static void	find_lim(t_toolbox *box, int *lim)
{
	lim[0] = ft_find_max(box);
	lim[1] = ft_find_min(box);
}

int	find_target(t_toolbox *box, t_moves *menu, int i, int scanning)
{
	t_list_int	*target;
	int			spy;
	int			lim[2];
	int			distance;

	if (box->list_b == NULL)
		return (0);
	target = box->list_a;
	spy = spy_content(box, menu);
	find_lim(box, lim);
	distance = lim[0] - spy;
	while (target)
	{
		if (spy > lim[0] && target->content == lim[1])
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
